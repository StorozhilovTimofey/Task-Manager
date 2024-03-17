#pragma once

#include <string>
#include <vector>

#include "RAM.h"

class GeneralRAM : public RAM
{
public:
    void ChangetoValidOutput(std::string& line);
    void GeneralRamParametres();
    void PrettyOutput();
private:
    const std::string path = "/proc/meminfo";
    std::vector<std::string> Needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    };
};