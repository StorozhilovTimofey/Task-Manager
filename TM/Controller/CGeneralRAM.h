#pragma once

#include "ICGeneralRAM.h"
#include "Model/IMGeneralRAM.h"
#include "View/IVGeneralRAM.h"

// Контроллер общих параметров оперативной памяти
class ControllerGRAM : public IControllerGRAM
{
public:
    ControllerGRAM(IViewGRAM::IGRAMVptr view, IModelGRAM::IGRAMMptr model); // Конструктор с указателями на интерфейсы model и view
    void Launch() override; // Функция, которая запускает реализацию проекта, осуществляя связь между всеми компонентами
private:
    IViewGRAM::IGRAMVptr view;
    IModelGRAM::IGRAMMptr model;
    const std::string path = "/proc/meminfo"; // Путь до файла с информацией об оперативной памяти
    const std::vector<std::string> needs =
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    }; // Вектор, для поиска и сравнения нужных параметров из всех доступных в файле
};
