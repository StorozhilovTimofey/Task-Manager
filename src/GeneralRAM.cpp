#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "GeneralRAM.h"

void GeneralRAM::ChangetoValidOutput(std::string& line)
{
    std::string word;
    float number;
    std::istringstream iss(line);
    iss >> word >> number;
    number /= 1048576;
    if (word == "MemTotal:") { std::cout << "Total Memory: " << number << " Gb" << std::endl; }
    else if (word == "MemFree:") { std::cout << "Free Memory: " << number << " Gb" << std::endl; }
    else { std::cout << word << " " << number * 1024 << " Mb" << std::endl; }
}

void GeneralRAM::GeneralRamParametres()
{
    std::cout << "General Parametres: " << std::endl;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
    {   
        for (const std::string& start : Needs)
        {
            if (GetFirstWord(line).compare(0, start.length(), start) == 0)
            {
                ChangetoValidOutput(line);
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