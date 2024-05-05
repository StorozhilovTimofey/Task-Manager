#pragma once

#include "IMram.h"

class ModelRAM : public IModelRAM
{
public:
    std::vector<std::string> GRAMparams(const std::string& path,
                                    const std::vector<std::string>& needs) override; // Функция, считывающая в вектор данные об оперативе
    void CreateFile() override;
    void DeleteFile() override;
    std::vector<std::string> AllData() override;
private:
    std::string FirstWord(const std::string& line); // Возвращает первое слово в строке, без первых пробелов
    std::string PrettyData(std::string& line); // Меняте вывод, просто чтобы приятнее читалось
    std::string ConvertFloatToString(float& number); // Переводит дробь в формат строки
    std::string exec(const char* cmd); // Запускает ввод консольной команды для обнаружения данных
    void RemoveLeadingSpaces(std::string& line); // Удаляет первые пробелы в строке
    std::string GetFirstWord(const std::string& line); // Возвращает первое слово в строке

    const std::vector<std::string> lineStarts =
    {
    "Size: ",
    "Type: ",
    "Speed: ",
    "Manufacturer: ",
    "Serial Number: "
    }; // Нужные параметры для вывода

    const std::vector<std::string> ignoredStarts =
    {
    "Size: No Module Installed",
    "Type: Unknown",
    "Speed: Unknown",
    "Manufacturer: Not Specified",
    "Serial Number: Not Specified"
    }; // Параметры пустых слотов оперативной памяти, которые должны быть проигнорированы

    const std::string filePath = "memory_info.txt"; // Путь до создаваемого файла
    int counter = 1; // Счетчик плашек оперативной памяти
};
