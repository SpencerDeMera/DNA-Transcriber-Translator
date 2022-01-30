#include <iostream>
#include <iomanip>
#include <limits>
#include "translator.hpp"
#include "colors.h"
using namespace std;

// Example Strand: 
// TCCATTCCATGATAATGGCCGGGATTAACGAGCCCGAAGCTTGTGAATAACGGTCA

void header();
void menu();

int main() {
    // Functions
    header();

    // Variables
    Translator T;
    int userChoice = 0;
    bool strandFlag = false;
    bool transcribFlag = false;
    
    do {
        menu();
        cout << GREEN;
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << RESET << endl;

        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores return char

        if (userChoice < 1 || userChoice > 10) {
            cout << RED << "ERROR: Input must be between 1 and 10. Please Try Again.\n\n" << RESET;
            userChoice = 0;
        }

        switch (userChoice) {
            case 1:
                // Input DNA: input DNA strand for use
                T.inputDNA();
                strandFlag = true;
                break;
            case 2:
                // DNA complement: get complement of input DNA strand
                if (strandFlag) {
                    T.DNAcomplement();
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet.\n\n" << RESET;
                }
                break;
            case 3:
                // DNA reverse: get the strand but reversed
                if (strandFlag) {
                    T.DNAreverse();
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet.\n\n" << RESET;
                }
                break;
            case 4:
                // DNA transcribe: transcribe DNA to RNA
                if (strandFlag) {
                    T.DNAtranscribe();
                    transcribFlag = true;
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet.\n\n" << RESET;
                }
                break;
            case 5:
                // RNA complement: get complement of transcribed RNA strand
                if (strandFlag && transcribFlag) {
                    T.RNAcomplement();
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet OR DNA strand has not been transcribed.\n\n" << RESET;
                }
                break;
            case 6:
                // RNA reverse: get the transcribed RNA strand but reversed
                if (strandFlag && transcribFlag) {
                    T.RNAreverse();
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet OR DNA strand has not been transcribed.\n\n" << RESET;
                }
                break;
            case 7:
                // DNA translate: translate directly from DNA to protein (transcribes to RNA in background)
                if (strandFlag) {
                    T.DNAtranslate();
                    transcribFlag = true;
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet.\n\n" << RESET;
                }
                break;
            case 8:
                // RNA translate: translates RNA, if transcribed from DNA, to protein
                if (strandFlag && transcribFlag) {
                    T.RNAtranslate();
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet OR DNA strand has not been transcribed.\n\n" << RESET;
                }
                break;
            case 9:
                // Amino Acids: lists amino acids & # of each used in translated protein strand
                if (strandFlag && transcribFlag) {
                    T.aminoAcids();
                } else {
                    cout << RED << "ERROR: No DNA strand has been input yet OR DNA strand has not been transcribed.\n\n" << RESET;
                }
                break;
            case 10:
                // Exit: exit program
                cout << CYAN << "You have chosen to exit the program.\n\n" << RESET;
                break;
            case 0:
                // Invaid input, restart loop
                break;
        }
    } while (userChoice != 10);

    cout << BOLDRED << "Program Terminating...\n\n" << RESET;
    return 0;
}

void header() {
    // function to print introduction
    cout << BOLDCYAN;
    cout << "\n";
    cout << setfill('=') << setw(58) << "=" << endl;
    cout << "------------  DNA Sequence Translator System  ------------\n";
    cout << setfill('=') << setw(58) << "=" << endl;
    cout << RESET << "\n" << CYAN;
    cout << setfill('-') << setw(59) << "-" << endl;
    cout << "This system is used to translate DNA to RNA and RNA to\n" <<
    setfill(' ') << setw(3) << ' ' <<
    "polymers of amino acids (proteins). Complementary and\n" <<
    setfill(' ') << setw(3) << ' ' <<
    "reverse strands of both DNA and RNA can also be deduced.\n";
    cout << setfill('-') << setw(59) << "-" << endl << endl;
    cout << RESET;
}

void menu() {
    // function for menu system display

    // Options
    // DNA input: input DNA strand for use
    // DNA complement: get complement of input DNA strand
    // DNA reverse: get the strand but reversed
    // DNA transcribe: transcribe DNA to RNA
    // RNA complement: get complement of transcribed RNA strand
    // RNA reverse: get the transcribed RNA strand but reversed
    // DNA translate: translate directly from DNA to protein (transcribes to RNA in background)
    // RNA translate: translates RNA, if transcribed from DNA, to protein
    // Amino Acids: lists amino acids & # of each used in translated protein strand
    // Exit: exit program

    cout << BOLDGREEN << setfill('*') << setw(24) << "*" << "  M E N U  " << setfill('*') << setw(24) << "*" << RESET << endl;
    cout << GREEN;
    cout << setfill(' ') << setw(22) << "[1]: Input DNA";
    cout << setfill(' ') << setw(30) << "[2]: DNA Complement\n"; 
    cout << setfill(' ') << setw(24) << "[3]: DNA Reverse";
    cout << setfill(' ') << setw(28) << "[4]: DNA Transcribe\n"; 
    cout << setfill(' ') << setw(27) << "[5]: RNA Complement";
    cout << setfill(' ') << setw(22) << "[6]: RNA Reverse\n"; 
    cout << setfill(' ') << setw(26) << "[7]: DNA Translate";
    cout << setfill(' ') << setw(25) << "[8]: RNA Translate\n"; 
    cout << setfill(' ') << setw(24) << "[9]: Amino Acids";
    cout << setfill(' ') << setw(19) << "[10]: Exit\n"; 
    cout << RESET;
    cout << BOLDGREEN << setfill('*') << setw(60) << "*" << RESET << endl;
}
