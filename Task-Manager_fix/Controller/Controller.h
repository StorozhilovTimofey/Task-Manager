#pragma once

#include "IControllerAll.h"


IControllerRAM::ICptr createControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model);


IControllerCPU::ICptr createControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model);


IControllerAll::ICptr createCAll();
