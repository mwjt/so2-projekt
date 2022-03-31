#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "Ball.h"

class Node
{
public:
    Ball* data;
    Node* next;
};

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    void add(Ball* data);
    void remove(Ball* data);
    Node getHead();
    Ball* get(int);
};

#endif