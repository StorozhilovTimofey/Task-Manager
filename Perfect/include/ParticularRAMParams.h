#pragma once

#include <string>
#include <vector>

#include "IParticularRAMParams.h"

class ModelPRAM : public IModelPRAM
{
public:
    void CreateFile() override; // Создает файл, в который будут записаны данные об оперативе
    void DeleteFile() override; // Удаляет файл с данными за ненадобностью
    std::vector<std::string> AllData() override; // Возвращает вектор с обработанными данными
private:
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

class ViewPRAM : public IViewPRAM
{
public:
    void ShowRAMParams(const std::vector<std::string>& RAMParams) override; // Выводит вектор из функции AllData
};

class ControllerPRAM : public IControllerPRAM
{
public:
    ControllerPRAM(IViewPRAM::IVptr view, IModelPRAM::IMptr model);
    void Launch() override; // Запускает всю обработку и вывод
private:
    IViewPRAM::IVptr view; // Обращение к view
    IModelPRAM::IMptr model; // Обращение к model
};