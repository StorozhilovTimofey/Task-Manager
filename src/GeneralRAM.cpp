#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "GeneralRAM.h"

void GeneralRAM::ChangetoValidOutput(std::string& line)
{
    std::string word; // Рассматриваемое первое слово в строке
    float number; // Число, получаемое во входной строке
    std::istringstream iss(line); // Разделение числа и слова по переменным
    iss >> word >> number;
    number /= 1048576; // Перевод в Gb
    // Замена первых слов в строке, просто для более приятного вывода
    if (word == "MemTotal:") { std::cout << "Total Memory: " << number << " Gb" << std::endl; }
    else if (word == "MemFree:") { std::cout << "Free Memory: " << number << " Gb" << std::endl; }
    else { std::cout << word << " " << number * 1024 << " Mb" << std::endl; }
}

void GeneralRAM::GeneralRamParametres()
{
    std::cout << "General Parametres: " << std::endl;
    std::ifstream file(path);
    std::string line;   
    while (std::getline(file, line)) // Чтение файла
    {   
        for (const std::string& start : Needs) // Цикл в котором сравниваются слова в строки с элементами вектора
        {
            if (GetFirstWord(line).compare(0, start.length(), start) == 0)
            {
                ChangetoValidOutput(line); // Смена вывода и сам вывод
                break;
            }
        }
    }
    file.close();
}

void GeneralRAM::PrettyOutput()
{
    std::cout << std::endl; std::cout << std::endl;
}