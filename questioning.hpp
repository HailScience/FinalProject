#ifndef QUESTIONING_HPP
#define QUESTIONING_HPP

#include <iostream>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Questioning : public Space
{
private:
    bool know;
    bool found;
    bool nameBoyfriend;
public:
    Questioning(int position, char color);
    void action();
    int menu(int time);
    int validateInput(int input, int min, int max);
    int getPosition();
    void setColor(char color);
    char getColor();
    bool getName();

};

#endif