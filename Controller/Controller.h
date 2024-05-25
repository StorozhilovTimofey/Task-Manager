#pragma once

#include "ControllerData.h"


namespace Controller
{
IControllerData::Ptr create(IViewData::Ptr view, IModelData::Ptr model);
}