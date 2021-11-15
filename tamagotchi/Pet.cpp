#include "Pet.h"

void Pet::setHunger(int amount) { 
    hunger = hunger + amount;
    if (hunger>100) {
        hunger = 100;
    }
}

int Pet::getHunger() { 
    return hunger;
}

void Pet::setMood(int amount) { 
    mood = mood + amount;
    if (mood>100) { 
        mood = 100;
    }
}

int Pet::getMood() { 
    return mood;
}

void Pet::setName(string n) { 
    name = n;
}

string Pet::getName() { 
    return name;
}