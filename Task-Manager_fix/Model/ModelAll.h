#pragma once

#include "CPUModel.h"
#include "IModelAll.h"
#include "Model.h"
#include "Mram.h"


class ModelAll : public IModelAll
{
public:
    std::shared_ptr<IModelCPU> getCpu() override;
    std::shared_ptr<IModelRAM> getRam() override;

    ~ModelAll() = default;
};
