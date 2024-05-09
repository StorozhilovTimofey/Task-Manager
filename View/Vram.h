#pragma once

#include "IVram.h"

class ViewRAM : public IViewRAM
{
public:
    void ShowRAMParams(const std::vector<std::string>& RAMParams,
                       const std::vector<std::string>& params) override;
    ~ViewRAM();
};