// doubly linked list:
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev, *next;
} *head = NULL;

void insertAtHead(int x)
{
    node *tmp = new node();
    tmp->data = x;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (head == NULL) // if the list is empty
    {
        head = tmp;
        return;
    }
    // when the list is not empty
    head->prev = tmp; // establishing link in forward dirn
    tmp->next = head; // establishing link in backward dirn
    head = tmp;       // head should now point at the node we inserted
}

void fwdPrint()
{
    for (node *itr = head; itr != NULL; itr = itr->next)
        cout << "This is " << itr << " having (prev=" << itr->prev << " data=" << itr->data << " next=" << itr->next << ")" << endl;
}

void revPrint()
{
    node *itr = head;
    if (head == NULL)
        return;               // exit if empty list
    while (itr->next != NULL) // to get to the last node
        itr = itr->next;
    while (itr != NULL)
    {
        cout << "This is " << itr << " having (prev=" << itr->prev << " data=" << itr->data << " next=" << itr->next << ")" << endl;
        itr = itr->prev;
    }
}

int main()
{
    cout << "[1] Insert At Head\n[2] Print Forward\n[3] Print Reverse\n[4] Quit\n\n";
    int ch;
restart:
    do
    {
        cout << "\nChoice: ";
        cin >> ch;
    } while (ch != 1 && ch != 2 && ch != 3 && ch != 4);
    switch (ch)
    {
    case 1:
        cout << "Enter Element: ";
        int x;
        cin >> x;
        insertAtHead(x);
        break;
    case 2:
        fwdPrint();
        break;
    case 3:
        revPrint();
        break;
    case 4:
        return 0;
    }
    goto restart;
}
