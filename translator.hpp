#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "colors.h"
#include "aminos.hpp"
using namespace std;

class Translator {
    private:
        // initialized / required variables
        map<string, char> AAs;
        vector<AminoAcid> amino;

        vector<char> initDNAStrandBuffer;
        vector<char> DNAcompStrandBuffer;
        vector<char> DNArevStrandBuffer;
        vector<char> initRNAStrandBuffer;
        vector<char> RNAcompStrandBuffer;
        vector<char> RNArevStrandBuffer;
        vector<char> proteinPolymerBuffer;

        string DNAStrand;
        int DNAStrandLength;
        int polymerLength;

    public:
        Translator();
        void inputDNA();
        void DNAcomplement();
        void DNAreverse();
        void DNAtranscribe();
        void RNAcomplement();
        void RNAreverse();
        void DNAtranslate();
        void RNAtranslate();
        void aminoAcids();
};

Translator::Translator() {
    // START codon
    // - AUG
    // STOP codons
    // - UAA, UAG, UGA
    AAs["UUU"] = 'F';
    AAs["UUC"] = 'F';
    AAs["UUA"] = 'L';
    AAs["UUG"] = 'L';
    AAs["CUU"] = 'L';
    AAs["CUC"] = 'L';
    AAs["CUA"] = 'L';
    AAs["CUG"] = 'L';
    AAs["AUU"] = 'I';
    AAs["AUC"] = 'I';
    AAs["AUA"] = 'I';
    AAs["AUG"] = 'M';
    AAs["GUU"] = 'V';
    AAs["GUC"] = 'V';
    AAs["GUA"] = 'V';
    AAs["GUG"] = 'V';
    AAs["UCU"] = 'S';
    AAs["UCC"] = 'S';
    AAs["UCA"] = 'S';
    AAs["UCG"] = 'S';
    AAs["CCU"] = 'P';
    AAs["CCC"] = 'P';
    AAs["CCA"] = 'P';
    AAs["CCG"] = 'P';
    AAs["ACU"] = 'T';
    AAs["ACC"] = 'T';
    AAs["ACA"] = 'T';
    AAs["ACG"] = 'T';
    AAs["GCU"] = 'A';
    AAs["GCC"] = 'A';
    AAs["GCA"] = 'A';
    AAs["GCG"] = 'A';
    AAs["UAU"] = 'Y';
    AAs["UAC"] = 'Y';
    AAs["CAU"] = 'H';
    AAs["CAC"] = 'H';
    AAs["CAA"] = 'Q';
    AAs["CAG"] = 'Q';
    AAs["AAU"] = 'N';
    AAs["AAC"] = 'N';
    AAs["AAA"] = 'K';
    AAs["AAG"] = 'K';
    AAs["GAU"] = 'D';
    AAs["GAC"] = 'D';
    AAs["GAA"] = 'E';
    AAs["GAG"] = 'E';
    AAs["UGU"] = 'C';
    AAs["UGC"] = 'C';
    AAs["UGG"] = 'W';
    AAs["CGU"] = 'R';
    AAs["CGC"] = 'R';
    AAs["CGA"] = 'R';
    AAs["CGG"] = 'R';
    AAs["AGU"] = 'S';
    AAs["AGC"] = 'S';
    AAs["AGA"] = 'R';
    AAs["AGG"] = 'R';
    AAs["GGU"] = 'G';
    AAs["GGC"] = 'G';
    AAs["GGA"] = 'G';
    AAs["GGG"] = 'G';

    AminoAcid d('D', 'a', "Aspartate");
    amino.push_back(d);
    AminoAcid e('E', 'a', "Glutamate");
    amino.push_back(e);
    AminoAcid k('K', 'b', "Lysine");
    amino.push_back(k);
    AminoAcid r('R', 'b', "Arginine");
    amino.push_back(r);
    AminoAcid h('H', 'b', "Histidine");
    amino.push_back(h);
    AminoAcid s('S', 'p', "Serine");
    amino.push_back(s);
    AminoAcid t('T', 'p', "Threonine");
    amino.push_back(t);
    AminoAcid y('Y', 'p', "Tyrosine");
    amino.push_back(y);
    AminoAcid n('N', 'p', "Asparagine");
    amino.push_back(n);
    AminoAcid q('Q', 'v', "Glutamine");
    amino.push_back(q);
    AminoAcid g('G', 'n', "Glycine");
    amino.push_back(g);
    AminoAcid a('A', 'n', "Alanine");
    amino.push_back(a);
    AminoAcid v('V', 'n', "Valine");
    amino.push_back(v);
    AminoAcid l('L', 'n', "Leucine");
    amino.push_back(l);
    AminoAcid i('I', 'n', "Isoleucine");
    amino.push_back(i);
    AminoAcid m('M', 'n', "Methionine");
    amino.push_back(m);
    AminoAcid c('C', 'n', "Cysteine");
    amino.push_back(c);
    AminoAcid f('F', 'n', "Phenylalanine");
    amino.push_back(f);
    AminoAcid w('W', 'n', "Tryptophan");
    amino.push_back(w);
    AminoAcid p('P', 'n', "Proline");
    amino.push_back(p);
}

