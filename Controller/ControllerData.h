#include "IControllerData.h"
#include "IModelData.h"
#include "IViewData.h"

class ControllerData : public IControllerData
{
public:
    ControllerData(IViewData::Ptr view, IModelData::Ptr model); // Конструктор с указателями на интерфейсы model и view
    void PrintRAM() override; // Функция, которая запускает реализацию проекта, осуществляя связь между всеми компонентами
    void PrintCPU() override;
private:
    IViewData::Ptr view;
    IModelData::Ptr model;
    const std::string path = "/proc/meminfo"; // Путь до файла с информацией об оперативной памяти
    const std::vector<std::string> needs =
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    }; // Вектор, для поиска и сравнения нужных параметров из всех доступных в файле
};
