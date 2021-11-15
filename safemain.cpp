#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

void retrieveArt(string);
string lowercase(string);
string decideMood(int);

// abstract base class
class Pet { 
    friend ostream& operator<<(ostream &os, const Pet&);
    private:
        int hunger = 0;
        int mood = 0;
        string name;
    public: 
        // pure virtual functions
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
            cout<<"Goodbye! Check your pet journal "<<Pet::getName()<<"_the_dog.txt!"<<endl;
        }
        void eat(ofstream &fout) {
            string food;
            cout<<"Which food for "<<Pet::getName()<<"?"<<" Water or Bone? ";
            getline(cin,food);
            food = lowercase(food);
            if (food=="water") {
                retrieveArt("eatWaterDog");
                Pet::setHunger(10);
                fout<<Pet::getName()<<" drank water."<<endl;
                fout<<"Hunger is now "<<Pet::getHunger()<<"/100 \n"<<endl;
            }
            else if (food=="bone") {
                retrieveArt("eatBoneDog");
                Pet::setHunger(15);
                fout<<Pet::getName()<<" ate a bone."<<endl;
                fout<<"Hunger is now "<<Pet::getHunger()<<"/100 \n"<<endl;
            }
            else {
                string errMsg = "Sorry, that food choice doesn't exist.";
                throw errMsg;
            }
        }
        void action(ofstream &fout) {
            string act;
            cout<<"Which action for "<<Pet::getName()<<"?"<<" Speak or Ball? ";
            
            getline(cin,act);
            act = lowercase(act);
            if (act=="speak") {
                retrieveArt("actionSpeakDog");
                Pet::setMood(-1);
                fout<<Pet::getName()<<" barked!"<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else if (act=="ball") {
                retrieveArt("actionBallDog");
                Pet::setMood(20);
                fout<<Pet::getName()<<" played fetch."<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else {
                string errMsg = "Sorry, that action choice doesn't exist.";
                throw errMsg;
            }
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
            cout<<"Goodbye! Check your pet journal "<<Pet::getName()<<"_the_cat.txt!"<<endl;
        }
        void eat(ofstream &fout) {
            string food;
            cout<<"Which food for "<<Pet::getName()<<"?"<<" Milk or Fish? ";
            getline(cin,food);
            food = lowercase(food);
            if (food=="milk") {
                retrieveArt("eatMilkCat");
                Pet::setHunger(15);
                fout<<Pet::getName()<<" drank milk."<<endl;
                fout<<"Hunger is now "<<Pet::getHunger()<<"/100 \n"<<endl;
            }
            else if (food=="fish") {
                retrieveArt("eatFishCat");
                Pet::setHunger(20);
                fout<<Pet::getName()<<" ate a fish."<<endl;
                fout<<"Hunger is now "<<Pet::getHunger()<<"/100 \n"<<endl;
            }
            else {
                string errMsg = "Sorry, that food choice doesn't exist.";
                throw errMsg;
            }
        }
        void action(ofstream &fout) {
            string act;
            cout<<"Which action for "<<Pet::getName()<<"?"<<" Speak, Ball, Toy or Box? ";
            
            getline(cin,act);
            act = lowercase(act);
            if (act=="speak") {
                retrieveArt("actionSpeakCat");
                Pet::setMood(-5);
                fout<<Pet::getName()<<" meowed!"<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else if (act=="ball") {
                retrieveArt("actionBallCat");
                Pet::setMood(-1);
                fout<<Pet::getName()<<" played with ball."<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else if (act=="toy") {
                retrieveArt("actionToyCat");
                Pet::setMood(10);
                fout<<Pet::getName()<<" played with feather toy."<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else if (act=="box") {
                retrieveArt("actionBoxCat");
                Pet::setMood(20);
                fout<<Pet::getName()<<" played with box."<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else {
                string errMsg = "Sorry, that action choice doesn't exist.";
                throw errMsg;
            }
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
            cout<<"Goodbye! Check your pet journal Ernie_the_eagle.txt!"<<endl;
        }
        void eat(ofstream &fout) {
            string food;
            cout<<"Which food for "<<Pet::getName()<<"?"<<" Water or Fish? ";
            getline(cin,food);
            food = lowercase(food);
            if (food=="water") {
                retrieveArt("eatWaterEagle");
                Pet::setHunger(15);
                fout<<Pet::getName()<<" drank water."<<endl;
                fout<<"Hunger is now "<<Pet::getHunger()<<"/100 \n"<<endl;
            }
            else if (food=="fish") {
                retrieveArt("eatFishEagle");
                Pet::setHunger(20);
                fout<<Pet::getName()<<" caught and ate a fish."<<endl;
                fout<<"Hunger is now "<<Pet::getHunger()<<"/100 \n"<<endl;
            }
            else {
                string errMsg = "Sorry, that food choice doesn't exist.";
                throw errMsg;
            }
        }
        void action(ofstream &fout) {
            string act;
            cout<<"Which action for "<<Pet::getName()<<"?"<<" Speak, Flap or Ball? ";
            
            getline(cin,act);
            act = lowercase(act);
            if (act=="speak") {
                retrieveArt("actionSpeakEagle");
                Pet::setMood(5);
                fout<<Pet::getName()<<" cawed!"<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else if (act=="flap") {
                retrieveArt("actionFlapEagle");
                Pet::setMood(0);
                fout<<Pet::getName()<<" flapped its wings."<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else if (act=="ball") {
                retrieveArt("actionBallEagle");
                Pet::setMood(-1);
                fout<<Pet::getName()<<" played with a ball."<<endl;
                fout<<"Mood is now "<<Pet::getMood()<<"/100. "<<decideMood(Pet::getMood())<<"\n"<<endl;
            }
            else {
                string errMsg = "Sorry, that action choice doesn't exist.";
                throw errMsg;
            }
        }
};

string lowercase(string s) {
    std::for_each(s.begin(), s.end(), [](char & c){
        c = tolower(c);
    });
    return s;
}

string decideMood(int m) {
    if (m <= 100 && m >= 90) {
        return "Excited";
    } else if (m <= 89 && m >= 80) {
        return "Happy";
    } else if (m <= 79 && m >= 70) {
        return "Calm";
    } else if (m <= 69 && m >= 60) {
        return "Lonely";
    } else {
        return "Depressed";
    }
}

ostream& operator<<(ostream &os, const Pet &p){
    os<<"\n***************************"<<endl;
    os<<"Pet's Name: "<<p.name<<endl;
    os<<"Mood: "<<decideMood(p.mood)<<endl;
    os<<"Hunger: "<<p.hunger<<"/100"<<endl;
    os<<"***************************\n"<<endl;
    return os;
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
    bool exit = false;
    Dog p;

    string logFile = p.getName() + "_the_dog.txt";
    ofstream fout(logFile);     
    fout<<"********PET JOURNAL********"<<endl;
    fout<<"Pet name: "<<p.getName()<<endl;
    fout<<p;

    string choice;
    while (exit == false) { 
        cout<<"What would you like to do with "<<p.getName()<<"? Feed, Interact, Check Stats, or Exit? ";
        getline(cin,choice);
        choice = lowercase(choice);
        if (choice=="feed") {
            try {
                p.eat(fout);
            } 
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (choice=="interact") {
            try {
                p.action(fout);
            } 
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (choice == "check stats") {
            cout<<p;
        }
        else if (choice == "exit"){
            exit = true;
        }
        else {
            string errMsg = "Not a valid choice.";
            throw errMsg;
        }
        cin.clear();
    }

    fout<<p;
    fout.close(); 

}

void branchCat() {
    bool exit = false;
    Cat p;

    string logFile = p.getName() + "_the_cat.txt";
    ofstream fout(logFile);     
    fout<<"********PET JOURNAL********"<<endl;
    fout<<"Pet name: "<<p.getName()<<endl;
    fout<<p;

    string choice;
    while (exit == false){
        cout<<"What would you like to do with "<<p.getName()<<"? Feed, Interact, Check Stats, or Exit? ";
        getline(cin,choice);
        choice = lowercase(choice);
        if (choice=="feed") {
            try {
                p.eat(fout);
            } 
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (choice=="interact") {
            try {
                p.action(fout);
            } 
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (choice == "check stats") {
            cout<<p;
        }
        else if (choice == "exit"){
                exit = true;
        }
        else {
            string errMsg = "Not a valid choice.";
            throw errMsg;
        }
        cin.clear();
    }
    fout<<p;
    fout.close(); 
}

void branchEagle() {
    bool exit = false;
    Eagle p;

    string logFile = "Ernie_the_eagle.txt";
    ofstream fout(logFile);     
    fout<<"********PET JOURNAL********"<<endl;
    fout<<"Pet name: Ernie"<<endl;
    fout<<p;

    string choice;
    while (exit == false){
        cout<<"What would you like to do with "<<p.getName()<<"? Feed, Interact, Check Stats, or Exit? ";
        getline(cin,choice);
        choice = lowercase(choice);
        if (choice=="feed") {
            try {
                p.eat(fout);
            } 
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (choice =="interact") {
            try {
                p.action(fout);
            } 
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (choice == "check stats") {
            cout<<p;
        }
        else if (choice == "exit"){
                exit = true;
            }
        else {
            string errMsg = "Not a valid choice.";
            throw errMsg;
        }
        cin.clear();
    }
    fout<<p;
    fout.close(); 
}

int main() {
    bool exit = false;
    string pet, cont;
    cout<<"What pet would you like? Dog, Cat or Eagle? ";
    getline(cin,pet);

    while (exit == false){
        pet = lowercase(pet);
        if (pet=="dog") {
            try {
                branchDog();
            }
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
            
        }
        else if (pet=="cat") {
            try {
                branchCat();
            }
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else if (pet=="eagle") {
            try {
                branchEagle();
            }
            catch (string errMsg) {
                cout<<errMsg<<endl;
            }
        }
        else {
            cout<<"Oops, that is not a valid pet. Try again."<<endl;
            cout<<"What pet would you like? Dog, Cat or Eagle? ";
            getline(cin,pet);
            continue;
        }

        cout<<"Would you like another pet? Yes or No? "<<ends;
        getline(cin,cont);
        cont = lowercase(cont);
        if (cont == "yes") {
            cout<<"What pet would you like? Dog, Cat or Eagle? "<<ends;
            getline(cin,pet);
        }
        else if (cont == "no") {
            exit = true;
        }
        else {
            string errMsg = "Not a valid choice.";
            throw errMsg;
        }
    }
    return 0;
}