#pragma once

#include <memory>
#include <vector>

#include "Model.h"
#include "CPUModel.h"
#include "Mram.h"


class ModelAll
{
public:
    std::shared_ptr<IModelCPU> Ptr_cpu;
    std::shared_ptr<IModelRAM> Ptr_ram;

    ModelAll()
    {
        Ptr_cpu = createModelCPU();
        Ptr_ram = createModelRAM();
    }
};
