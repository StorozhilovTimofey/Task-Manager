#pragma once

#include <memory>

class IControllerGRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerGRAM() = default;

    using IGRAMCptr = std::shared_ptr<IControllerGRAM>;
};
