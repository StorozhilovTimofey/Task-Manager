#include "ICram.h"
#include "IVram.h"
#include "IMram.h"

IControllerRAM::ICptr createControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model);