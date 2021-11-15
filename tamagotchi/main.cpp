#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Dog.h"
#include "Cat.h"
#include "Eagle.h"
#include "functions.h"

using namespace std;

void branchDog();
void branchCat();
void branchEagle();

int main() {
    // promp user for pet type
    bool exit = false;
    string pet, cont;
    cout<<"What pet would you like? Dog, Cat or Eagle? ";
    getline(cin,pet);
    while (exit==false){
        // Choose branch based on user input of pet type
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

        // Prompt user if they would like another pet
        cout<<"Would you like another pet? Yes or No? "<<ends;
        getline(cin,cont);
        cont = lowercase(cont);
        if (cont=="yes") {
            cout<<"What pet would you like? Dog, Cat or Eagle? "<<ends;
            getline(cin,pet);
        }
        else if (cont=="no") {
            exit = true;
        }
        else {
            string errMsg = "Not a valid choice.";
            throw errMsg;
        }
    }
    return 0;
}

void branchDog() {
    /*
    branchDog starts the pet loop process if a Dog pet has been selected.
    It asks if the user would like to feed or interact with their pet, then loops these two options until exit.
    */
    bool exit = false;
    Dog p;

    // start pet journal
    string logFile = p.getName() + "_the_dog.txt";
    ofstream fout(logFile);     
    fout<<"********PET JOURNAL********"<<endl;
    fout<<"Pet name: "<<p.getName()<<endl;
    fout<<p;

    // select action
    string choice;
    while (exit==false) { 
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
    /*
    branchCat starts the pet loop process if a Cat pet has been selected.
    It asks if the user would like to feed or interact with their pet, then loops these two options until exit.
    */
    bool exit = false;
    Cat p;

    // start pet journal
    string logFile = p.getName() + "_the_cat.txt";
    ofstream fout(logFile);     
    fout<<"********PET JOURNAL********"<<endl;
    fout<<"Pet name: "<<p.getName()<<endl;
    fout<<p;

    // select action
    string choice;
    while (exit==false){
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
        else if (choice=="check stats") {
            cout<<p;
        }
        else if (choice=="exit"){
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
    /*
    branchEagle starts the pet loop process if a Eagle pet has been selected.
    It asks if the user would like to feed or interact with their pet, then loops these two options until exit.
    */
    bool exit = false;
    Eagle p;

    // start pet journal
    string logFile = "Ernie_the_eagle.txt";
    ofstream fout(logFile);     
    fout<<"********PET JOURNAL********"<<endl;
    fout<<"Pet name: Ernie"<<endl;
    fout<<p;

    // select action
    string choice;
    while (exit==false){
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
        else if (choice=="check stats") {
            cout<<p;
        }
        else if (choice=="exit"){
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