#include "Controller.h"
#include "Cram.h"

IControllerRAM::ICptr createController(IViewRAM::IVptr view, IModelRAM::IMptr model)
{
    return std::make_shared<ControllerRAM>(std::move(view), std::move(model));
}
