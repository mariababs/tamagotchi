#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// abstract base class
class Pet { 
    private:
        int hunger;
        int mood;
        string name;
    public: 
        // pure virtual functions
        virtual void eat() = 0;
        virtual void action() = 0;

        void setHunger(int amount) { 
            hunger = hunger + amount;
        }
        int getHunger() { 
            return hunger;
        }

        void setMood(int amount) { 
            mood = mood + amount;
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

        string decideMood() {
            if (mood <= 100 && mood >= 90) {
                return "Excited";
            } else if (mood <= 89 && mood >= 80) {
                return "Happy";
            } else if (mood <= 79 && mood >= 70) {
                return "Calm";
            } else if (mood <= 69 && mood >= 60) {
                return "Lonely";
            } else {
                return "Depressed";
            }
        }
};

class Dog : public Pet { 
    private: 
    public: 
        Dog(){
            cout << "What is you dog's name: " << ends;
            string n;
            getline(cin,n);
            Pet::setName(n);

            Pet::setHunger(80);
            Pet::setMood(80);
        }
        ~Dog() {
            // goodbye pet, check pet journal/log
        }
        void eat() {
            
        }
        void action() {

        }
};

class Cat : public Pet { 
    private: 

    public: 
        Cat(){
            cout << "What is you cat's name: " << ends;
            string n;
            getline(cin,n);
            Pet::setName(n);

            Pet::setHunger(80);
            Pet::setMood(80);
        }
        ~Cat() {
            // goodbye pet, check pet journal/log
        }
        void eat() {
            
        }
        void action() {
            
        }
};

class Eagle : public Pet { 
    private: 

    public: 
        Eagle() {
            cout << "Your Eagle's name is Ernie.";
            Pet::setName("Eagle");
            Pet::setHunger(80);
            Pet::setMood(80);
        }
        ~Eagle() {
            // goodbye pet, check pet journal/log
        }
        void eat() {

        }
        void action() {
            
        }
};

int main() {

    return 0;
}

