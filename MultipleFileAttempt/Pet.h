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

        void setHunger(int amount) { 
            hunger = hunger + amount;
            if (hunger>100) {
                hunger = 100;
            }
        }
        int getHunger() { 
            return hunger;
        }

        void setMood(int amount) { 
            mood = mood + amount;
            if (mood>100) { 
                mood = 100;
            }
        }
        int getMood() { 
            return mood;
        }

        void setName(string n) { 
            name = n;
        }
        string getName() { 
            return name;
        }
};

class Dog : public Pet { 
    public: 
        Dog();
        ~Dog();
        void eat(ofstream &fout);
        void action(ofstream &fout);
        
};
class Cat : public Pet { 
    public: 
        Cat();
        ~Cat();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};
class Eagle : public Pet { 
    public: 
        Eagle();
        ~Eagle();
        void eat(ofstream &fout);
        void action(ofstream &fout);
};