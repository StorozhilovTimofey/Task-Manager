#pragma once

#include <string>
#include <vector>

#include "IParticularRAMParams.h"

class ModelPRAM : public IModelPRAM
{
public:
    void CreateFile() override;
    void DeleteFile() override;
    std::vector<std::string> AllData() override;
private:
    std::string exec(const char* cmd);
    void RemoveLeadingSpaces(std::string& line);
    std::string GetFirstWord(const std::string& line);

    const std::vector<std::string> lineStarts = 
    {
    "Size: ", 
    "Type: ",
    "Speed: ",
    "Manufacturer: ",
    "Serial Number: "
    };

    const std::vector<std::string> ignoredStarts = 
    {
    "Size: No Module Installed",
    "Type: Unknown",
    "Speed: Unknown",
    "Manufacturer: Not Specified",
    "Serial Number: Not Specified"
    };

    const std::string filePath = "memory_info.txt";
    int counter = 1;
};

class ViewPRAM : public IViewPRAM
{
public:
    void ShowRAMParams(const std::vector<std::string>& RAMParams) override;
};

class ControllerPRAM : public IControllerPRAM
{
public:
    ControllerPRAM(IViewPRAM::IVptr view, IModelPRAM::IMptr model);
    void Launch() override;
private:
    IViewPRAM::IVptr view;
    IModelPRAM::IMptr model;
};