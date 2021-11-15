#include <iostream>
#include "Pet.h"
using namespace std;

class Eagle : public Pet { 
    public: 
        Eagle();
        ~Eagle();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};