#pragma once

#include "IGeneralRAMParams.h"

IControllerGRAM::ICptr create(IViewGRAM::IVptr view, IModelGRAM::IMptr model); // Создает указатель на интерфейс класс контроллера