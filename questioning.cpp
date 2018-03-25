#include <iostream>
#include <string>
#include "space.hpp"
#include "questioning.hpp"
#include "clue.hpp"
#include "itemStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Questioning::Questioning(int position, char color) : Space(position, color)
{
    know = false;
    found = false;
    nameBoyfriend = false;
}

void Questioning::action()
{
    cout << "\tQuestioning" << endl;
    cout << "-------------------" << endl;
    cout << "Since the victim's best friend found the body,";
    cout << " you should question her." << endl;
    cout << endl;

    //Prompt to question best friend
    int question = menu(1);
    //If user chooses to question best friend
    if(question == 1)
    {
        //Ask first question
        int first = menu(2);
        if(first == 1)
        {
            cout << "You: How did you know the victim?" << endl;
            cout << "BF: She was my best friend.";
            cout << " We're both nurses and work at the hospital together." << endl;
            cout << endl;

            //Indicate that question was answered
            know = true;
        }
        else
        {
            cout << "You: How did you find the victim?" << endl;
            cout << "BF: We were supposed to meet up yesterday,";
            cout << " but she cancelled to meet her boyfriend.\n";
            cout << "    When she didn't show up for work the next day,";
            cout << " I called her house, and there was no answer.\n";
            cout << "    I showed up at her house and found her." << endl;
            cout << "You: What is her boyfriend's name?" << endl;
            cout << "Bf: Michael Smith." << endl;


            //Indicate clue has been found
            nameBoyfriend = true;
            //Indicate question has been answered
            found = true;
            cout << endl;
        }

        //Ask second question
        int second = menu(3);
        if(second == 1)
        {
            cout << "You: How did you know the victim?" << endl;
            cout << endl;
            cout << "BF: She was my best friend.";
            cout << " We're both nurses and work at the hospital together." << endl;
            cout << endl;

            //Indicate question has been answered
            know = true;
        }
        else
        {
            cout << "You: How did you find the victim?" << endl;
            cout << endl;
            cout << "BF: We were supposed to meet up yesterday,\n";
            cout << "but she cancelled to meet her boyfriend.\n";
            cout << "    When she didn't show up for work the next day,";
            cout << "I called her house, and there was no answer.\n";
            cout << "    I showed up at her house and found her." << endl;
            cout << endl;
            cout << "You: What is her boyfriend's name?" << endl;
            cout << endl;
            cout << "BF: Michael Smith." << endl;


            //Indicate clue has been found
            nameBoyfriend = true;
            //Indicate question has been asked
            found = true;
            cout << endl;
        }
    }
}

int Questioning::menu(int time)
{
    bool validInput = false;
    int choice;

    if(time == 1)
    {
        cout << "Would you like to question the best friend?" << endl;
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
    else if(time == 2)
    {
        cout << "What question would you like to ask?" << endl;
        cout << "1. 'How did you know the victim'\n";
        cout << "2. 'How did you find the body?'\n";

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
                    //If question 1 has not been asked
                else if(choice == 1 && know == false)
                {
                    validInput = true;
                }
                    //If question 1 has been asked
                else if(choice == 1 && know == true)
                {
                    cout << "You already asked that question!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                    //If question 2 has not been asked
                else if(choice == 2 && found == false)
                {
                    validInput = true;
                }
                    //If question 2 has been asked
                else if(choice == 2 && found == true)
                {
                    cout << "You already asked that question!" << endl;
                }
            }
        }

        validInput = false;
        cout << endl;
        return choice;
    }
    else if(time == 3)
    {
        cout << "What question would you like to ask?" << endl;
        cout << "1. 'How did you know the victim'\n";
        cout << "2. 'How did you find the body?'\n";

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
                    //If question 1 has not been asked
                else if(choice == 1 && know == false)
                {
                    validInput = true;
                }
                    //If question 1 has been asked
                else if(choice == 1 && know == true)
                {
                    cout << "You already asked that question!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                    //If question 2 has not been asked
                else if(choice == 2 && found == false)
                {
                    validInput = true;
                }
                    //If question 2 has been asked
                else if(choice == 2 && found == true)
                {
                    cout << "You already asked tht question!" << endl;
                }
            }
        }

        validInput = false;
        cout << endl;
        return choice;
    }
}

int Questioning::validateInput(int input, int min, int max)
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

void Questioning::setColor(char color)
{
    this->color = color;
}

char Questioning::getColor()
{
    return color;
}

bool Questioning::getName()
{
    return nameBoyfriend;
}