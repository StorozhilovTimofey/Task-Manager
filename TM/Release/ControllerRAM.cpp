#include "ControllerRAM.h"
#include "Controller/ICGeneralRAM.h"
#include "Model/IMGeneralRAM.h"
#include "View/IVGeneralRAM.h"
#include "Controller/CGeneralRAM.h"

IControllerGRAM::IGRAMCptr create(IViewGRAM::IGRAMVptr view, IModelGRAM::IGRAMMptr model)
{
    return std::make_shared<ControllerGRAM>(std::move(view), std::move(model));
}
