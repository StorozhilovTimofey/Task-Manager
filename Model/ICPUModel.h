#pragma once

#include <memory>
#include <vector>


class IModelCPU
{
public:
    virtual double getCpuTemperature() = 0;
    virtual double getCurrentCpuFrequency() = 0;
    virtual std::vector<double> getParametres() = 0;

    using IMptr = std::shared_ptr<IModelCPU>;
};
