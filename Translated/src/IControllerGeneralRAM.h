#pragma once

#include <string>
#include <vector>

class IControllerGeneralRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerGeneralRAM() = default;
    using Ptr = std::shared_ptr<IControllerGeneralRAM>;
};