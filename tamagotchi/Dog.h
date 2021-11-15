#include <iostream>
#include "Pet.h"
using namespace std;

class Dog : public Pet { 
    public: 
        Dog();
        ~Dog();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};