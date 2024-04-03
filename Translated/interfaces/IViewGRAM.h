#pragma once

#include <vector>
#include <memory>
#include <string>

class IViewGRAM
{
public:
    virtual void ShowGeneralParams(const std::vector<std::string>& params) = 0;
    using IVptr = std::shared_ptr<IViewGRAM>;
};