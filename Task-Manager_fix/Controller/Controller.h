#pragma once

#include "ICram.h"
#include "IVram.h"
#include "IMram.h"

#include "ICPUController.h"
#include "ICPUView.h"
#include "ICPUModel.h"
#include "IControllerAll.h"

IControllerRAM::ICptr createControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model);

IControllerCPU::ICptr createControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model);

IControllerAll::ICptr createCAll();