#ifndef INVESTIGATION_HPP
#define INVESTIGATION_HPP

#include <iostream>
#include "space.hpp"

using std::cout;
using std::endl;

class Investigation
{
private:
    Space *head;
    Space *tail;
public:
    //Constructor
    Investigation()
    {
        head = NULL;
        tail = NULL;
    }

    //Destructor
    ~Investigation()
    {
        while (head != NULL)
        {
            destroyList();
        }
    }

    //Adds space to list
    void addSpace(Space *n)
    {
        //Make next point to NULL to indicate end of list
        n->right = NULL;
        //If the list is empty
        if(tail == NULL)
        {
            //Set head to node
            head = n;
            //Set tail to node
            tail = n;
            //Set node's prev to NULL
            n->left = NULL;
        }
        else
        {
            //Set tail's next to node
            tail->right = n;
            //Set node's prev to tail
            n->left = tail;
            //Set tail to node
            tail = n;
        }
    }

    void printBoard()
    {
        cout << "\tMap" << endl;
        cout << "-----------" << endl;
        //Create a space pointer that points to head
        Space *temp = head;
        //Until list gets to end
        while(temp != NULL)
        {
            //Print symbol for each space
            cout << temp->getColor();
            //Move pointer to next node
            temp = temp->right;
        }
        cout << endl;
        cout << endl;
    }

    //Called by constructor to destroy each node in list
    void destroyList()
    {
        //Create pointer to head of list
        Space *current = head;
        while(current != NULL)
        {
            Space* temp = current;
            current = current->right;
            delete temp;
        }
        head = NULL;
    }
};

#endif