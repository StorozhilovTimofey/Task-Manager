#include <vector>
#include <iostream>

#include "CPUView.h"

void ViewCPU::ShowCpuParametres(std::vector<double> input)
{
    std::cout << "Frequency: " << input[0] << " Hz" << std::endl;
    std::cout << "Temperature: " << input[1] << " C^" << std::endl;
}