#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Pet.h"
using namespace std;


string lowercase(string);

string decideMood(int);

ostream& operator<<(ostream&, const Pet&);

void retrieveArt(string);
