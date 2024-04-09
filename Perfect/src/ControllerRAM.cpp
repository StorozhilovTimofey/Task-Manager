#include "ControllerRAM.h"
#include "GeneralRAMParams.h"
#include "ParticularRAMParams.h"

IControllerGRAM::ICptr create(IViewGRAM::IVptr view, IModelGRAM::IMptr model)
{
    return std::make_shared<ControllerGRAM>(std::move(view), std::move(model));
}

IControllerPRAM::ICptr create(IViewPRAM::IVptr view, IModelPRAM::IMptr model)
{
    return std::make_shared<ControllerPRAM>(std::move(view), std::move(model));
}