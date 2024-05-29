#include <iostream>

#include "ViewData.h"


void ViewData::ShowRamParametres(const std::vector<std::string> &RAMParams,
                            const std::vector<std::string>& params)
{
    for (const auto &param : RAMParams)
    {
        std::cout << param << std::endl;
    }
    for (const auto &param : params)
    {
        std::cout << param << std::endl;
    }
    
    std::cout << std::endl;
}


void ViewData::ShowCpuParametres(std::vector<double> input)
{
    std::cout << "Frequency: " << input[0] << " Hz" << std::endl;
    std::cout << "Temperature: " << input[1] << " C^" << std::endl;
}