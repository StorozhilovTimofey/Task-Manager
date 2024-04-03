#pragma once

#include <memory>
#include <string>
#include <vector>

class IModelGRAM
{
public:
    virtual std::vector<std::string> GRAMparams(const std::string& path,
                                            const std::vector<std::string>& needs) = 0;
    using IMptr = std::shared_ptr<IModelGRAM>;
};