void Translator::inputDNA() {
    cout << "Enter a strand of DNA: ";
    getline(cin, DNAStrand);
    DNAStrandLength = (int)DNAStrand.length();

    for (int i = 0; i < DNAStrandLength; i++) {
        initDNAStrandBuffer.push_back(DNAStrand[i]);
    }

    // Prints out DNA strand input by user
    cout << "       - Input Strand: ";
    for (int i = 0; i < DNAStrandLength; i++) {
        cout << initDNAStrandBuffer[i];
    }
    cout << endl << endl;
}

void Translator::DNAcomplement() {
    // A = T
    // G = C

    for (int i = 0; i < DNAStrandLength; i++) {
        if (initDNAStrandBuffer[i] == 'A') {
            DNAcompStrandBuffer.push_back('T');
        } else if (initDNAStrandBuffer[i] == 'T') {
            DNAcompStrandBuffer.push_back('A');
        } else if (initDNAStrandBuffer[i] == 'G') {
            DNAcompStrandBuffer.push_back('C');
        } else if (initDNAStrandBuffer[i] == 'C') {
            DNAcompStrandBuffer.push_back('G');
        }
    }

    // Prints out complement DNA strand input by user
    cout << "       - Complement Strand: ";
    for (int i = 0; i < DNAStrandLength; i++) {
        cout << DNAcompStrandBuffer[i];
    }
    cout << endl << endl;
}

void Translator::DNAreverse() {
    for (int i = DNAStrandLength - 1; i >= 0; i--) {
        DNArevStrandBuffer.push_back(initDNAStrandBuffer[i]);
    }

    // Prints out reversed DNA strand input by user
    cout << "       - Reversed Strand: ";
    for (int i = 0; i < DNAStrandLength; i++) {
        cout << DNArevStrandBuffer[i];
    }
    cout << endl << endl;
}

void Translator::DNAtranscribe() {
    for (int i = 0; i < DNAStrandLength; i++) {
        if (initDNAStrandBuffer[i] == 'T') {
            initRNAStrandBuffer.push_back('U');
        } else {
            initRNAStrandBuffer.push_back(initDNAStrandBuffer[i]);
        }
    }

    // Prints out RNA strand transcribed from DNA
    cout << "       - Transcribed Strand: ";
    for (int i = 0; i < DNAStrandLength; i++) {
        cout << initRNAStrandBuffer[i];
    }
    cout << endl << endl;
}

void Translator::RNAcomplement() {
    // A = U
    // G = C

    for (int i = 0; i < DNAStrandLength; i++) {
        if (initRNAStrandBuffer[i] == 'A') {
            RNAcompStrandBuffer.push_back('U');
        } else if (initRNAStrandBuffer[i] == 'U') {
            RNAcompStrandBuffer.push_back('A');
        } else if (initRNAStrandBuffer[i] == 'G') {
            RNAcompStrandBuffer.push_back('C');
        } else if (initRNAStrandBuffer[i] == 'C') {
            RNAcompStrandBuffer.push_back('G');
        }
    }

    // Prints out complement RNA strand translated from DNA
    cout << "       - Complement Strand: ";
    for (int i = 0; i < DNAStrandLength; i++) {
        cout << RNAcompStrandBuffer[i];
    }
    cout << endl << endl;
}

void Translator::RNAreverse() {
    for (int i = DNAStrandLength - 1; i >= 0; i--) {
        RNArevStrandBuffer.push_back(initRNAStrandBuffer[i]);
    }

    // Prints out reversed DNA strand input by user
    cout << "       - Reversed Strand: ";
    for (int i = 0; i < DNAStrandLength; i++) {
        cout << RNArevStrandBuffer[i];
    }
    cout << endl << endl;
}

