#include <iostream>
using namespace std;

// Node and its head declaration
struct Node
{
    int data;
    Node *link;
} *head = NULL;

int main()
{

    // linked list has one element that has the value 2
    Node *tmp = new Node();
    tmp->data = 2;
    tmp->link = NULL;
    head = tmp->link;
    delete tmp;

    // to find the last node
    Node *itr = head; // never directly use head otherwise you will lose it
    while (itr->link != NULL)
        itr = itr->link;

    // adding 4 to the end of the list
    tmp = new Node();
    tmp->data = 4;
    tmp->link = NULL;
    itr->link = tmp;
    delete tmp;
}
