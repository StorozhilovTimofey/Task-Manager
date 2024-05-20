#include "Controller.h"

IControllerData::Ptr Controller::create(IViewData::Ptr view, IModelData::Ptr model)
{
    return std::make_shared<ControllerData>(std::move(view), std::move(model));
}