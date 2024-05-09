#pragma once

#include "ICPUModel.h"


class ModelCPU : public IModelCPU
{
public:
    double getCpuTemperature() override;
    double getCurrentCpuFrequency() override;
    std::vector<double> getParametres() override;
private:
    static std::string readFromFile(const std::string &filePath);
};
