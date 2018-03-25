#include <iostream>
#include <string>
#include "space.hpp"
#include "identify.hpp"
#include "testing.hpp"
#include "autopsy.hpp"
#include "clue.hpp"
#include "itemStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Identify::Identify(int position, char color) : Space(position, color)
{
    suspect = false;
}

void Identify::action()
{
    cout << "\tIdentify" << endl;
    cout << "----------------" << endl;

    cout << "Now, we must identify a suspect." << endl;
    cout << "Based on the hair we tested, we know that the killer uses\n";
    cout << "Rogaine and Propecia, which should show up black under a special infrared light.\n";
    cout << "Since we know the killer is a doctor, we're going to test doctors\n";
    cout << "that worked closely with the victim at the hospital." << endl;

    //Prompt to identify suspect
    int identification = menu(1);
    //While user identification is wrong
    while(identification == 1)
    {
        cout << "Good guess, but the red light should turn black";
        cout << " in the presence of Propecia." << endl;
        //Prompt again
        identification = menu(2);
    }
    //If identification is correct
    if(identification == 2)
    {
        cout << "Correct!" << endl;

        //Indicate clue was found
        suspect = true;
        cout << endl;
    }
}

int Identify::menu(int time)
{
    bool validInput = false;
    int choice;

    if(time == 1)
    {
        cout << endl;
        cout << "You test two doctors the victim knew who have gray or balding hair.\n";
        cout << "The doctors are Dr. Milligan, the victim's friend,\n";
        cout << "and Dr. Lipton, the victim's supervisor.\n" << endl;
        cout << "When the light shines on the first doctor, Dr. Milligan, the light is completely red.\n";
        cout << "When the light shines on the second doctor, Dr. Lipton, the light turns to black." << endl;

        cout << "Which doctor is the best suspect?" << endl;
        cout << "1. Dr. Milligan\n";
        cout << "2. Dr. Lipton\n";

        while(validInput == false)
        {
            cin >> choice;
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                choice = validateInput(choice, 1, 2);
                if(choice == 0)
                {
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validInput = true;
                }
            }
        }

        validInput = false;
        cout << endl;
        return choice;
    }
    else if(time == 2)
    {
        cout << "When the light shines on the first doctor, Dr. Milligan, the light is completely red.\n";
        cout << "When the light shines on the second doctor, Dr. Lipton, the light turns to black." << endl;

        cout << "Which doctor is the best suspect?" << endl;
        cout << "1. Dr. Milligan\n";
        cout << "2. Dr. Lipton\n";

        while(validInput == false)
        {
            cin >> choice;
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                choice = validateInput(choice, 1, 2);
                if(choice == 0)
                {
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validInput = true;
                }
            }
        }

        validInput = false;
        cout << endl;
        return choice;
    }
}

int Identify::validateInput(int input, int min, int max)
{
    if(input > max || input < min)
    {
        cout << "Error! Please choose a valid option!" << endl;
        cin.clear();
        cin.ignore();
        return 0;
    }
    else
    {
        return input;
    }
}

void Identify::setColor(char color)
{
    this->color = color;
}

char Identify::getColor()
{
    return color;
}

bool Identify::getSuspect()
{
    return suspect;
}