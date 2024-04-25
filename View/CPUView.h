#pragma once

#include <vector>

#include "ICPUView.h"


class ViewCPU : public IViewCPU
{
public:
    void ShowCpuParametres(std::vector<double> input) override; // Тут она должна вывести в консоль параметры
};
