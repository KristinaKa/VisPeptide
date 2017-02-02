#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "resultwindow.h"
#include <cstdlib>
#include <vector>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <QTableWidget>
#include <QtDebug>
#include <QStringList>
#include <QTextEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private:
    void createImportBox();
    void createVisuBox();
    void readResults();


    enum { NumGridRows = 3, NumButtons = 4 };

    QLabel *openFileNameLabel;
    std::vector<std::string> mgfFileNames;

    QGridLayout *mainLayout;
    QGroupBox *importBox;
    QGroupBox *visuBox;
    QTableWidget *resultsTable;
    QPushButton *buttons[NumButtons];

    std::vector<ResultWindow *> ResultsWindows;
    std::vector<QPushButton *> buttonsResults;
    QPushButton *buttonParameters;
    std::vector< std::vector <char*> > results;

public slots:
    void browse();
    void loadParameters();
    void run();
    int verifyImports();
    void checkResults();
};

#endif // MAINWINDOW_H

