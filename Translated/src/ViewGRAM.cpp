#include <string>
#include <vector>
#include <iostream>

#include "ViewGRAM.h"

void ViewGRAM::ShowGeneralParams(const std::vector<std::string>& params)
{
    for (const std::string& line : params)
    {
        std::cout << line << std::endl;
    }
}