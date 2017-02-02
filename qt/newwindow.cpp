
#include "newwindow.h"
#include "QFileDialog"
#include <iostream>
#include <fstream>


NewWindow::NewWindow(std::vector<char*> &results)
{
  this->results=results;
  resultsBox = new QGroupBox(tr("Your Result"));
  sequence = new QTextEdit();


//  data.append("<p><b>Your Sequence : <b></p>");
//  data.append("<p>");
//  data.append(results[5]);
//  data.append("<p>");
//

  // 0 if original sequence, 1 otherwise
  QString data = "<p> <b>Experiment spectrum title :</b><br> ";
  data = data + results[0] + "</p>";
  data = data + "<p> <b> Database spectrum title :</b><br> ";
  data = data + results[1]+ "</p>";
   
  data = data +  "<p><b>Reference sequence : </b><br>";
  data = data + colorSequence(0) + "</p>";

  data = data + "<p><b> SAP on the sequence : </b>";
  data = data +colorSequence(1) + "</p>";

  data = data + "<p><b> Cos angle between spectra : </b>";
  data = data +results[6] + "</p>";

  for (int i=0; i< results.size();i++){
    std::cout << results[i]<< std::endl;
  }

  sequence->setHtml(data);

  layout = new QVBoxLayout; 

  layout->addWidget(sequence);


  resultsBox->setLayout(layout);
        
  mainLayout = new QGridLayout;
  mainLayout->addWidget(resultsBox, 0, 0);
  setLayout(mainLayout); //we install the layout in the window
  setWindowTitle(tr("Results"));
}

NewWindow::~NewWindow(){
  
}

QString NewWindow::colorSequence(int mode){


  int position = atoi(results[2]);

  char *sap = results[3];

  char *sequence = results[5];

  QString colored_sequence;

  for (int i=0; i<position-1; i++){
    colored_sequence.append(sequence[i]);

  }

  colored_sequence.append("<span style=\" color:#ff0000;\">");
  if (mode==0){
  colored_sequence.append(sequence[position-1]);
  }
  else{
  colored_sequence.append(sap);
  }
  colored_sequence.append("</span>");

  if (position!=strlen(sequence)){
  for (int i=position; i<strlen(sequence); i++){
    colored_sequence.append(sequence[i]);

  }
  }
  return colored_sequence;

}
