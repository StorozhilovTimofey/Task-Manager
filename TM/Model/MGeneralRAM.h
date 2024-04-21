#pragma once

#include <string>
#include <vector>

#include "IMGeneralRAM.h"

// Модель общих параметров оперативной памяти
class ModelGRAM : public IModelGRAM
{
public:
    std::vector<std::string> GRAMparams(const std::string& path,
                                    const std::vector<std::string>& needs) override; // Функция, считывающая в вектор данные об оперативе
private:
    std::string FirstWord(const std::string& line); // Возвращает первое слово в строке, без первых пробелов
    std::string PrettyData(std::string& line); // Меняте вывод, просто чтобы приятнее читалось
    std::string ConvertFloatToString(float& number); // Переводит дробь в формат строки
};
