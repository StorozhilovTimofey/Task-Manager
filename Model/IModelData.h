#pragma once

#include <memory>
#include <string>
#include <vector>

class IModelData
{
public:
    virtual std::vector<std::string> getRamGeneral(const std::string& path,
                                            const std::vector<std::string>& needs) = 0;
    virtual std::vector<std::string> getRamSpecific() = 0;
    virtual void CreateFile() = 0;
    virtual void DeleteFile() = 0;

    virtual double getCpuTemperature() = 0;
    virtual double getCurrentCpuFrequency() = 0;
    virtual std::vector<double> getParametres() = 0;
    
    virtual ~IModelData() = default;
    
    using Ptr = std::shared_ptr<IModelData>;
};