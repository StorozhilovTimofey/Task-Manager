#pragma once

#include <memory>


class IControllerRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerRAM() = default;
    using ICptr = std::shared_ptr<IControllerRAM>;
};
