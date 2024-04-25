#include "ICram.h"
#include "View/IVram.h"
#include "Model/IMram.h"

#include "ICPUController.h"
#include "View/ICPUView.h"
#include "Model/ICPUModel.h"

IControllerRAM::ICptr createControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model);

IControllerCPU::ICptr createControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model);
