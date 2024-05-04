#pragma once

#include <memory>

#include "ICPUModel.h"
#include "ICPUView.h"


class IControllerCPU
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerCPU() = default;

    using ICptr = std::shared_ptr<IControllerCPU>;
};
