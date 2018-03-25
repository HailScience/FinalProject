#ifndef INTERROGATION_HPP
#define INTERROGATION_HPP

#include <iostream>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Interrogation : public Space
{
private:
    bool motive;
    bool opportunity;
    bool confess;

public:
    Interrogation(int position, char color);
    void action();
    int menu(int time);
    int validateInput(int input, int min, int max);
    void setColor(char color);
    char getColor();
    bool getConfession();
};

#endif