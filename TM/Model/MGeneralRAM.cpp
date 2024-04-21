#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "MGeneralRAM.h"

std::string ModelGRAM::FirstWord(const std::string& line)
{
    std::string word; // Результат
    for (char ch : line) // Получение слова без пробелов
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

std::vector<std::string> ModelGRAM::GRAMparams(const std::string& path, const std::vector<std::string>& needs)
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

std::string ModelGRAM::PrettyData(std::string& line)
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

std::string ModelGRAM::ConvertFloatToString(float& number)
{

    std::ostringstream oss;
    oss << number;
    return oss.str();
}
