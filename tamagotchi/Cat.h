#include <iostream>
#include "Pet.h"
using namespace std;

class Cat : public Pet { 
    /*
    Cat is a child of the parent abstract base class, Pet. Cat has its own actions and food possibilities.
    */
    public: 
        Cat();
        ~Cat();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};