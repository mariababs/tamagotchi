#include <iostream>
#include "Pet.h"
using namespace std;

class Dog : public Pet { 
    /*
    Dog is a child of the parent abstract base class, Pet. Dog has its own actions and food possibilities.
    */
    public: 
        Dog();
        ~Dog();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};