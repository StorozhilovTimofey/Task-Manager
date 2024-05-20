#include "Controller.h"

IControllerData::Ptr createController(IViewData::Ptr view, IModelData::Ptr model)
{
    return std::make_shared<ControllerData>(std::move(view), std::move(model));
}