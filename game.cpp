#include <iostream>
#include <string>
#include "game.hpp"
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

Game::Game()
{
    //Initialize board and its spaces
    //"O" will signify unoccupied space
    this->board = new Investigation();
    this->crimeScene = new CrimeScene(1, 'O');
    this->questioning = new Questioning(2, 'O');
    this->autopsy = new Autopsy(3, 'O');
    this->testing = new Testing(4, 'O');
    this->identify = new Identify(5, 'O');
    this->interrogation = new Interrogation(6, 'O');

    //Initialize item stack
    this->items = new ItemStack();

    //Initialize player
    this->player = new Player(1);
}

Game::~Game()
{
    delete board;
    delete crimeScene;
    delete questioning;
    delete autopsy;
    delete testing;
    delete identify;
    delete interrogation;
    delete items;
    delete player;
}

void Game::setup()
{
    //Add spaces to board
    board->addSpace(crimeScene);
    board->addSpace(questioning);
    board->addSpace(autopsy);
    board->addSpace(testing);
    board->addSpace(identify);
    board->addSpace(interrogation);

    //Mark player's position on board
    crimeScene->setColor('X');

    //Print board
    board->printBoard();
}

void Game::play()
{
    //Go to crime scene
    crimeScene->action();

    bool parts = crimeScene->getPartsBoyfriend();
    if(parts)
    {
        //Create new clue
        Clue *parts = new Clue("Body Parts", "Bags of bloody body parts found in dumpster");
        //Put clue in item stack
        items->push(parts);
    }

    bool hair = crimeScene->getHairSuspect();
    if(hair)
    {
        //Create new clue
        Clue *hair = new Clue("Hair", "Hair found on victim's body");
        //Add clue to item stack
        items->push(hair);
    }

    bool victim = crimeScene->getVictim();
    if(victim)
    {
        //Create new clue
        Clue *body = new Clue("Body of Victim", "Victim's body found in shower");
        //Add clue to item stack
        items->push(body);
    }

    bool braceletLink = crimeScene->getBraceletLink();
    if(braceletLink)
    {
        //Create new clue
        Clue *link = new Clue("Cat-shaped Bracelet Link", "Link found in carpet of bedroom");
        //Add clue to item stack
        items->push(link);
    }

    //Change player position
    player->setPosition(2);
    //Change back crime scene's color
    crimeScene->setColor('O');
    //Mark player's new position on board
    questioning->setColor('X');
    //Print board
    board->printBoard();

    //Go to questioning
    questioning->action();

    bool name = questioning->getName();
    if(name)
    {
        //Create new clue
        Clue *name = new Clue("Boyfriend's Name", "Boyfriend's name is Michael");
        //Add clue to stack
        items->push(name);
    }

    //Change player position
    player->setPosition(3);
    //Change back questioning's color
    questioning->setColor('O');
    //Mark player's new position on board
    autopsy->setColor('X');
    //Print board
    board->printBoard();

    //If victim's body is found and boyfriend's body is found
    if(victim == true && parts == true)
    {
        //Go to autopsy
        autopsy->action();
    }
        //If no bodies are found
    else
    {
        cout << "There is nothing to autopsy!" << endl;
    }

    bool doctor = autopsy->getClueDoctor();
    if(doctor)
    {
        //Create new clue
        Clue *doctor = new Clue("Doctor Clue", "Clue that killer was a doctor");
        //Add clue to item stack
        items->push(doctor);
    }

    //Change player position
    player->setPosition(4);
    //Change back autopsy's color
    autopsy->setColor('O');
    //Mark player's new position on board
    testing->setColor('X');
    //Print board
    board->printBoard();

//If hair is obtained from bathroom
    if(hair == true)
    {
        //Go to testing
        testing->action();
    }
        //If hair is not obtained from bathroom
    else if(hair == false)
    {
        cout << "Nothing to test!" << endl;
    }

    bool balding = testing->getClueBalding();
    if(balding)
    {
        //Create new clue
        Clue *bald = new Clue("Hair with Rogaine and Propecia", "Indicates killer is balding");
        //Add clue to items
        items->push(bald);
    }

    //Change player position
    player->setPosition(5);
    //Change back testing's color
    testing->setColor('O');
    //Mark player's new position on board
    identify->setColor('X');
    //Print board
    board->printBoard();

    //If both clues are found
    if(balding == true && doctor == true)
    {
        //Go to identify
        identify->action();
    }
        //If only one clue is found
    else
    {
        cout << "There is not enough evidence to identify a suspect!" << endl;
    }

    bool suspect = identify->getSuspect();
    if(suspect)
    {
        //Create new clue
        Clue *susp = new Clue("Suspect", "Dr. Lipton, the victim's supervisor");
        //Add clue to item stack
        items->push(susp);
    }

    //Change player position
    player->setPosition(6);
    //Change back identify's color
    identify->setColor('O');
    //Mark player's new position on board
    interrogation->setColor('X');
    //Print board
    board->printBoard();

    if(suspect)
    {
        //Go to interrogation
        interrogation->action();
    }
    //If suspect is not found
    else if(suspect == false)
    {
        cout << "There is no suspect to interrogate!" << endl;
    }

    bool confession = interrogation->getConfession();
    if(confession)
    {
        //Create new clue
        Clue *confession = new Clue("Confession", "Dr. Lipton's confession");
        //Add clue to item stack
        items->push(confession);
    }
}

void Game::endGame()
{
    //Set clues to the number of items
    clues = items->getSize();
    //Set maxClues to stack capacity
    maxClues = items->getCapacity();

    //If the all clues are obtained
    if(clues == maxClues)
    {
        cout << "You solved the murder! Congratulations!" << endl;
    }
        //If not all clues obtained
    else
    {
        cout << "You did not find enough clues! You lost!" << endl;
    }
}

