#pragma once

#include <memory>

#include "Model/ICPUModel.h"
#include "View/ICPUView.h"


class IControllerCPU
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerCPU() = default;

    using ICptr = std::shared_ptr<IControllerCPU>;
};
