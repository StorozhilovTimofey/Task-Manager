#pragma once

#include <string>
#include <vector>

#include "IControllerGeneralRAM.h"
#include "IViewGeneralRAM.h"
#include "IModelGeneralRAM.h"

class ControllerGeneralRAM : public IControllerGeneralRAM
{
public:
    ControllerGeneralRAM(IModelGeneralRAM* model, IViewGeneralRAM* view) : model(model), view(view) {}
    void Launch() override;
private:
    IModelGeneralRAM* model;
    IViewGeneralRAM* view;
    const std::string path = "/proc/meminfo";
    const std::vector<std::string> needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    };
};