#include <string>
#include <vector>
#include <iostream>

#include "ViewGeneralRAM.h"

void ViewGeneralRAM::ShowGeneralRAMParams(const std::vector<std::string> params)
{
    for (const std::string& start : params)
    {
        std::cout << start << std::endl;
    }
}