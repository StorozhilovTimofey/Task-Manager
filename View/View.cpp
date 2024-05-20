#include "View.h"

IViewData::Ptr createView()
{
    return std::make_shared<ViewData>();
}