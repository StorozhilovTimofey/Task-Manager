#pragma once

#include <memory>
#include <string>
#include <vector>

#include "IGeneralRAMParams.h"

class ControllerGRAM : public IControllerGRAM
{
public:
    ControllerGRAM(IViewGRAM::IVptr view, IModelGRAM::IMptr model);
    void Launch() override;
private:
    IViewGRAM::IVptr view;
    IModelGRAM::IMptr model;
    const std::string path = "/proc/meminfo";
    const std::vector<std::string> needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    };
};

class ModelGRAM : public IModelGRAM
{
public:
    std::vector<std::string> GRAMparams(const std::string& path,
                                    const std::vector<std::string>& needs) override;
private:
    std::string FirstWord(const std::string& line);
    std::string PrettyData(std::string& line);
    std::string ConvertFloatToString(float& number);
};

class ViewGRAM : public IViewGRAM
{
public:
    void ShowGeneralParams(const std::vector<std::string>& params) override;
};