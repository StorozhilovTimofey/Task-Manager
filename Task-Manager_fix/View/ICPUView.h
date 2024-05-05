#pragma once

#include <memory>
#include <vector>


class IViewCPU
{
public:
    virtual void ShowCpuParametres(std::vector<double> input) = 0;

    virtual ~IViewCPU() = default;

    using IVptr = std::shared_ptr<IViewCPU>;
};
