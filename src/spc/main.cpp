#include "speptide.h"
#include "result.h"

using namespace std;

int main (int argc, char *argv[]){

  try {
  
    // check input arguments and print help
    if(argc != 4) {
      cout << "  speptide version 0.92 by Dima Ischenko (ischenko.dmitry@gmail.com)" << endl;
      cout << endl;
      cout << "  Usage:" << endl;
      cout << "   speptide <exp mgf> <db mgf> <config>" << endl;
      cout << endl;
      cout << "  Inputs:" << endl;
      cout << "   <exp mgf>    (string)  experiment spectra mgf file." << endl;
      cout << "   <db mgf>     (string)  database spectra mgf file (with SEQ tag)." << endl;
      cout << "   <config>     (string)  ini file with params for search." << endl;
      cout << endl;
      cout << "  Output (tab separated format):" << endl;
      cout << "   [exp spectra] [db spectra] [position] [exp ami] [db ami] [db seq] [cos(theta)]" << endl;
      cout << endl;
      cout << "  Read doc/speptide.pdf for detailed information.";
      cout << endl;
      exit(1);
    }
  } catch(exception& e) {
    cerr << "Error: " << e.what() << endl;
    exit(1);
  }
  // set mgf filenames
  string mgf1F = (string)argv[1];
  string mgf2F = (string)argv[2];
  
  // load ini file and set params
  dictionary* ini;
  ini = iniparser_load(argv[3]);
  if (ini == NULL) return -1;

  ResultSap res = launch_speptide(mgf1F, mgf2F, ini);

  res.print();
  return 0;

}
