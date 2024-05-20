#include "View.h"

IViewRAM::IVptr createViewRAM()
{
    return std::make_shared<ViewRAM>();
}