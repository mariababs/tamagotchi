#include <iostream>
#include "Pet.h"
using namespace std;

class Cat : public Pet { 
    public: 
        Cat();
        ~Cat();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};