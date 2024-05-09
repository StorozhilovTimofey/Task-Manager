#pragma once

#include <memory>
#include <vector>

#include "Model.h"
#include "CPUModel.h"
#include "Mram.h"
#include "IModelAll.h"


class ModelAll : public IModelAll
{
public:
    std::shared_ptr<IModelCPU> getCpu() override;
    std::shared_ptr<IModelRAM> getRam() override;

    ~ModelAll() = default;
};

