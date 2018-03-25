#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>


class Investigation;

class Space
{
    friend class Investigation;
public:
    Space(int position, char color);
    virtual void action() =0;
    virtual int menu(int time) =0;
    virtual int validateInput(int input, int min, int max) =0;
    virtual void setColor(char color) =0;
    virtual char getColor() =0;

protected:
    int position;
    char color;
    Space* top;
    Space* bottom;
    Space* left;
    Space* right;
};

#endif