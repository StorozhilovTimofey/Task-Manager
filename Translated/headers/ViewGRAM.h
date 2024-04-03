#pragma once

#include "IViewGRAM.h"

class ViewGRAM : public IViewGRAM
{
public:
    void ShowGeneralParams(const std::vector<std::string>& params) override;
};