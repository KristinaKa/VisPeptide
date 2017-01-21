#include <QApplication>
#include <QWidget>
// #include "mainwindow.h"

#include "../src/spc/speptide.h"
#include "../src/spc/result.h"


int main(int argc, char *argv[])

{
    QApplication app(argc, argv);

    // MainWindow mainWindow;
   
    
    // mainWindow.show();
    

    string mgf1F = "/net/cremi/kkastano/espaces/travail/projet_genie_logiciel/VisPeptide/tests/h1.mgf";
    string mgf2F = "/net/cremi/kkastano/espaces/travail/projet_genie_logiciel/VisPeptide/tests/h2.mgf";
   
    ResultSap res = launch_speptide(mgf1F, mgf2F);

    return app.exec();
}
