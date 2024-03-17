#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>
#include <iomanip>

#include "CP_lib.h"

std::vector<CPUData> CPU::CPUdata_info()
{
    std::ifstream file("/proc/stat");
    std::string line;
    std::vector<CPUData> result;

    getline(file, line);
    while (line.substr(0, 3) == "cpu")
    {
        CPUData element;
        std::istringstream ss(line);
        ss >> element.cpu >> element.user >> element.nice >> element.system >> element.idle >> element.iowait
           >> element.irq >> element.softirq >> element.steal >> element.guest >> element.guest_nice;
        result.push_back(element);
        getline(file, line);
    }
    return result;
}

long double CPU::CPUload(CPUData& start, CPUData& end)
{
    long double total_load = static_cast<long double>((end.user - start.user) + (end.nice - start.nice) +
                             (end.system - start.system) + (end.idle - start.idle) +
                             (end.iowait - start.iowait) + (end.irq - start.irq) +
                             (end.softirq - start.softirq) + (end.steal - start.steal) +
                             (end.guest - start.guest) + (end.guest_nice - start.guest_nice));

    long double real_load =  static_cast<long double>((end.idle - start.idle) + (end.iowait - start.iowait));
    
    return 100 - (real_load/total_load)*100.0;
}

void CPU::ShowCPULoad1(int64_t millisecond)
{
    if (millisecond < 1)
    {
        return;
    }
    auto start = CPUdata_info();
    std::this_thread::sleep_for(std::chrono::milliseconds (millisecond));
    auto end = CPUdata_info();

    for (size_t i = 0; i < start.size() ; ++i)
    {
        auto pr = CPUload(start[i], end[i]);
        std::cout << (start[i]).cpu << ": " << std::setw(7) << std::fixed << std::setprecision(3) << pr << "%   ";
    }
    std::cout << std::endl;
}

void CPU::ShowCPULoad2(int64_t millisecond, int64_t second_of_show)
{
    if (millisecond < 1 || second_of_show < 1)
    {
        return;
    }
    if (millisecond > 100)
    {
        for (int32_t i = 0; i < ((1000.0 / (float)millisecond) * second_of_show) + 1; ++i)
        {
            ShowCPULoad1(millisecond);
        }
    }
    // Возникает вопрос что делать, если user хочет посмотреть загруженность раз в 10 миллисекунд,
    // это слишком часто, ниже решение этого вопроса
    else
    { 
        int32_t d = 100/millisecond + 1;
        long double k = (long double)second_of_show*1000.0/(long double)millisecond;
        std::vector<std::vector<CPUData>> MyVector(d);
        for (int32_t i = 0; i < d; ++i)
        {
            auto start = CPUdata_info();
            std::this_thread::sleep_for(std::chrono::milliseconds (millisecond));
            MyVector[i] = start;
        }
        for (int32_t i = 0; i < k - d; ++i)
        {
            for (size_t j = 0; j < MyVector[0].size() ; ++j)
            {
                auto to_print = CPUload(MyVector[i%d][j], MyVector[(i+d-1)%d][j]);
                std::cout << (MyVector[i%d][j]).cpu << ": " << std::setw(7) << std::fixed << std::setprecision(3) << to_print << "%   ";
            }
            std::this_thread::sleep_for(std::chrono::milliseconds (millisecond));
            auto start = CPUdata_info();
            MyVector[i%d] = start;

            std::cout << std::endl;
        }
    }
}


void CPU::ShowCPUOperation(int64_t millisecond_of_show)
{
    auto start = CPUdata_info();
    std::this_thread::sleep_for(std::chrono::milliseconds (millisecond_of_show));
    auto end = CPUdata_info();

    for (size_t i = 0; i < start.size() ; ++i)
    {
        size_t total_start = start[i].user + start[i].nice + start[i].system + start[i].irq
                             + start[i].softirq + start[i].guest_nice + start[i].steal + start[i].guest;
        size_t total_end = end[i].user + end[i].nice + end[i].system + end[i].irq
                           + end[i].softirq + end[i].guest_nice + end[i].steal + end[i].guest;
        std::cout << (start[i]).cpu << ": " << total_end - total_start << "    ";
    }
    std::cout << std::endl;
}

// Функция для чтения значения из файла и возврата его в виде строки
std::string readFromFile(const std::string &filePath)
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


// Функция для чтения текущей частоты процессора из файла /proc/cpuinfo
std::string CPU::getCurrentCpuFrequency()
{
    std::ifstream cpuinfoFile("/proc/cpuinfo");
    if (!cpuinfoFile.is_open())
    {
        std::cerr << "Failed to open /proc/cpuinfo" << std::endl;
        return "Error";
    }

    std::string line;
    while (std::getline(cpuinfoFile, line))
    {
        if (line.find("cpu MHz") != std::string::npos)
        {
            // Найдена строка с текущей частотой процессора
            size_t colonPos = line.find(":");
            if (colonPos != std::string::npos)
            {
                std::string frequencyStr = line.substr(colonPos + 1);
                // Удаляем лишние пробелы в начале строки
                size_t firstDigitPos = frequencyStr.find_first_of("0123456789");
                if (firstDigitPos != std::string::npos)
                {
                    return frequencyStr.substr(firstDigitPos);
                }
            }
        }
    }

    return "Unknown";
}


double CPU::getCpuTemperature()
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

