#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "functions.h"
#include "Pet.h"
using namespace std;

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