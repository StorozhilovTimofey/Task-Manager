#pragma once

#include <vector>
#include <string>

class IModelGeneralRAM
{
public:
    virtual std::vector<std::string> GeneralRAMParams(const std::string& path, const std::vector<std::string>& needs) = 0;
};  