#pragma once

#include <memory>
#include <string>
#include <vector>

class IViewGRAM
{
public:
    virtual void ShowGeneralParams(const std::vector<std::string>& params) = 0;

    using IGRAMVptr = std::shared_ptr<IViewGRAM>;
};
