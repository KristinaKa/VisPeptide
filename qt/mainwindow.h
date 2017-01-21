#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private:
    void createImportBox();
    void createParameterBox();
    void createVisuBox();


    enum { NumGridRows = 3, NumButtons = 4 };

    QGroupBox *importBox;
    QGroupBox *parameterBox;
    QGroupBox *visuBox;
    QPushButton *buttons[NumButtons];

};

#endif // MAINWINDOW_H

