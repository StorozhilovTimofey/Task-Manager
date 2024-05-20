#pragma once

#include <memory>
#include <string>
#include <vector>

class IControllerData
{
public:
    virtual void PrintRAM() = 0;
    virtual void PrintCPU() = 0;
    
    virtual ~IControllerData() = default;

    using Ptr = std::shared_ptr<IControllerData>;
};
