#pragma once

#include "IControllerGRAM.h"
#include "IViewGRAM.h"
#include "IModelGRAM.h"

IControllerGRAM::ICptr create(IViewGRAM::IVptr view, IModelGRAM::IMptr model);