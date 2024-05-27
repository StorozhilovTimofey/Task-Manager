#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <vector>
#include <string>

#include "Model/IModelData.h"

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
