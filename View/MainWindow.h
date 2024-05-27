#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <vector>
#include <string>

class MainWindow : public QWidget {
public:
   MainWindow() {
       // Initialize the vectors
       stringsVector = {"String 1", "String 2", "String 3"};
       numbersVector = {1.1, 2.2, 3.3, 4.4};
   }

   void display() {
       // Create a layout
       QVBoxLayout *layout = new QVBoxLayout();

       // Display strings vector
       QLabel *stringsLabel = new QLabel("Strings Vector:");
       layout->addWidget(stringsLabel);

       for (const auto &str : stringsVector) {
           QLabel *strLabel = new QLabel(QString::fromStdString(str));
           layout->addWidget(strLabel);
       }

       // Display numbers vector
       QLabel *numbersLabel = new QLabel("Numbers Vector:");
       layout->addWidget(numbersLabel);

       for (const auto &num : numbersVector) {
           QLabel *numLabel = new QLabel(QString::number(num));
           layout->addWidget(numLabel);
       }

       setLayout(layout);
       show();
   }

private:
   std::vector<std::string> stringsVector;
   std::vector<double> numbersVector;
};
