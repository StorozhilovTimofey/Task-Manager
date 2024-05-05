#pragma once

#include <memory>
#include <vector>

#include "Controller.h"
#include "Cram.h"
#include "CPUController.h"
#include "ModelAll.h"
#include "ViewAll.h"

class ControllerAll
{
public:
    std::shared_ptr<IControllerCPU> Ptr_cpu;
    std::shared_ptr<IControllerRAM> Ptr_ram;

    ControllerAll(const ViewAll& viewAll, const ModelAll& modelAll)
    {
        Ptr_cpu = createControllerCPU(viewAll.Ptr_cpu, modelAll.Ptr_cpu);
        Ptr_ram = createControllerRAM(viewAll.Ptr_ram, modelAll.Ptr_ram);
    }
};