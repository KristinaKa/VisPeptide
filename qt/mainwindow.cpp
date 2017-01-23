#include "mainwindow.h"
#include "QFileDialog"
#include <iostream>

using namespace std;

MainWindow::MainWindow()
{
        createImportBox();
        createParameterBox();

        //le layout principal
        mainLayout = new QGridLayout;
        mainLayout->addWidget(importBox, 0, 0);
        mainLayout->addWidget(parameterBox, 1, 0);
        //addLayout(QLayout *layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment = Qt::Alignment())

        setLayout(mainLayout); //we install the layout in the window
        setWindowTitle(tr("Basic Layouts"));
	//QPushButton run = new QPushButton("run");
}



void MainWindow::createImportBox()
{
    //La boîte
    importBox = new QGroupBox(tr("Data"));
    //Le layout qui ira dans la boîte
    QHBoxLayout *layout = new QHBoxLayout;

    //Browse button
    QPushButton* browseButton = new QPushButton("Browse");
    layout->addWidget(browseButton);
    openFileNameLabel = new QLabel("");
    layout->addWidget(openFileNameLabel);
    QObject::connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));

    //Run button
    QPushButton* runButton = new QPushButton("Run");
    layout->addWidget(runButton);
    QObject::connect(runButton, SIGNAL(clicked()), this, SLOT(run()));


    //On installe le layout dans la boite
    importBox->setLayout(layout);
}


void MainWindow::browse(){
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Select a file to open...", QDir::homePath());

    for (int i=0; i<fileNames.size(); i++){
        QString fileName = fileNames[i];
        std::string name = fileName.toUtf8().constData();
        mgfFileNames.push_back(name);
        openFileNameLabel->setText(openFileNameLabel->text()+"\n"+fileName);
   }
}

void MainWindow::run(){
    if (mgfFileNames.size() >= 2){
        string mgf1F = mgfFileNames[0];
        string mgf2F = mgfFileNames[1];

        ResultSap res = launch_speptide(mgf1F, mgf2F);

        createVisuBox(res);
        mainLayout->addWidget(visuBox,0, 1, 2, 2);
     }
}

void MainWindow::createVisuBox(ResultSap result)
{
    visuBox = new QGroupBox(tr("Visu"));
    QVBoxLayout *layout = new QVBoxLayout;

    //Création et remplissage d'une table de résultats
    resultsTable = new QTableWidget(this);
    fillTableWidget(result);

    layout->addWidget(resultsTable);

    visuBox->setLayout(layout);
}

void MainWindow::fillTableWidget(ResultSap result)
{
    int row_n = result.get_nb_results();
    int column_n = 7;

    qDebug()<<"row "<<row_n;

    resultsTable->setRowCount(row_n);
    resultsTable->setColumnCount(column_n);

    QStringList labels;
    labels.append("title seq 1");
    labels.append("title 2");
    labels.append("position");
    labels.append("aminoacid 1");
    labels.append("aminoacid 2");
    labels.append("sequence 2");
    labels.append("angle");
    resultsTable->setHorizontalHeaderLabels(labels);


    for (int row=0; row<row_n; row++){
    std::vector<std::string> resultsLine = result.get_result_with_index(row);
        for (int column=0; column<column_n; column++){
            std::cout<<"resultsLine "<< resultsLine[column]<<"\n";
            QString text = QString::fromStdString(resultsLine[column]);
            qDebug()<<"qstring text"<<text;
            QTableWidgetItem *newItem = new QTableWidgetItem(text);
            qDebug()<<row<<" "<<column;
            resultsTable->setItem(row, column, newItem);
        }
    }
}



int MainWindow::verifyImports(){
    if (mgfFileNames.size() == 2)
        return 1;
    return 0;
}

void MainWindow::createParameterBox()
{
    //La boîte
    parameterBox = new QGroupBox(tr("Parameters"));
    //Le layout qui ira dans la boîte
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    //On installe le layout dans la boite
    parameterBox->setLayout(layout);
}

