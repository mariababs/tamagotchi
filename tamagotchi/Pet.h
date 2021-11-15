#ifndef PET_H
#define PET_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Pet { 
    friend ostream& operator<<(ostream &os, const Pet&);
    private:
        int hunger = 0;
        int mood = 0;
        string name;
    public: 
        virtual void eat(ofstream &fout) = 0;
        virtual void action(ofstream &fout) = 0;

        void setHunger(int);
        int getHunger();

        void setMood(int);
        int getMood();

        void setName(string n);
        string getName();
};

#endif /* PET_H */