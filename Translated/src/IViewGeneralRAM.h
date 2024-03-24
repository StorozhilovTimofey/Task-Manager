#pragma once

#include <vector>
#include <string>

class IViewGeneralRAM
{
public:
    virtual void ShowGeneralRAMParams(const std::vector<std::string> params) = 0;
};