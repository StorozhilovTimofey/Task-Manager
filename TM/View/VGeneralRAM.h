#pragma once

#include <string>
#include <vector>

#include "IVGeneralRAM.h"

class ViewGRAM : public IViewGRAM
{
public:
    void ShowGeneralParams(const std::vector<std::string>& params) override; // Выводит параметры
};
