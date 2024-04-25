    #include "Mram.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::string ModelRAM::FirstWord(const std::string& line)
{
    std::string word; // Результат
    for (char ch : line) // Получение слова без пробелов
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

std::vector<std::string> ModelRAM::GRAMparams(const std::string& path, const std::vector<std::string>& needs)
{
    std::ifstream file(path); // Файл с нужными данными
    std::string line; // Строка из файла
    std::vector<std::string> result; // Вектор, в который будет записан результат
    while (std::getline(file, line)) // Перебор всех строк файла
    {
        for (const std::string& start : needs) // Перебор вектора needs для сравениня параметров
        {
            if (FirstWord(line).compare(0, start.length(), start) == 0)
            {
                std::string validLine = PrettyData(line); // Перевод строки в более красивый вид
                result.push_back(validLine);
                break;
            }
        }
    }
    file.close();
    return result;
}

std::string ModelRAM::PrettyData(std::string& line)
{
    std::string result;
    std::string word; // Слово в строке
    float number; // Число в строке
    std::istringstream iss(line); // Разбиение на число и слово
    iss >> word >> number;
    number /= 1048576; // Перевод в гигабайты
    if (word == "MemTotal:")
    {

        result = "Total Memory: " + ConvertFloatToString(number) + " GB";
        return result;
    }
    else if (word == "MemFree:")
    {
        result = "Free Memory: " + ConvertFloatToString(number) + " GB";
        return result;
    }
    else
    {
        number *= 1024; // Перевод в мегабайты
        result = word + " " + ConvertFloatToString(number) + " MB";
        return result;
    }
}

std::string ModelRAM::ConvertFloatToString(float& number)
{

    std::ostringstream oss;
    oss << number;
    return oss.str();
}

std::string ModelRAM::exec(const char* cmd)
{
    std::array<char, 128> buffer; // Массив для чтения вывода выполненной команды
    std::string result; // Результат выполнения команды
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose); // Умный указатель для управления процессом, выполняющим команду
    if (!pipe) // Проверка открытия процесса
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) // Чтение строк из процесса в буфер
    {
        result += buffer.data();
    }
    return result;
}

void ModelRAM::RemoveLeadingSpaces(std::string& line)
{
    size_t pos = 0;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (!std::isspace(line.at(i))) // Проверка на пробел
        {
            pos = i; // Если не пробел, то позиция обновляется значением индекса
            break;
        }
    }
    line = line.substr(pos); // Обрезание начала строки до pos
}

std::string ModelRAM::GetFirstWord(const std::string& line)
{
    std::string word; // Результат
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

void ModelRAM::CreateFile()
{
    std::string memoryInfo = exec("sudo dmidecode --type memory"); // Запуск процесса
    std::ofstream file(filePath); // Файл, куда записывается результат процесса
    file << "Memory Information:\n" << memoryInfo << std::endl; // Запись
    file.close(); // Освобождение памяти
}

void ModelRAM::DeleteFile()
{
    std::string command = "rm -f " + filePath; // Команда удаления созданного файла
    int result = std::system(command.c_str()); // Ввод команды
}

std::vector<std::string> ModelRAM::AllData()
{
    std::vector<std::string> result; // Результат
    result.push_back("\n#" + std::to_string(counter) + ":"); // Обозначение первой плашки оперативы
    std::ifstream file(filePath); // Файл, откуда считываются данные, созданный нами
    if (file.is_open()) // Если файл открылся
    {
        std::string line; // Текущая, рассматриваемая строка
        std::string prevLine; // Предыдущая строка; нужна, чтобы отслеживать изменение счетчика плашек
        while (std::getline(file, line)) // Считываение файла
        {
            RemoveLeadingSpaces(line); // Удаление первых пробелов в строке
            bool isIgnored = false; // Создание флага, который отслеживает не попался ли пустой слот для оперативы
            for (const std::string& elem : ignoredStarts) // Проверка на пустоту
            {
                if(line.compare(0, elem.length(), elem) == 0)
                {
                    isIgnored = true;
                    break;
                }
            }
            if (isIgnored) { continue; } // Пропуск куска информации, если слот пустой
            for (const std::string& elem : lineStarts) // Заполнение вектора нужными данными
            {
                if (line.compare(0, elem.length(), elem) == 0)
                {
                    if (GetFirstWord(prevLine) == "Serial") // Смена счетчика
                    {
                        counter++;
                        result.push_back("\n#" + std::to_string(counter) + ":");
                    }
                    prevLine = line;
                    result.push_back(line);
                    break;
                }
            }
        }
        file.close();
    }
    else { std::cerr << "Unable to open file: " << filePath << std::endl; } // Если файл не создался

    return result;
}
