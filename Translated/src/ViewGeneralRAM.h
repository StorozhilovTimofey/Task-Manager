#pragma once

#include <vector>
#include <string>

#include "IViewGeneralRAM.h"

class ViewGeneralRAM : public IViewGeneralRAM
{
public:
    void ShowGeneralRAMParams(const std::vector<std::string> params) override;
};