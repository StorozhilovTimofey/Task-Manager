#pragma once

#include "IControllerGeneralRAM.h"
#include "IModelGeneralRAM.h"
#include "IViewGeneralRAM.h"

IControllerGeneralRAM::Ptr create(IModelGeneralRAM::Ptr model, IViewGeneralRAM* view);