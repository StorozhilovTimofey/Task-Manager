#pragma once

#include <memory>
#include <string>
#include <vector>

class IViewPRAM
{
public:
    virtual void ShowRAMParams(const std::vector<std::string>& RAMParams) = 0;

    using IVptr = std::shared_ptr<IViewPRAM>;
};

class IModelPRAM
{
public:
    virtual void CreateFile() = 0;
    virtual void DeleteFile() = 0;
    virtual std::vector<std::string> AllData() = 0;

    using IMptr = std::shared_ptr<IModelPRAM>;
};

class IControllerPRAM
{
public:
    virtual void Launch() = 0;
    virtual ~IControllerPRAM() = default;

    using ICptr = std::shared_ptr<IControllerPRAM>;
};