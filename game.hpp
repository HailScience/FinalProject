#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "space.hpp"
#include "Investigation.hpp"
#include "itemStack.hpp"
#include "clue.hpp"
#include "crimeScene.hpp"
#include "questioning.hpp"
#include "autopsy.hpp"
#include "testing.hpp"
#include "identify.hpp"
#include "interrogation.hpp"
#include "player.hpp"

using std::string;
using std::cout;
using std::endl;

class Game
{
public:
    Game();
    ~Game();
    void setup();
    void play();
    void endGame();
    ItemStack *items;
private:
    Investigation *board;
    CrimeScene *crimeScene;
    Questioning *questioning;
    Autopsy *autopsy;
    Testing *testing;
    Identify *identify;
    Interrogation *interrogation;
    Player *player;
    int clues;
    int maxClues;
};

#endif