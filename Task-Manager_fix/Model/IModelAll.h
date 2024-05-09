#pragma once

#include "ICPUModel.h"
#include "IMram.h"


class IModelAll
{
public:
    virtual std::shared_ptr<IModelCPU> getCpu() = 0;
    virtual std::shared_ptr<IModelRAM> getRam() = 0;

    using IMptr = std::shared_ptr<IModelAll>;
    ~IModelAll() = default;
};
