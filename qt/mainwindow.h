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
#include <QProcess>
#include <QByteArray>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private:
    void createImportBox();
    void createParameterBox();
    //void createVisuBox(ResultSap result);
    void fillTableWidget(ResultSap);
      void createVisuBox(QByteArray);

    enum { NumGridRows = 3, NumButtons = 4 };

    QLabel *openFileNameLabel;
    QStringList mgfFileNames;

    QGridLayout *mainLayout;
    QGroupBox *importBox;
    QGroupBox *parameterBox;
    QGroupBox *visuBox;
    QTableWidget *resultsTable;
    QPushButton *buttons[NumButtons];
    QProcess *process;

public slots:
    void browse();
    void run();
    int verifyImports();

};

#endif // MAINWINDOW_H

