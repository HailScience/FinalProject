#include <iostream>
#include <string>
#include "space.hpp"
#include "autopsy.hpp"
#include "crimeScene.hpp"
#include "clue.hpp"
#include "itemStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Autopsy::Autopsy(int position, char color) : Space(position, color)
{
    clueDoctor = false;
}

void Autopsy::action()
{
    cout << "\tAutopsy" << endl;
    cout << "---------------" << endl;

    cout << "Let's examine the victim found in the shower first." << endl;
    cout << endl;
    cout << "The victim is a young adult woman.\n";
    cout << "Her throat is slashed, and she died of exsanguination.\n";
    cout << "From the clean cut, it is clear that a scalpel was used.\n";
    cout << "Rigor has passed, so she must have died over 24 hours ago.\n";
    cout << endl;

    cout << "The use of a scalpel to inflict the wound indicates that\n";
    cout << "there is a good chance the killer is a doctor,\n";
    cout << "based on the skill that is required to make this clean cut." << endl;
    cout << endl;
    cout << endl;

    cout << "Now let's examine the victim found in the dumpster." << endl;
    cout << endl;
    cout << "The victim is a young adult male identified as Michael Smith, the boyfriend.\n";
    cout << "Again, it is clear from the clean cuts that a scalpel";
    cout << " was used to dismember the body.\n";
    cout << "The coroner informs you it must have taken at least 12 hours";
    cout << " to dismember the body in this manner.\n";
    cout << "Once more, this indicates the killer must have been a doctor." << endl;

    //Indicate clue has been found
    clueDoctor = true;
    cout << endl;
}

int Autopsy::menu(int time)
{

}

int Autopsy::validateInput(int input, int min, int max)
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

void Autopsy::setColor(char color)
{
    this->color = color;
}

char Autopsy::getColor()
{
    return color;
}

bool Autopsy::getClueDoctor()
{
    return clueDoctor;
}
