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

void ShowCPULoad2(int64_t millisecond, int64_t second_of_show)
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
    else{ //Возникает вопрос что делать, если user хочет посмотреть загруженность раз в 10 миллисекунд, это слишком часто, ниже решение этого вопроса
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