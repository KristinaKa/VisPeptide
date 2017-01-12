#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
#include <stdexcept>
#include "time.h"

#include "../ini/iniparser.h"
#include "spectra.h"
#include "mparser.h"
#include "result.h"
#include "scoring.h"

using namespace std;

#ifndef SPEPTIDE_H
#define SPEPTIDE_H


ResultSap launch_speptide (string mgf1F, string mgf2F, dictionary* ini);


#endif
