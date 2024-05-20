#pragma once

#include <memory>
#include <string>
#include <vector>

class IViewData
{
public:
    virtual void ShowRamParametres(const std::vector<std::string>& RAMParams,
                               const std::vector<std::string>& params) = 0;
    virtual void ShowCpuParametres(std::vector<double> input) = 0;
    
    virtual ~IViewData() = default;
    using Ptr = std::shared_ptr<IViewData>;
};
