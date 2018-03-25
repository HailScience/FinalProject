#ifndef CRIMESCENE_HPP
#define CRIMESCENE_HPP

#include <iostream>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CrimeScene : public Space
{
private:
    bool kitchen;
    bool bathroom;
    bool bedroom;
    bool victim;
    bool hairSuspect;
    bool partsBoyfriend;
    bool braceletLink;
public:
    CrimeScene(int position, char color);
    void action();
    int menu(int time);
    int validateInput(int input, int min, int max);
    void setColor(char color);
    char getColor();
    bool getPartsBoyfriend();
    bool getHairSuspect();
    bool getVictim();
    bool getBraceletLink();

};

#endif