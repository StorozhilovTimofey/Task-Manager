#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "CPUModel.h"


// Функция для чтения текущей частоты процессора из файла /proc/cpuinfo
double ModelCPU::getCurrentCpuFrequency()
{
    std::ifstream cpuinfoFile("/proc/cpuinfo");
    if (!cpuinfoFile.is_open())
    {
        std::cerr << "Failed to open /proc/cpuinfo" << std::endl;
        return -1; // ~ "Error"
    }

    std::string line;
    while (std::getline(cpuinfoFile, line))
    {
        if (line.find("cpu MHz") != std::string::npos)
        {
            // Найдена строка с текущей частотой процессора
            size_t colonPos = line.find(':');
            if (colonPos != std::string::npos)
            {
                std::string frequencyStr = line.substr(colonPos + 1);
                // Удаляем лишние пробелы в начале строки
                size_t firstDigitPos = frequencyStr.find_first_of("0123456789");
                if (firstDigitPos != std::string::npos)
                {

                    return std::stod(frequencyStr.substr(firstDigitPos));
                }
            }
        }
    }

    return 0; // ~ "Unknown"
}


// Функция для чтения содержимого всего файла и возврата его в виде одной строки
// Вернет пустую строку в случае ошибки
std::string ModelCPU::readFromFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


double ModelCPU::getCpuTemperature()
{
    std::string tempStr = readFromFile("/sys/class/thermal/thermal_zone0/temp");
    if (tempStr.empty())
    {
        std::cerr << "Failed to read CPU temperature" << std::endl;
        return -1.0;
    }

    // Преобразуем строку в число (температуру) и переводим её в градусы Цельсия
    double temp;
    std::stringstream(tempStr) >> temp;
    return temp / 1000.0;
}


std::vector<double> ModelCPU::getParametres()
{
    std::vector<double> result = {getCurrentCpuFrequency(), getCpuTemperature()};
    return result;
}
