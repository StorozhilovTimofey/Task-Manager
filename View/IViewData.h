#pragma once

#include <memory>
#include <string>
#include <vector>


//! \brief Интерфейс для печати данных по ram и cpu
class IViewData
{
public:
    //! \brief Выводит вектор с ram 
    virtual void ShowRamParametres(const std::vector<std::string>& RAMParams,
                               const std::vector<std::string>& params) = 0;
    
    //! \brief Выводит вектор с cpu 
    virtual void ShowCpuParametres(std::vector<double> input) = 0;
    
    virtual ~IViewData() = default;
    
    using Ptr = std::shared_ptr<IViewData>;
};