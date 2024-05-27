#pragma once

#include <memory>
#include <string>
#include <vector>


/*! \brief
 * Интерфейс, нужный для записи данных ram и cpu
 * в вектор в удобном виде
 */
class IModelData
{
public:
    //! \brief Возвращает вектор с общими данными ram
    virtual std::vector<std::string> getRamGeneral() = 0;
    
    //! \brief Возвращает вектор с данными по модулям ram
    virtual std::vector<std::string> getRamSpecific() = 0;
    
    //! \brief Создает файл, в который будут записаны данные по ram
    virtual void CreateFile() = 0;

    //! \brief Удаляет файл, созданный в CreateFile
    virtual void DeleteFile() = 0;

    //! \brief Температура процессора
    virtual double getCpuTemperature() = 0;

    //! \brief Частота процессора
    virtual double getCurrentCpuFrequency() = 0;

    //! \brief Запись температуры и частоты в вектор
    virtual std::vector<double> getCpuParametres() = 0;
    
    virtual ~IModelData() = default;
    
    using Ptr = std::shared_ptr<IModelData>;
};
