#pragma once

#include "IModelData.h"

class ModelData : public IModelData
{
public:
    std::vector<std::string> getRamGeneral(const std::string& path,
                                    const std::vector<std::string>& needs) override; // Функция, считывающая в вектор данные об оперативе
    std::vector<std::string> getRamSpecific() override;
    void CreateFile() override;
    void DeleteFile() override;
    
    double getCpuTemperature() override;
    double getCurrentCpuFrequency() override;
    std::vector<double> getCpuParametres() override;
    
private:
    //! \brief Возвращает первое слово в строке, без первых пробелов
    std::string FirstWord(const std::string& line);

    //! \brief Меняте вывод, просто чтобы приятнее читалось
    std::string PrettyData(std::string& line);

    //! \brief Переводит дробь в формат строки
    std::string ConvertFloatToString(float& number);

    //! \brief Запускает ввод консольной команды для обнаружения данных
    std::string exec(const char* cmd);

    //! \brief Удаляет первые пробелы в строке
    void RemoveLeadingSpaces(std::string& line);

    //! \brief Возвращает первое слово в строке
    std::string GetFirstWord(const std::string& line);

    static std::string readFromFile(const std::string &filePath);

     // Путь до создаваемого файла
    int counter = 1; // Счетчик плашек оперативной памяти
};
