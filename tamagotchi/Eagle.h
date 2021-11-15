#include <iostream>
#include "Pet.h"
using namespace std;

class Eagle : public Pet { 
    /*
    Eagle is a child of the parent abstract base class, Pet. Eagle has its own actions and food possibilities.
    */
    public: 
        Eagle();
        ~Eagle();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};