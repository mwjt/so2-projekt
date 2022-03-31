#include "LinkedList.h"

LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
}

void LinkedList::add(Ball* data)
{
    Node *node = new Node();
    node->data = data;
    node->next = this->head;
    head = node;
    length++;
}

void LinkedList::remove(Ball* data)
{
    if (head == NULL) return;
    if (head->data == data)
    {
        delete(head->data);
        head = NULL;
        length--;
        return;
    }

    Node* current = head;
    Node* next = head->next;
    do
    {
        if (next != NULL && next->data == data) {
            current->next = next->next;
            delete(next->data);
            delete(next);
            length--;
            return;
        }
        current = next;
        next = next->next;
    } while (next != NULL);
}

Ball* LinkedList::get(int i)
{
    Node* node = head;

    int count = 0;
    while (node != NULL && count < length)
    {
        if (count == i)
            return node->data;
        count++;
        node=node->next;
    }
    return NULL;
}