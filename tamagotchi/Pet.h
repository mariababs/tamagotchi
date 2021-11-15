#ifndef PET_H
#define PET_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Pet { 
    /*
    Pet is an abstract base class that contains all of the fields and functions a generic pet would need.
    */
    friend ostream& operator<<(ostream &os, const Pet&);
    private:
        int hunger = 0;
        int mood = 0;
        string name;
    public: 
        /*
        eat asks the user which food they would like to feed to their pet.
        Only the relevant food options are offered, depending on the pet.
        The selected food art is retrieved and hunger and mood values are updated.
        */
        virtual void eat(ofstream &fout) = 0;

        /*
        action asks the user which action they would like to interact with their pet with.
        Only the relevant action options are offered, depending on the pet.
        The selected action art is retrieved and hunger and mood values are updated.
        */
        virtual void action(ofstream &fout) = 0;

        void setHunger(int);
        int getHunger();

        void setMood(int);
        int getMood();

        void setName(string n);
        string getName();
};

#endif /* PET_H */