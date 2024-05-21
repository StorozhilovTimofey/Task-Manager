#pragma once

#include "IViewData.h"


class ViewData : public IViewData
{
public:
    void ShowRamParametres(const std::vector<std::string>& RAMParams,
                           const std::vector<std::string>& params) override;

    void ShowCpuParametres(std::vector<double> input) override;
};