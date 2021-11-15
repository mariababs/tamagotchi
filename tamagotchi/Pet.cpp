#include "Pet.h"

void Pet::setHunger(int amount) { 
    /*
    setHunger recieves the hunger update (+/- amount) and adjusts the overall hunger value.
    */
    hunger = hunger + amount;
    if (hunger>100) {
        hunger = 100;
    }
}

int Pet::getHunger() { 
    /*
    getHunger retrieves the hunger from the Pet class' private fields.
    */
    return hunger;
}

void Pet::setMood(int amount) { 
    /*
    setMood recieves the mood update (+/- amount) and adjusts the overall mood value.
    */
    mood = mood + amount;
    if (mood>100) { 
        mood = 100;
    }
}

int Pet::getMood() { 
    /*
    getMood retrieves the mood from the Pet class' private fields.
    */
    return mood;
}

void Pet::setName(string n) { 
    /*
    setName sets the Pet's private name field to n.
    */
    name = n;
}

string Pet::getName() { 
    /*
    getName retrieves the name from the Pet class' private fields.
    */
    return name;
}