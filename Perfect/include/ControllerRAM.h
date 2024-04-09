#pragma once

#include "IGeneralRAMParams.h"
#include "IParticularRAMParams.h"

IControllerGRAM::ICptr create(IViewGRAM::IVptr view, IModelGRAM::IMptr model); // Создает указатель на интерфейс класс контроллера

IControllerPRAM::ICptr create(IViewPRAM::IVptr view, IModelPRAM::IMptr model);