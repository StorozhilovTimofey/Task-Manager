#pragma once

#include "Controller/ICGeneralRAM.h"
#include "Model/IMGeneralRAM.h"
#include "View/IVGeneralRAM.h"
#include "Controller/CGeneralRAM.h"

IControllerGRAM::IGRAMCptr create(IViewGRAM::IGRAMVptr view, IModelGRAM::IGRAMMptr model); // Создает указатель на интерфейс IControllerGRAM

//IControllerPRAM::ICptr create(IViewPRAM::IVptr view, IModelPRAM::IMptr model); // Создает указатель на интерфейс IControllerPRAM
