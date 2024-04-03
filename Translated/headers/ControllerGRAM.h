#pragma once

#include <string>
#include <vector>

#include "IModelGRAM.h"
#include "IViewGRAM.h"
#include "IControllerGRAM.h"

class ControllerGRAM : public IControllerGRAM
{
public:
    ControllerGRAM(IViewGRAM::IVptr view, IModelGRAM::IMptr model);
    void Launch() override;
private:
    IViewGRAM::IVptr view;
    IModelGRAM::IMptr model;
    const std::string path = "/proc/meminfo";
    const std::vector<std::string> needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    };
};