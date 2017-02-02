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
        QLabel *openFileNameLabel;
        std::vector<std::string> mgfFileNames;

        QGridLayout *mainLayout;
        QGroupBox *importBox;
        QGroupBox *visuBox;

        std::vector<ResultWindow *> ResultsWindows;
        std::vector<QPushButton *> resultsButtons;
        QPushButton *parametersButton;
        std::vector< std::vector <char*> > results;

        void createImportBox();
        void createVisuBox();
        void readResults();

    public slots:
        void browse();
        void loadParameters();
        void run();
        void checkResults();
};

#endif // MAINWINDOW_H

