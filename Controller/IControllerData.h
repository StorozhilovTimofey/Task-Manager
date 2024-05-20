#pragma once

#include <memory>
#include <string>
#include <vector>

class IControllerData
{
public:
    virtual void Launch1() = 0;
    virtual void Launch2() = 0;
    virtual ~IControllerData() = default;
    using Ptr = std::shared_ptr<IControllerData>;
};
