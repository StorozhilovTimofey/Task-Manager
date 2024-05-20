#pragma once

#include <memory>
#include <string>
#include <vector>

class IViewRAM
{
public:
    virtual void ShowRAMParams(const std::vector<std::string>& RAMParams,
                               const std::vector<std::string>& params) = 0;
    virtual void ShowCpuParametres(std::vector<double> input) = 0;
    virtual ~IViewRAM() = default;
    using IVptr = std::shared_ptr<IViewRAM>;
};
