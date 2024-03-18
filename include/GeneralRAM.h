#pragma once

#include <string>
#include <vector>

#include "RAM.h"

// Класс, который будет выводить общие данные по оперативной памяти
class GeneralRAM : public RAM 
{
public:
    void ChangetoValidOutput(std::string& line); // Меняет и выделяет только нужные параметры
    void GeneralRamParametres(); // Считывает параметры из файла /proc/meminfo
    void PrettyOutput(); // Просто добавляет пару переносов строки
private:
    const std::string path = "/proc/meminfo";
    std::vector<std::string> Needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    }; // Вектор, который нужен для опеределения только нужных параметров
};