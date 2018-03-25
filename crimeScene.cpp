#include <iostream>
#include <string>
#include "space.hpp"
#include "crimeScene.hpp"
#include "clue.hpp"
#include "itemStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

CrimeScene::CrimeScene(int position, char color) : Space(position, color)
{
    kitchen = false;
    bathroom = false;
    bedroom = false;
    victim = false;
    hairSuspect = false;
    partsBoyfriend = false;
    braceletLink = false;
}

void CrimeScene::action()
{
    cout << "\tCrime Scene" << endl;
    cout << "-------------------" << endl;

    //Prompt to search car
    int car = menu(1);
    //If player wants to search car
    if(car == 1)
    {
        cout << "You find a fresh bag of groceries inside the car." << endl;
        cout << endl;
    }

    //If player chooses '2', continue...

    //Enter house
    cout << "You enter the house." << endl;
    //Prompt for room to search
    int room = menu(2);
    //While user wants to keep searching house...
    while(room != 4)
    {
        //If player chooses kitchen
        if(room == 1)
        {
            //Prompt to look in refrigerator
            int fridge = menu(3);
            //If user chooses to look in fridge
            if(fridge == 1)
            {
                cout << "You find what looks like a new jug of milk.\n";
                cout << "You turn it over to look at the expiration date.\n";
                cout << "The expiration date indicates the milk was bought 2 days ago." << endl;
                cout << endl;
            }

            //If user chooses '2', continue...

            cout << "You look around and notice there are no cleaning supplies ";
            cout << "(paper towels, bleach, sponges), ";
            cout << "and there is nothing in the trash." << endl;
            cout << endl;
            //Prompt to look in dumpster
            int dumpster = menu(4);
            //If user chooses to look in dumpster
            if(dumpster == 1)
            {
                cout << "You go outside to the dumpster.\n";
                cout << "There is an awful smell coming from inside.\n";
                cout << "You open the dumpster to find bags full of bloody body parts." << endl;

                //Indicate clue was found
                partsBoyfriend = true;
                cout << endl;
            }
            //Indicate kitchen was visited
            kitchen = true;
            //Display menu again
            room = menu(2);
        }
        //If user chooses to visit bathroom
        if(room == 2)
        {
            cout << "You find the victim face down in the shower in a pool of blood.\n";
            cout << "You are told she was found by her best friend." << endl;
            //Prompt to take a closer look at the body
            int closer = menu(5);
            //If user chooses to take a closer look
            if(closer == 1)
            {
                cout << "You find a hair on the body.\n";
                cout << "Best to take that for testing." << endl;

                //Indicate the clue was found
                hairSuspect = true;
                cout << endl;
            }

            //If user chooses '2', continue...

            cout << "Better take the body for an autopsy." << endl;

            //Indicate clue was found
            victim = true;
            cout << endl;

            //Prompt to look in drain
            int drain = menu(6);
            //If user chooses to look in drain
            if(drain == 1)
            {
                cout << "You swab the drain and test the swab.\n";
                cout << "You find that the drain is covered in blood and bleach.\n" << endl;
                cout << "This probably means the killer cleaned up afterwards." << endl;
                cout << endl;
            }

            //If user chooses '2', continue...

            //Indicate bathroom has been visited
            bathroom = true;
            //Display menu again
            room = menu(2);
        }
        //If user chooses to visit bedroom
        if(room == 3)
        {
            cout << "You go into the bedroom and find it has been cleaned." << endl;
            //Prompt to take a closer look
            int close = menu(7);
            //If user chooses to take a closer look
            if(close == 1)
            {
                cout << "You find a cat-shaped bracelet link in the carpet." << endl;

                //Indicate clue was found
                braceletLink = true;
                cout << endl;
            }
            bedroom = true;
            //Display menu again
            room = menu(2);
            //If user chooses '2', continue...
        }
    }
    //If user chooses to exit, or if all rooms have been visited
    if(room == 4)
    {
        cout << "You are done searching the crime scene!" << endl;
        cout << endl;
    }
}

