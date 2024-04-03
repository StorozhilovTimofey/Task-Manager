#include "Controller.h"
#include "ControllerGRAM.h"

IControllerGRAM::ICptr create(IViewGRAM::IVptr view, IModelGRAM::IMptr model)
{
    return std::make_shared<ControllerGRAM>(std::move(view), std::move(model));
}