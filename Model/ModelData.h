#pragma once

#include "IModelData.h"

class ModelData : public IModelData
{
public:
    std::vector<std::string> getRamGeneral() override; // Функция, считывающая в вектор данные об оперативе
    std::vector<std::string> getRamSpecific() override;
    void CreateFile() override;
    void DeleteFile() override;
    
    double getCpuTemperature() override;
    double getCurrentCpuFrequency() override;
    std::vector<double> getCpuParametres() override;
};
