#include <iostream>
#include <string>
#include "space.hpp"
#include "interrogation.hpp"
#include "identify.hpp"
#include "clue.hpp"
#include "itemStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Interrogation::Interrogation(int position, char color) : Space(position, color)
{
    motive = false;
    opportunity = false;
    confess = false;
}

void Interrogation::action()
{
    cout << "\tInterrogation" << endl;
    cout << "---------------------" << endl;

    cout << "The best way to interrogate the suspect is to identify";
    cout << " means, motive, and opportunity.\n";
    cout << "We already know the doctor had the means, since he is";
    cout << " skilled with a scalpel.\n";
    cout << "Now, let's identify a motive and see where the doctor";
    cout << " was at the time of the murder." << endl;
    cout << endl;
    //Prompt for first question
    int first = menu(1);
    //If user chooses question 1
    if(first == 1)
    {

        cout << "You: What was your relationship with the victim?" << endl;
        cout << endl;
        cout << "Dr. L: We used to be lovers, but she broke it off." << endl;
        cout << endl;
        cout << "You: That must have made you upset." << endl;
        cout << endl;
        cout << "Dr. L: Sure." << endl;
        cout << endl;
        cout << "You show the doctor the bracelet link found in the bedroom." << endl;
        cout << "You: Did you give this to the victim?" << endl;
        cout << endl;
        cout << "Dr. L: Yes, I did." << endl;
        cout << endl;
        cout << endl;
        cout << "Dr. Lipton has given you a motive: ";
        cout << "He was angry that the victim ended the relationship with him." << endl;
        cout << endl;
        //Indicate question has been answered
        motive = true;
    }
        //If user chooses question 2
    else if(first == 2)
    {
        cout << "You: Where were you at the time of the murder?" << endl;
        cout << endl;
        cout << "Dr. L: I was home, alone." << endl;
        cout << endl;
        cout << "You: Can anyone verify that? Did you call anyone, see anyone?" << endl;
        cout << endl;
        cout << "No." << endl;
        cout << endl;
        cout << endl;
        cout << "Since Dr. Lipton has no alibi, he certainly had the";
        cout << " opportunity to kill both victims." << endl;
        cout << endl;
        //Indicate question has been answered
        opportunity = true;
    }

    //Prompt for second question
    int second = menu(2);
    //If user chooses question 1
    if(second == 1)
    {
        cout << "You: What was your relationship with the victim?" << endl;
        cout << endl;
        cout << "Dr. L: We used to be lovers, but she broke it off." << endl;
        cout << endl;
        cout << "You: That must have made you upset." << endl;
        cout << endl;
        cout << "Dr. L: Sure." << endl;
        cout << endl;
        cout << "You show the doctor the bracelet link found in the bedroom." << endl;
        cout << "You: Did you give this to the victim?" << endl;
        cout << endl;
        cout << "Dr. L: Yes, I did." << endl;
        cout << endl;
        cout << endl;
        cout << "Dr. Lipton has given you a motive: ";
        cout << "He was angry that the victim ended the relationship with him." << endl;
        cout << endl;
        //Indicate question has been answered
        motive = true;
    }
    else
    {
        cout << "You: Where were you at the time of the murder?" << endl;
        cout << endl;
        cout << "Dr. L: I was home, alone." << endl;
        cout << endl;
        cout << "You: Can anyone verify that? Did you call anyone, see anyone?" << endl;
        cout << endl;
        cout << "No." << endl;
        cout << endl;
        cout << endl;
        cout << "Since Dr. Lipton has no alibi, he certainly had the";
        cout << " opportunity to kill both victims." << endl;
        cout << endl;
        //Indicate question has been answered
        opportunity = true;
    }
    if(motive == true && opportunity == true)
    {
        cout << "You: Dr. Lipton, from our evidence, it is clear\n";
        cout << "     that you had a motive, the means, and the opportunity\n";
        cout << "     to murder the victim. You can save yourself the\n";
        cout << "     cost and difficulty of a trial if you confess now." << endl;
        cout << endl;
        cout << "Dr. L: Okay, okay. After she broke up with me,\n";
        cout << "       I was very upset. I've been lonely for a long time.\n";
        cout << "       When I saw she had a new boyfriend, I was incensed.\n";
        cout << "       I went to her house, and slit her throat when she\n";
        cout << "       stepped into the shower." << endl;
        cout << "       When her boyfriend showed up, I panicked.\n";
        cout << "       I slit his throat too and spent the rest of the night\n";
        cout << "       taking care of the body." << endl;
        cout << "       When I was done, I went to her bedroom and broke the bracelet I gave her." << endl;
        cout << "       I didn't even think about it. I was just so angry!" << endl;
        cout << endl;
        cout << "You: Dr. Lipton, you're under arrest for double murder." << endl;
        cout << endl;

        //Indicate clue was found
        confess = true;
        cout << endl;
    }
}

int Interrogation::menu(int time)
{
    bool validInput = false;
    int choice;

    if(time == 1)
    {
        cout << "What question would you like to ask?" << endl;
        cout << "1. 'What was your relationship with the victim?'\n";
        cout << "2. 'Where were you at the time of the murder?'\n";

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
                    //If question 1 has not been answered
                else if(choice == 1 && motive == false)
                {
                    validInput = true;
                }
                    //If question 1 has been answered
                else if(choice == 1 && motive == true)
                {
                    cout << "You already asked that question!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                    //If question 2 has not been answered
                else if(choice == 2 && opportunity == false)
                {
                    validInput = true;
                }
                    //If question 2 has been answered
                else if(choice == 2 && opportunity == true)
                {
                    cout << "You already asked that question!" << endl;
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
        cout << "1. 'What was your relationship with the victim?'\n";
        cout << "2. 'Where were you at the time of the murder?'\n";

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
                    //If question 1 has not been answered
                else if(choice == 1 && motive == false)
                {
                    validInput = true;
                }
                    //If question 2 has been answered
                else if(choice == 1 && motive == true)
                {
                    cout << "You already asked that question!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                    //If question 2 has not been answered
                else if(choice == 2 && opportunity == false)
                {
                    validInput = true;
                }
                    //If question 2 has been answered
                else if(choice == 2 && opportunity == true)
                {
                    cout << "You already asked that question!" << endl;
                    cin.clear();
                    cin.ignore();
                }
            }
        }

        validInput = false;
        cout << endl;
        return choice;
    }
}

int Interrogation::validateInput(int input, int min , int max)
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

void Interrogation::setColor(char color)
{
    this->color = color;
}

char Interrogation::getColor()
{
    return color;
}

bool Interrogation::getConfession()
{
    return confess;
}