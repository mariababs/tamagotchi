#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// abstract base class
class Pet { 
    private:
        int hunger;
        int mood;
    public: 
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
};

class Dog : public Pet { 
    private: 

    public: 

};

class Cat : public Pet { 
    private: 

    public: 
    
};

class Eagle : public Pet { 
    private: 

    public: 

};

int main() {

    return 0;
}