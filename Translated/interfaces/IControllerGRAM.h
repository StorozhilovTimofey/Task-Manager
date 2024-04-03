#pragma once

#include <string>
#include <vector>
#include <memory>

class IControllerGRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerGRAM() = default;
    using ICptr = std::shared_ptr<IControllerGRAM>;
};