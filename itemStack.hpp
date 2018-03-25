#ifndef ITEMSTACK_HPP
#define ITEMSTACK_HPP

#include <iostream>
#include "clue.hpp"

using std::cout;
using std::endl;

class ItemStack
{
    struct StackNode
    {
        Clue *item;
        StackNode *next;
        StackNode(Clue *item1, StackNode *next1 = NULL)
        {
            item = item1;
            next = next1;
        }
    };
    StackNode *top;
    int capacity;
    int size;
public:
    ItemStack()
    {
        top = NULL;
        capacity = 9;
        size = 0;
    }
    ~ItemStack()
    {
        StackNode * garbage = top;
        while(garbage != NULL)
        {
            top = top->next;
            garbage->next = NULL;
            delete garbage;
            garbage = top;
        }
    }

/******************************************************************
 * Description: Pushes item into stack
 *****************************************************************/
    void push(Clue *clue)
    {
        top = new StackNode(clue, top);
        cout << "You added " << clue->getName() << " to your items!" << endl;
        size++;
    }
/******************************************************************
 * Description: Checks for if stack is empty
 *****************************************************************/

    bool isEmpty()
    {
        return top == NULL;
    }
/******************************************************************
 * Description: Returns size of stack
 *****************************************************************/
    int getSize()
    {
        return size;
    }
/******************************************************************
 * Description: Returns capacity of stack
 *****************************************************************/
    int getCapacity()
    {
        return capacity;
    }
};

#endif
