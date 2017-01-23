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
#include <QTableWidget>
#include <QtDebug>
#include <QStringList>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private:
    void createImportBox();
    void createParameterBox();
    void createVisuBox(ResultSap result);
    void fillTableWidget(ResultSap);


    enum { NumGridRows = 3, NumButtons = 4 };

    QLabel *openFileNameLabel;
    std::vector<std::string> mgfFileNames;

    QGridLayout *mainLayout;
    QGroupBox *importBox;
    QGroupBox *parameterBox;
    QGroupBox *visuBox;
    QTableWidget *resultsTable;
    QPushButton *buttons[NumButtons];

public slots:
    void browse();
    void run();
    int verifyImports();
};

#endif // MAINWINDOW_H

