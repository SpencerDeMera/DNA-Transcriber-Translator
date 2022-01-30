#ifndef AMINOS_HPP
#define AMINOS_HPP

#include <iostream>
#include <string>
using namespace std;

class AminoAcid {
    private:
        char abrev;
        char cat;
        string name;
        int value;

    public:
        AminoAcid(char, char, string);
        char getAbrev();
        char getCat();
        string getName();
        void setValue(int);
        int getValue();
};

AminoAcid::AminoAcid(char a, char c, string n) {
    abrev = a;
    cat = c;
    name = n;
}

char AminoAcid::getAbrev() { return abrev; }

char AminoAcid::getCat() { return cat; }

string AminoAcid::getName() { return name; }

void AminoAcid::setValue(int v) { value = v; }

int AminoAcid::getValue() { return value; }

#endif