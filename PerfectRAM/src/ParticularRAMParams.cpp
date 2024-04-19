#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ParticularRAMParams.h"

std::string ModelPRAM::exec(const char* cmd)
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

void ModelPRAM::RemoveLeadingSpaces(std::string& line)
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

std::string ModelPRAM::GetFirstWord(const std::string& line)
{
    std::string word; // Результат
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

void ModelPRAM::CreateFile()
{
    std::string memoryInfo = exec("sudo dmidecode --type memory"); // Запуск процесса
    std::ofstream file(filePath); // Файл, куда записывается результат процесса
    file << "Memory Information:\n" << memoryInfo << std::endl; // Запись
    file.close(); // Освобождение памяти
}

void ModelPRAM::DeleteFile()
{
    std::string command = "rm -f " + filePath; // Команда удаления созданного файла
    int result = std::system(command.c_str()); // Ввод команды
}

std::vector<std::string> ModelPRAM::AllData()
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

void ViewPRAM::ShowRAMParams(const std::vector<std::string>& RAMParams)
{   
    for (const std::string& elem : RAMParams)
    {
        std::cout << elem << std::endl;
    }
}

ControllerPRAM::ControllerPRAM(IViewPRAM::IVptr view, IModelPRAM::IMptr model) :
    view(view), model(model)
{
}

void ControllerPRAM::Launch()
{
    model->CreateFile(); // Создание файла
    std::vector<std::string> result = model->AllData(); // Запсь данных из модели в вектор
    view->ShowRAMParams(result); // Вывод вектора
    model->DeleteFile(); // Удаление файла
}