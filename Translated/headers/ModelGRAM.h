#pragma once

#include <string>
#include <vector>

#include "IModelGRAM.h"

class ModelGRAM : public IModelGRAM
{
public:
    std::vector<std::string> GRAMparams(const std::string& path,
                                    const std::vector<std::string>& needs) override;
private:
    std::string FirstWord(const std::string& line);
    std::string PrettyData(std::string& line);
    std::string ConvertFloatToString(float& number);
};