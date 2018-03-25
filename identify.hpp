#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Identify : public Space
{
private:
    bool suspect;
public:
    Identify(int position, char color);
    void action();
    int menu(int time);
    int validateInput(int input, int min, int max);
    void setColor(char color);
    char getColor();
    bool getSuspect();
};

#endif