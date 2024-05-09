#pragma once

#include <memory>
#include <vector>

#include "Model.h"
#include "CPUModel.h"
#include "Mram.h"
#include "IModelAll.h"

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

class ModelAll1 : public IModelAll
{
public:
    std::shared_ptr<IModelCPU> getCpu() override;
    std::shared_ptr<IModelRAM> getRam() override;

    ~ModelAll1() = default;
};

