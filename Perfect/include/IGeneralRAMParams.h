#pragma once

#include <memory>
#include <string>
#include <vector>

class IControllerGRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerGRAM() = default;
    using ICptr = std::shared_ptr<IControllerGRAM>;
};

class IModelGRAM
{
public:
    virtual std::vector<std::string> GRAMparams(const std::string& path,
                                            const std::vector<std::string>& needs) = 0;
    using IMptr = std::shared_ptr<IModelGRAM>;
};

class IViewGRAM
{
public:
    virtual void ShowGeneralParams(const std::vector<std::string>& params) = 0;
    using IVptr = std::shared_ptr<IViewGRAM>;
};