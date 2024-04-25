#include "CPUView.h"

#include <iostream>
#include <vector>

#include "CPUView.h"


void ViewCPU::ShowCpuParametres(std::vector<double> input)
{
    std::cout << "Current CPU frequency: " << input[0] << " MHz" << std::endl;

    std::cout << "Current CPU temperature: "  << input[1] << " °C" << std::endl;
}
