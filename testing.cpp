#include <iostream>
#include <string>
#include "space.hpp"
#include "testing.hpp"
#include "crimeScene.hpp"
#include "clue.hpp"
#include "itemStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Testing::Testing(int position, char color) : Space(position, color)
{
    clueBalding = false;
}

void Testing::action()
{
    cout << "\tTesting" << endl;
    cout << "---------------" << endl;

    cout << "You should test the hair to see if there are any clues." << endl;
    //Prompt to test hair
    int test = menu(1);
    //If user wants to test hair
    if(test == 1)
    {
        cout << "You test the hair and find it's positive for Propecia and Rogaine.\n";
        cout << "This combination is usually used by men who are balding.\n";
        cout << " Therefore, your killer must a balding man." << endl;

        //Indicate clue has been found
        clueBalding = true;
        cout << endl;
    }
}

int Testing::menu(int time)
{
    bool validInput = false;
    int choice;

    if(time == 1)
    {
        cout << "Would you like to test the hair?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

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

int Testing::validateInput(int input, int min, int max)
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

void Testing::setColor(char color)
{
    this->color = color;
}

char Testing::getColor()
{
    return color;
}

bool Testing::getClueBalding()
{
    return clueBalding;
}