int CrimeScene::menu(int time)
{
    int choice;
    bool validInput = false;
    if(time == 1)
    {
        //Prompt to look in car
        cout << "Outside the house you see a car parked in the driveway.\n";
        cout << "The car is unlocked." << endl;
        cout << "Do you want to look inside the car?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

        while(!validInput)
        {
            //Input choice
            cin >> choice;
            //If wrong input type
            if(cin.fail())
            {
                //Clear stream and return through loop
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                //Check for valid input limits
                choice = validateInput(choice, 1, 2);
                if(choice == 0)
                {
                    //Clear stream and return through loop
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Don't return through loop
                    validInput = true;
                }
            }
        }
        //Set validInput back to false
        validInput = false;
        cout << endl;
        //Return input
        return choice;
    }
    else if(time == 2)
    {
        //If no rooms have been visited yet...
        if(kitchen == false && bathroom == false && bedroom == false)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong type of input
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and try again
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        //Break out of loop
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If only kitchen has been visited...
        else if(kitchen == true && bathroom == false && bedroom == false)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong type of input
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and return through loop
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses kitchen again
                    else if(choice == 1)
                    {
                        //Display error message, clear stream, return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        //If user does not choose kitchen
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If kitchen and bathroom have been visited...
        else if(kitchen == true && bathroom == true && bedroom == false)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong type of input
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and return through loop
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses kitchen again
                    else if(choice == 1)
                    {
                        //Clear stream and return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses bathroom again
                    else if(choice == 2)
                    {
                        //Clear stream and return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If kitchen and bedroom have been visited...
        else if(kitchen == true && bathroom == false && bedroom == true)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong type of input
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and return through loop
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses kitchen again
                    else if(choice == 1)
                    {
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses bedroom again
                    else if(choice == 3)
                    {
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If only bathroom has been visited...
        else if(kitchen == false && bathroom == true && bedroom == false)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong type of input
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and return through loop
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses bathroom again
                    else if(choice == 2)
                    {
                        //Clear stream and return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If bathroom and bedroom have already been visited...
        else if(kitchen == false && bathroom == true && bedroom == true)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong type of input
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and return through loop
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses bathroom again
                    else if(choice == 2)
                    {
                        //Clear stream and return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses bedroom again
                    else if(choice == 3)
                    {
                        //Clear stream and return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If only bedroom has been visited...
        else if(kitchen == false && bathroom == false && bedroom == true)
        {
            cout << "Which room would you like to investigate?" << endl;
            cout << "1. Kitchen\n";
            cout << "2. Bathroom\n";
            cout << "3. Bedroom\n";
            cout << "4. Exit crime scene\n";

            while(!validInput)
            {
                cin >> choice;
                //If wrong input type
                if(cin.fail())
                {
                    cout << "Error! Please enter an integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    //Validate user input
                    choice = validateInput(choice, 1, 4);
                    //If invalid choice
                    if(choice == 0)
                    {
                        //Clear stream and return through loop
                        cin.clear();
                        cin.ignore();
                    }
                        //If user chooses bedroom again
                    else if(choice == 3)
                    {
                        //Clear stream and return through loop
                        cout << "You've already been there!" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        validInput = true;
                    }
                }
            }
            //Set validInput back to false
            validInput = false;
            cout << endl;
            //Return user input
            return choice;
        }
            //If user has visited every room
        else if(kitchen == true && bathroom == true && bedroom == true)
        {
            //Set choice to 4 for 'exit'
            choice = 4;
            return choice;
        }
    }
    else if(time == 3)
    {
        //Prompt to look in fridge
        cout << "In the kitchen, you see groceries on the counter." << endl;
        cout << "Would you like to look inside the refrigerator?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

        while(!validInput)
        {
            cin >> choice;
            //If wrong input type
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                //Validate user input
                choice = validateInput(choice, 1, 2);
                //If invalid choice
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
        //Set validInput back to false
        validInput = false;
        cout << endl;
        //Return user input
        return choice;
    }
    else if(time == 4)
    {
        //Prompt to look in dumpster
        cout << "It might be a good idea to check the dumpster." << endl;
        cout << "Would you like to check the dumpster?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

        while(!validInput)
        {
            cin >> choice;
            //If wrong input type
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                //Validate user input
                choice = validateInput(choice, 1, 2);
                //If invalid input
                if(choice == 0)
                {
                    //Clear stream and return through loop
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validInput = true;
                }
            }
        }
        //Set validInput back to false
        validInput = false;
        cout << endl;
        //Return user input
        return choice;
    }
    else if(time == 5)
    {
        //Prompt to take a closer look at the body
        cout << "Would you like to take a closer look?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

        while(!validInput)
        {
            cin >> choice;
            //If wrong input type
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                //Validate user input
                choice = validateInput(choice, 1, 2);
                //If invalid input
                if(choice == 0)
                {
                    //Clear stream and return through loop
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validInput = true;
                }
            }
        }
        //Set validInput back to false
        validInput = false;
        cout << endl;
        //Return user input
        return choice;
    }
    else if(time == 6)
    {
        //Prompt to check drains
        cout << "The bathroom is too clean..." << endl;
        cout << "Would you like to check the drains?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

        while(!validInput)
        {
            cin >> choice;
            //If wrong input type
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                //Validate user input
                choice = validateInput(choice, 1, 2);
                //If invalid input
                if(choice == 0)
                {
                    //Clear stream and return through loop
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validInput = true;
                }
            }
        }
        //Set validInput back to false
        validInput = false;
        cout << endl;
        //Return user input
        return choice;
    }
    else if(time == 7)
    {
        //Prompt to take closer look
        cout << "Would you like to take a closer look?" << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";

        while(!validInput)
        {
            cin >> choice;
            //If wrong input type
            if(cin.fail())
            {
                cout << "Error! Please enter an integer!" << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                //Validate user input
                choice = validateInput(choice, 1, 2);
                //If invalid input
                if(choice == 0)
                {
                    //Clear stream and return through loop
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validInput = true;
                }
            }
        }
        //Set validInput back to false
        validInput = false;
        cout << endl;
        //Return user input
        return choice;
    }
}

int CrimeScene::validateInput(int input, int min, int max)
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

void CrimeScene::setColor(char color)
{
    this->color = color;
}

char CrimeScene::getColor()
{
    return color;
}

bool CrimeScene::getPartsBoyfriend()
{
    return partsBoyfriend;
}

bool CrimeScene::getHairSuspect()
{
    return hairSuspect;
}
bool CrimeScene::getVictim()
{
    return victim;
}
bool CrimeScene::getBraceletLink()
{
    return braceletLink;
}