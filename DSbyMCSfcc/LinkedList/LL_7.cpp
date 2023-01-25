// reversing the linked list using iteration
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = NULL;

void insert(int x) // at the end
{
    node *tmp = new node();
    tmp->data = x;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
        return;
    }
    node *itr = head;
    while (itr->next != NULL)
        itr = itr->next;
    itr->next = tmp;
}

void print()
{
    node *itr = head;
    while (itr != NULL)
    {
        cout << "[ This is " << itr << ", Value=" << itr->data << ", Next=" << itr->next << " ]\t";
        itr = itr->next;
    }
    cout << "\n\n";
}

void reverse()
{
    node *prv = NULL, *current = head, *nxt;
    while (current != NULL)
    {
        nxt = current->next;
        current->next = prv;
        prv = current;
        current = nxt;
    }
    head = prv;
}

int main()
{
    cout << "How many numbers: ";
    int len;
    cin >> len;

    for (int i = 0, x; i < len; i++)
    {
        cout << "Element " << i + 1 << " is ";
        cin >> x;
        insert(x);
        print();
    }

    reverse();

    cout << "\n\n\n Reversed:" << endl;
    print();
}
