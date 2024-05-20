#include "View.h"

IViewData::Ptr View::create()
{
    return std::make_shared<ViewData>();
}