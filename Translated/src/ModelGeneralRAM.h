#pragma once

#include "IModelGeneralRAM.h"

class ModelGeneralRAM : public IModelGeneralRAM
{
public:
    std::vector<std::string> GeneralRAMParams(const std::string& path, const std::vector<std::string>& needs) override;
private:
    std::string FirstWord(const std::string& line);
};