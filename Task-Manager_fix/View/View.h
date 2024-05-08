#pragma once

#include "IVram.h"
#include "ICPUView.h"
#include "IViewAll.h"


IViewRAM::IVptr createViewRAM();

IViewCPU::IVptr createViewCPU();

IViewAll::IVptr createVAll();