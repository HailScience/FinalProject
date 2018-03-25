#ifndef AUTOPSY_HPP
#define AUTOPSY_HPP

#include <iostream>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Autopsy : public Space
{
private:
    bool clueDoctor;
public:
    Autopsy(int position, char color);
    void action();
    int menu(int time);
    int validateInput(int input, int min, int max);
    void setColor(char color);
    char getColor();
    bool getClueDoctor();
};

#endif