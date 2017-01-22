#include "mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow()
{
        createImportBox();
        createParameterBox();
        createVisuBox();
        //createGridGroupBox();
        //createFormGroupBox();
        //le layout principal
        QGridLayout *mainLayout = new QGridLayout;
        /*In general, the QBoxLayout class takes the space it gets
         * (from its parent layout or from the parent widget),
         * divides it up into a series of boxes, and makes each managed
         * widget fill one box. If the QBoxLayout's orientation is Qt::Horizontal
         * the boxes are placed in a row. If the orientation is Qt::Vertical,
         * the boxes are placed in a column.
         * The corresponding convenience classes are QHBoxLayout and QVBoxLayout,
         * respectively. */
        mainLayout->addWidget(importBox, 0, 0);
        mainLayout->addWidget(parameterBox, 1, 0);
        //addLayout(QLayout *layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment = Qt::Alignment())
        mainLayout->addWidget(visuBox,0, 1, 2, 2);

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
        std::cout<<"fini !!!"<<endl;
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

void MainWindow::createVisuBox()
{
    visuBox = new QGroupBox(tr("Visu"));
    QVBoxLayout *layout = new QVBoxLayout;
    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    visuBox->setLayout(layout);
}

