#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<algorithm>

using namespace std;

void retrieveArt(string);
string lowercase(string);
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
            retrieveArt("petDog");
            Pet::setHunger(80);
            Pet::setMood(80);
        }
        ~Dog() {
            // goodbye pet, check pet journal/log
        }
        void eat() {
            string food;
            cout<<"Which food for "<<Pet::getName()<<"?"<<" Water or Bone? ";
            
            getline(cin,food);
            food = lowercase(food);
            if (food=="water") {
                retrieveArt("eatWaterDog");
                Pet::setHunger(10);
            }
            else if (food=="bone") {
                retrieveArt("eatBoneDog");
                Pet::setHunger(15);
            }
            else {
                string errMsg = "Sorry, that food choice doesn't exist.";
                throw errMsg;
            }
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
            retrieveArt("petCat");
            Pet::setHunger(80);
            Pet::setMood(80);
        }
        ~Cat() {
            // goodbye pet, check pet journal/log
        }
        void eat() {
            string food;
            cout<<"Which food for "<<Pet::getName()<<"?"<<" Milk or Fish? ";
            getline(cin,food);
            food = lowercase(food);
            if (food=="milk") {
                retrieveArt("eatMilkCat");
                Pet::setHunger(15);
            }
            else if (food=="fish") {
                retrieveArt("eatFishCat");
                Pet::setHunger(20);
            }
            else {
                string errMsg = "Sorry, that food choice doesn't exist.";
                throw errMsg;
            }
        }
        void action() {
            
        }
};

class Eagle : public Pet { 
    private: 
        
    public: 
        Eagle() {
            cout << "Your Eagle's name is Ernie." << endl;
            Pet::setName("Eagle");
            retrieveArt("petEagle");
            Pet::setHunger(80);
            Pet::setMood(80);
        }
        ~Eagle() {
            // goodbye pet, check pet journal/log
        }
        void eat() {
            string food;
            cout<<"Which food for "<<Pet::getName()<<"?"<<" Water or Fish? ";
            getline(cin,food);
            food = lowercase(food);
            if (food=="water") {
                retrieveArt("eatWaterEagle");
                Pet::setHunger(15);
            }
            else if (food=="fish") {
                retrieveArt("eatFishEagle");
                Pet::setHunger(20);
            }
            else {
                string errMsg = "Sorry, that food choice doesn't exist.";
                throw errMsg;
            }
        }
        void action() {
            
        }
};

string lowercase(string s) {
    std::for_each(s.begin(), s.end(), [](char & c){
        c = tolower(c);
    });
    return s;
}

void retrieveArt(string findArt) {
    char newArt = '*';
    ifstream fin("Ascii Art.txt");
    string line;
    while (getline(fin,line)) {
        if (line[0]==newArt) {
            if (line.find(newArt+findArt)!=string::npos) {
                int keepPrinting = 1;
                while (keepPrinting) {
                    getline(fin,line);
                    if (line[0]!=newArt)
                        cout<<line<<endl;
                    else
                        keepPrinting = 0;
                    
                }
            }
        }
    }
}

void branchDog() {
    Dog p;
    string choice;
    cout<<"What would you like to do with "<<p.getName()<<"? Feed or Interact? ";
    getline(cin,choice);
    choice = lowercase(choice);
    if (choice=="feed") {
        p.eat();
    }
    else if (choice=="interact") {
        
    }
    else {
        string errMsg = "Not a valid choice.";
        throw errMsg;
    }
    
}

void branchCat() {
    Cat p;
    string choice;
    cout<<"What would you like to do with "<<p.getName()<<"? Feed or Interact? ";
    getline(cin,choice);
    choice = lowercase(choice);
    if (choice=="feed") {
        p.eat();
    }
    else if (choice=="interact") {
        
    }
    else {
        string errMsg = "Not a valid choice.";
        throw errMsg;
    }
}

void branchEagle() {
    Eagle p;
    string choice;
    cout<<"What would you like to do with "<<p.getName()<<"? Feed or Interact? ";
    getline(cin,choice);
    choice = lowercase(choice);
    if (choice=="feed") {
        p.eat();
    }
    else if (choice=="interact") {
        
    }
    else {
        string errMsg = "Not a valid choice.";
        throw errMsg;
    }
}

int main() {
    string pet;
    cout<<"What pet would you like? Dog, Cat or Eagle? ";
    getline(cin,pet);
    pet = lowercase(pet);
    if (pet=="dog") {
        branchDog();
    }
    else if (pet=="cat") {
        branchCat();
    }
    else if (pet=="eagle") {
        branchEagle();
    }
    else {
        cout<<"Oops, that is not a valid pet. Try again."<<endl;
    }
    
    return 0;
}
