#include "ICram.h"
#include "IMram.h"
#include "IVram.h"

class ControllerRAM : public IControllerRAM
{
public:
    ControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model); // Конструктор с указателями на интерфейсы model и view
    void Launch() override; // Функция, которая запускает реализацию проекта, осуществляя связь между всеми компонентами
private:
    IViewRAM::IVptr view;
    IModelRAM::IMptr model;
    const std::string path = "/proc/meminfo"; // Путь до файла с информацией об оперативной памяти
    const std::vector<std::string> needs =
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    }; // Вектор, для поиска и сравнения нужных параметров из всех доступных в файле
};
