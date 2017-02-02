#include "mainwindow.h"
#include "QFileDialog"
#include <iostream>
#include <fstream>


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


void MainWindow::loadParameters(){

    QStringList fileParameter = QFileDialog::getOpenFileNames(this, "Select a file to open...", QDir::homePath());

    for (int i=0; i<fileParameter.size(); i++){
        QString fileName = fileParameter[i];
        std::string name = fileName.toUtf8().constData();
        mgfFileNames.push_back(name);
        openFileNameLabel->setText(openFileNameLabel->text()+"\n"+fileName);
   }

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


  char *command = "./../src/speptide ";

  char *file1 = (char*)mgfFileNames[0].c_str();
  char *file2 = (char*)mgfFileNames[1].c_str();
  char *params = (char*)mgfFileNames[2].c_str();
  char *output = " >> ./../src/results.txt"; 
 char result[1000];   // array to hold the result.

  strcpy(result,command);
  strcat(result,file1);
  strcat(result," ");
  strcat(result,file2);
  strcat(result," ");
  strcat(result,params);
  strcat(result,output);

  std::cout << result << std::endl;

  std::system(result); 

  readResults();
  createVisuBox();
//  if (mgfFileNames.size() >= 2){
//        string mgf1F = mgfFileNames[0];
//        string mgf2F = mgfFileNames[1];

//        ResultSap res = launch_speptide(mgf1F, mgf2F);
//
//        createVisuBox(res);
  mainLayout->addWidget(visuBox,0, 1, 2, 2);
  //   }
}

void MainWindow::createVisuBox()
{
    visuBox = new QGroupBox(tr("Visu"));
    QVBoxLayout *layout = new QVBoxLayout;

    QString data;

    //QPushButton *buttonsResults[results.size()];


    for (int i = 0; i< results.size(); i++){

      
      buttonsResults.push_back(new QPushButton("Browse"));
      //buttonsResults[i] = new QPushButton("Browse");
      layout->addWidget(buttonsResults[i]);
      QObject::connect(buttonsResults[i], SIGNAL(clicked()), this, SLOT(checkResults()));

    }

    //QTextEdit *sequence = new QTextEdit();
    //sequence->setHtml(data);


    //layout->addWidget(sequence);
    
    visuBox->setLayout(layout);
}

void MainWindow::checkResults(){

      std::cout << "ici" << std::endl;
      QObject *inconnu = sender();

      std::vector<char *> myButtonResults;

      for (int i=0; i<buttonsResults.size(); i++){
        if (inconnu==buttonsResults[i]){
            myButtonResults = results[i]; 
        
        }

      }
      
     NewWindow *mMyNewWindow = new NewWindow(myButtonResults); // Be sure to destroy you window somewhere

    mMyNewWindow->show();
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


//
//    for (int i = 0; i < NumButtons; ++i) {
//        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
//        layout->addWidget(buttons[i]);
//    }
    buttonParameters = new QPushButton("Load Parameters");
    layout->addWidget(buttonParameters);

    QObject::connect(buttonParameters, SIGNAL(clicked()), this, SLOT(loadParameters()));
    //On installe le layout dans la boite
    parameterBox->setLayout(layout);
}


void MainWindow::readResults(){

	std::ifstream infile("../src/results.txt");
	std::string line;
  std::vector< std::vector <char*> > results_data;
  std::vector<char*> results_line;

  std::string s;
  char * scopy;

	while (std::getline(infile, line))
	{

    istringstream ss(line);
    std::cout << "c'est une ligne " << std::endl;
    while(ss){

      if (!getline( ss, s, '\t' )) break;
      
      scopy = new char[s.size() + 1];
      std::copy(s.begin(), s.end(), scopy);
      scopy[s.size()] = '\0'; 
  
      results_line.push_back(scopy);
       }
    
    results_data.push_back(results_line);
    
    results_line.clear();

	}

  results = results_data;
}
