#pragma once

#include "IGeneralRAMParams.h"
#include "IParticularRAMParams.h"

IControllerGRAM::ICptr create(IViewGRAM::IVptr view, IModelGRAM::IMptr model); // Создает указатель на интерфейс IControllerGRAM

IControllerPRAM::ICptr create(IViewPRAM::IVptr view, IModelPRAM::IMptr model); // Создает указатель на интерфейс IControllerPRAM