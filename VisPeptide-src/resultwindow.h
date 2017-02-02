
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



class ResultWindow : public QWidget
{
    Q_OBJECT

    public:
        ResultWindow(std::vector<char*> &);
        ~ResultWindow();
        QString colorSequence(int);
    private:
      std::vector<char*> results;
      QGroupBox *resultsBox;
      QVBoxLayout *layout;
      QTextEdit *sequence;
      QGridLayout *mainLayout;
};

#endif 
