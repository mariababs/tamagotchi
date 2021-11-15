#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
//#include "Cat.h"
#include "Pet.h"
#include "functions.h"

using namespace std;

Cat::Cat(){
    cout << "What is you cat's name: " << ends;
    string n;
    getline(cin,n);
    Pet::setName(n);
    retrieveArt("petCat");
    Pet::setHunger(80);
    Pet::setMood(80);
}
Cat::~Cat() {
    cout<<"Goodbye! Check your pet journal "<<Pet::getName()<<"_the_cat.txt!"<<endl;
}
void Cat::eat(ofstream &fout) {
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

void Cat::action(ofstream &fout) {
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