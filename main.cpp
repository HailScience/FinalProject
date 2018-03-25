#include <iostream>
#include <string>
#include "game.hpp"


using std::string;
using std::cout;
using std::endl;

void instructions()
{
    cout << "Welcome, Detective." << endl;
    cout << "You have just been called to the crime scene of a murder.\n";
    cout << "It is your job to solve the murder, ";
    cout << " and in order to do this, you must find all the clues.\n";
    cout << "There are six phases of the investigation: " << endl;
    cout << "Searching the crime scene\n";
    cout << "Questioning the witnesses\n";
    cout << "Performing an autopsy\n";
    cout << "Testing the evidence\n";
    cout << "Identifying a suspect\n";
    cout << "Interrogating the suspect\n";
    cout << endl;
    cout << "Good luck. We're counting on you." << endl;
    cout << endl;
}

int main()
{
    //Initialize Game object
    Game game;

    //Start setup
    game.setup();

    //Print instructions
    instructions();

    game.play();

    game.endGame();

    return 0;
}