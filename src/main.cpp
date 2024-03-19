#include <iostream>
#include <string>
#include <thread>

#include "RAM.h"
#include "GeneralRAM.h"
#include "CP_lib.h"

int main()
{
    int64_t i = 0;
    while (i < 50)
    {
        // Получаем текущие частоты процессора и выводим их
        CPU a;
        if (a.getCurrentCpuFrequency() != "Error" && a.getCurrentCpuFrequency() != "Unknown")
        {
            std::cout << "Current CPU frequency: " << a.getCurrentCpuFrequency() << " MHz" << std::endl;
        } else
        {
            std::cerr << "Failed to get current CPU frequency" << std::endl;
        }


        // Получаем температуру процессора и выводим её
        if (a.getCpuTemperature() >= 0.0)
        {
            std::cout << "CPU temperature: " << a.getCpuTemperature() << " C" << std::endl;
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ++i;
    }

    RAM example;
    example.createFile();
    example.printMatchingLines();
    example.deleteFile();

    GeneralRAM sameexample;
    sameexample.PrettyOutput();
    sameexample.GeneralRamParametres();

    return 0;
}