#include "Controller.h"
#include "ControllerGeneralRAM.h"

IControllerGeneralRAM::Ptr create(IModelGeneralRAM::Ptr model, IViewGeneralRAM* view)
{
    return std::make_shared<ControllerGeneralRAM>(std::move(model), view);
}