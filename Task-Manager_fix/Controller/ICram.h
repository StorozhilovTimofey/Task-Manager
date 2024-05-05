#pragma once

#include <memory>
#include <string>
#include <vector>

class IControllerRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerRAM() = default;
    using ICptr = std::shared_ptr<IControllerRAM>;
};
