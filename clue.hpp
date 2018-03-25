#ifndef CLUE_HPP
#define CLUE_HPP

#include <iostream>
#include <string>

using std::string;

class Clue
{
private:
    string name;
    string description;
public:
    Clue(string name, string description)
    {
        this->name = name;
        this->description = description;
    }
    string getName()
    {
        return name;
    }
    string getDescription()
    {
        return description;
    }
};

#endif