void Translator::DNAtranslate() {
    // Transcribe DNA -> RNA
    for (int i = 0; i < DNAStrandLength; i++) {
        if (initDNAStrandBuffer[i] == 'T') {
            initRNAStrandBuffer.push_back('U');
        } else {
            initRNAStrandBuffer.push_back(initDNAStrandBuffer[i]);
        }
    }

    // Translate RNA -> Proteins
    int startIndex = 0;
    for (int i = 0; i < DNAStrandLength; i++) {
        // If start codon detected
        if (initRNAStrandBuffer[i] == 'A' && initRNAStrandBuffer[i+1] == 'U' && initRNAStrandBuffer[i+2] == 'G') {
            startIndex = i + 3;
            break;
        }
    }

    for (int i = startIndex; i < DNAStrandLength; i++) {
        // While no stop codon is next
        if ((initRNAStrandBuffer[i] == 'U' && initRNAStrandBuffer[i+1] == 'A' && initRNAStrandBuffer[i+2] == 'A') || 
        (initRNAStrandBuffer[i] == 'U' && initRNAStrandBuffer[i+1] == 'A' && initRNAStrandBuffer[i+2] == 'G') || 
        (initRNAStrandBuffer[i] == 'U' && initRNAStrandBuffer[i+1] == 'G' && initRNAStrandBuffer[i+2] == 'A')) {
            break;
        } else {
            string tempBuffer;

            tempBuffer += initRNAStrandBuffer[i];
            tempBuffer += initRNAStrandBuffer[i+1];
            tempBuffer += initRNAStrandBuffer[i+2];

            char tempAA = AAs[tempBuffer]; // gets amino acid value of codon

            proteinPolymerBuffer.push_back(tempAA); 
            polymerLength++; // inc length of polymer
        }
        i += 2;
    }

    // Prints out translated protein strand
    cout << "       - Protein Strand: ";
    for (int i = 0; i < polymerLength; i++) {
        cout << proteinPolymerBuffer[i];
    }
    cout << endl << endl;
}

void Translator::RNAtranslate() {
    // Translate RNA -> Proteins
    proteinPolymerBuffer.clear(); // clears the buffer if data already exists in it

    int startIndex = 0;
    for (int i = 0; i < DNAStrandLength; i++) {
        // If start codon detected
        if (initRNAStrandBuffer[i] == 'A' && initRNAStrandBuffer[i+1] == 'U' && initRNAStrandBuffer[i+2] == 'G') {
            startIndex = i + 3;
            break;
        }
    }

    for (int i = startIndex; i < DNAStrandLength; i++) {
        // While no stop codon is next
        if ((initRNAStrandBuffer[i] == 'U' && initRNAStrandBuffer[i+1] == 'A' && initRNAStrandBuffer[i+2] == 'A') || 
        (initRNAStrandBuffer[i] == 'U' && initRNAStrandBuffer[i+1] == 'A' && initRNAStrandBuffer[i+2] == 'G') || 
        (initRNAStrandBuffer[i] == 'U' && initRNAStrandBuffer[i+1] == 'G' && initRNAStrandBuffer[i+2] == 'A')) {
            break;
        } else {
            string tempBuffer;

            tempBuffer += initRNAStrandBuffer[i];
            tempBuffer += initRNAStrandBuffer[i+1];
            tempBuffer += initRNAStrandBuffer[i+2];

            char tempAA = AAs[tempBuffer]; // gets amino acid value of codon

            proteinPolymerBuffer.push_back(tempAA); 
            polymerLength++; // inc length of polymer
        }
        i += 2;
    }

    // Prints out translated protein strand
    cout << "       - Protein Strand: ";
    for (int i = 0; i < polymerLength; i++) {
        cout << proteinPolymerBuffer[i];
    }
    cout << endl << endl;
}

void Translator::aminoAcids() {
    // Creates temporary vectors
    vector<char> proteinPolymerBufferAlt;
    vector<int> acidCtr;
    vector<char> acidAbrev;

    // Sort chars of vector
    sort(proteinPolymerBuffer.begin(), proteinPolymerBuffer.end());

    // Copy proteinPolymerBuffer to proteinPolymerBufferAlt
    for (int i = 0; i < polymerLength; i++) {
        proteinPolymerBufferAlt.push_back(proteinPolymerBuffer[i]);
    }

    // Remove duplicate elements and resize vector
    vector<char>::iterator ip;
    ip = unique(proteinPolymerBufferAlt.begin(), proteinPolymerBufferAlt.begin() + polymerLength);
    proteinPolymerBufferAlt.resize(distance(proteinPolymerBufferAlt.begin(), ip));

    // Gets count of each element in proteinPolymerBuffer
    for (int i = 0; i < polymerLength; i++) {
        int size = 0;
        if (proteinPolymerBuffer[i] != proteinPolymerBuffer[i + 1]) {
            size = count(proteinPolymerBuffer.begin(), proteinPolymerBuffer.end(), proteinPolymerBuffer[i]);
            acidCtr.push_back(size);
        }
    }

    // Add instance of each acid to vector acidAbrev
    for (int i = 0; i < proteinPolymerBufferAlt.size(); i++) {
        acidAbrev.push_back(proteinPolymerBufferAlt[i]);
    }

    // Print area
    for (int i = 0; i < proteinPolymerBufferAlt.size(); i++) {
        for (int j = 0; j < 20; j++) {
            if (amino[j].getAbrev() == acidAbrev[i]) {
                cout << YELLOW;
                cout << "*" << setfill(' ') << setw(3) <<
                    acidCtr[i] << " -> " << amino[j].getAbrev() << " ( " << amino[j].getName() << " )\n";
            }
        }
    }
    cout << endl;
}

#endif