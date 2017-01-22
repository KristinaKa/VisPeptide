#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <string>
#include <vector>
#include "../src/spc/speptide.h"
#include "../src/spc/result.h"
#include <iostream>

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

    QLabel *openFileNameLabel;
    std::vector<std::string> mgfFileNames;
    QGroupBox *importBox;
    QGroupBox *parameterBox;
    QGroupBox *visuBox;
    QPushButton *buttons[NumButtons];

public slots:
    void browse();
    void run();
    int verifyImports();
};

#endif // MAINWINDOW_H

