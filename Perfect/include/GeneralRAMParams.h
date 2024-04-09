#pragma once

#include <memory>
#include <string>
#include <vector>

#include "IGeneralRAMParams.h"

// Контроллер общих параметров оперативной памяти
class ControllerGRAM : public IControllerGRAM
{
public:
    ControllerGRAM(IViewGRAM::IVptr view, IModelGRAM::IMptr model); // Конструктор с указателями на интерфейсы model и view
    void Launch() override; // Функция, которая запускает реализацию проекта, осуществляя связь между всеми компонентами
private:
    IViewGRAM::IVptr view;
    IModelGRAM::IMptr model;
    const std::string path = "/proc/meminfo"; // Путь до файла с информацией об оперативной памяти
    const std::vector<std::string> needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    }; // Вектор, для поиска и сравнения нужных параметров из всех доступных в файле
};

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

// Вид общих параметров оперативной памяти
class ViewGRAM : public IViewGRAM
{
public:
    void ShowGeneralParams(const std::vector<std::string>& params) override; // Выводит параметры
};