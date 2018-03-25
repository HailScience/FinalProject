#ifndef TESTING_HPP
#define TESTING_HPP

#include <iostream>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Testing : public Space
{
private:
    bool clueBalding;
public:
    Testing(int position, char color);
    void action();
    int menu(int time);
    int validateInput(int input, int min, int max);
    void setColor(char color);
    char getColor();
    bool getClueBalding();
};

#endif