#include "ICram.h"
#include "View/IVram.h"
#include "Model/IMram.h"

IControllerRAM::ICptr createController(IViewRAM::IVptr view, IModelRAM::IMptr model);
