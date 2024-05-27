#pragma once

#include <QLabel>
#include <QVBoxLayout>

#include "IModelData.h"

class MainWindow : public QWidget
{
public:
    MainWindow(IModelData::Ptr model);
    void display();
private:
   std::vector<std::string> stringsVector1;
   std::vector<std::string> stringsVector2;
   std::vector<double> numbersVector;
   IModelData::Ptr model;
};
