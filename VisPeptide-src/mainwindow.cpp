#include "mainwindow.h"
#include "QFileDialog"
#include <iostream>
#include <fstream>


using namespace std;

MainWindow::MainWindow()
{
        createImportBox();

        mainLayout = new QGridLayout;
        mainLayout->addWidget(importBox, 0, 0);

        setLayout(mainLayout);
        setWindowTitle(tr("VisPeptide"));
}


void MainWindow::createImportBox()
{
    importBox = new QGroupBox(tr("Data"));
    QVBoxLayout *layout = new QVBoxLayout;

    //Load mgf files button
    QPushButton* browseButton = new QPushButton("Load mgf files");
    layout->addWidget(browseButton);
    openFileNameLabel = new QLabel("");
    layout->addWidget(openFileNameLabel);
    QObject::connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));

    //Load parameters button
    parametersButton = new QPushButton("Load Parameters");
    layout->addWidget(parametersButton);
    QObject::connect(parametersButton, SIGNAL(clicked()), this, SLOT(loadParameters()));

    //Run button
    QPushButton* runButton = new QPushButton("Run");
    layout->addWidget(runButton);
    QObject::connect(runButton, SIGNAL(clicked()), this, SLOT(run()));

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


  char *command = "./../speptide-src/speptide ";

  char *file1 = (char*)mgfFileNames[0].c_str();
  char *file2 = (char*)mgfFileNames[1].c_str();
  char *params = (char*)mgfFileNames[2].c_str();
  char *output = " >> ./../speptide-src/results.txt";
  char result[1000];   // array to hold the result.

  strcpy(result,command);
  strcat(result,file1);
  strcat(result," ");
  strcat(result,file2);
  strcat(result," ");
  strcat(result,params);
  strcat(result,output);

  std::system(result); 

  readResults();
  std::system("rm ../speptide-src/results.txt");
  createVisuBox();

  mainLayout->addWidget(visuBox,0, 1, 2, 2);

}

void MainWindow::createVisuBox()
{
    visuBox = new QGroupBox(tr("Results"));
    QVBoxLayout *layout = new QVBoxLayout;

    QString data;


    for (int i = 0; i< results.size(); i++){
      
      resultsButtons.push_back(new QPushButton("See result"));
      layout->addWidget(resultsButtons[i]);
      QObject::connect(resultsButtons[i], SIGNAL(clicked()), this, SLOT(checkResults()));

    }

    visuBox->setLayout(layout);
}

void MainWindow::checkResults(){

      QObject *inconnu = sender();

      std::vector<char *> myButtonResults;

      for (int i=0; i<resultsButtons.size(); i++){
        if (inconnu==resultsButtons[i]){
            myButtonResults = results[i];         
        }
      }
      
     ResultWindow *mMyResultWindow = new ResultWindow(myButtonResults); // Be sure to destroy you window somewhere

     mMyResultWindow->show();
}


void MainWindow::readResults(){

    std::ifstream infile("../speptide-src/results.txt");
    std::string line;
    std::vector< std::vector <char*> > results_data;
    std::vector<char*> results_line;
    std::string s;
    char * scopy;

	while (std::getline(infile, line))
	{
        istringstream ss(line);

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
