#pragma once

#include <memory>
#include <string>
#include <vector>


class IModelRAM
{
public:
    virtual std::vector<std::string> GRAMparams(const std::string& path,
                                            const std::vector<std::string>& needs) = 0;
    virtual void CreateFile() = 0;
    virtual void DeleteFile() = 0;
    virtual std::vector<std::string> AllData() = 0;
    virtual ~IModelRAM() = default;
    using IMptr = std::shared_ptr<IModelRAM>;
};
