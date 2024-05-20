#pragma once

#include "IViewData.h"

class ViewData : public IViewData
{
public:
    void ShowRAMParams(const std::vector<std::string>& RAMParams,
                       const std::vector<std::string>& params) override;
    void ShowCpuParametres(std::vector<double> input) override; // Тут она должна вывести в консоль параметры
    ~ViewData();
};