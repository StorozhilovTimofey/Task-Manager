#pragma once

#include "ICPUController.h"


class ControllerCPU : public IControllerCPU
{
public:
    ControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model);
    void Launch() override;
private:
    IViewCPU::IVptr view;
    IModelCPU::IMptr model;
};
