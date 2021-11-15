#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Dog.h"
#include "functions.h"

using namespace std;

Dog::Dog(){
    /*
    The constructor Dog function asks for the Dog's name and sets the private name field. 
    It also retrieves the base Dog art and sets initial hunger and mood values.
    */
    cout << "What is you dog's name: " << ends;
    string n;
    getline(cin,n);
    Pet::setName(n);
    retrieveArt("petDog");
    Pet::setHunger(80);
    Pet::setMood(80);
}
Dog::~Dog() {
    /*
    The destructor Dog function says goodbye to the pet and asks the user to check the pet log.
    */
    cout<<"Goodbye! Check your pet journal "<<Pet::getName()<<"_the_dog.txt!"<<endl;
}
void Dog::eat(ofstream &fout) {
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
void Dog::action(ofstream &fout) {
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