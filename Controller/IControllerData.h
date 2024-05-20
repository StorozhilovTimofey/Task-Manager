#pragma once

#include <memory>
#include <string>
#include <vector>

/*! \brief
 * Интерфейс, осуществляющий взаимодействие
 * между Model и View
 */
class IControllerData
{
public:
    /*! \brief
     * Осуществляет вывод данных оперативной памяти
     */
    virtual void PrintRAM() = 0;

    /*! \brief
     * Осуществляет вывод данных процессора
     */
    virtual void PrintCPU() = 0;
    
    virtual ~IControllerData() = default;

    using Ptr = std::shared_ptr<IControllerData>;
};
