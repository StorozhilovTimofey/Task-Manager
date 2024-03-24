#pragma once

#include <string>
#include <vector>

#include "IControllerGeneralRAM.h"
#include "ViewGeneralRAM.h"
#include "ModelGeneralRAM.h"

class ControllerGeneralRAM : public IControllerGeneralRAM
{
public:
    void Launch() override;
private:
    ModelGeneralRAM model;
    ViewGeneralRAM view;
    const std::string path = "/proc/meminfo";
    const std::vector<std::string> needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    };
};