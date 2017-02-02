
#ifndef NEWWINDOW_H
#define NEWWINDOW_H

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



class NewWindow : public QWidget
{
    Q_OBJECT

    public:
        NewWindow(std::vector<char*> &);
        ~NewWindow();
        QString colorSequence(int);
    private:
      std::vector<char*> results;
      QGroupBox *resultsBox;
      QVBoxLayout *layout;
      QTextEdit *sequence;
      QGridLayout *mainLayout;
};

#endif 
