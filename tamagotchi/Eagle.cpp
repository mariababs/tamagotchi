#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Eagle.h"
#include "functions.h"

using namespace std;

Eagle::Eagle() {
    cout << "Your Eagle's name is Ernie." << endl;
    Pet::setName("Eagle");
    retrieveArt("petEagle");
    Pet::setHunger(80);
    Pet::setMood(80);
}
Eagle::~Eagle() {
    cout<<"Goodbye! Check your pet journal Ernie_the_eagle.txt!"<<endl;
}
void Eagle::eat(ofstream &fout) {
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
void Eagle::action(ofstream &fout) {
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