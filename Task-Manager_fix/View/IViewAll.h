#pragma once

#include <memory>

#include "ICPUView.h"
#include "IVram.h"


class IViewAll
{
public:
    virtual std::shared_ptr<IViewCPU> getCpu() = 0;
    virtual std::shared_ptr<IViewRAM> getRam() = 0;

    using IVptr = std::shared_ptr<IViewAll>;
    ~IViewAll() = default;
};
