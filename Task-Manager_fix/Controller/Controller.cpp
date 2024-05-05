#include "Controller.h"
#include "Cram.h"
#include "CPUController.h"

IControllerRAM::ICptr createControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model)
{
    return std::make_shared<ControllerRAM>(std::move(view), std::move(model));
}

IControllerCPU::ICptr createControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model)
{
    return std::make_shared<ControllerCPU>(std::move(view), std::move(model));
}
