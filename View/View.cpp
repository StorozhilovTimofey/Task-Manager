#include "View.h"
#include "Vram.h"

IViewRAM::IVptr createView()
{
    return std::make_shared<ViewRAM>();
}
