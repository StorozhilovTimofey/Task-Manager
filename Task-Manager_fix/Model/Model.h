#pragma once

#include "Mram.h"
#include "CPUModel.h"
#include "IModelAll.h"

IModelRAM::IMptr createModelRAM();

IModelCPU::IMptr createModelCPU();

IModelAll::IMptr createMAll();
