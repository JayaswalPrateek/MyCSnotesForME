// inserting elements at the beginning of the linked list
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insertAtStart(node **head, int x)
{
    node *tmp = new node();
    tmp->data = x;
    tmp->next = *head;
    *head = tmp;
}

void print(node *itr)
{
    while (itr != NULL)
    {
        cout << "[ This is " << itr << ", Value=" << itr->data << ", Next=" << itr->next << " ]\t";
        itr = itr->next;
    }
    cout << "\n\n";
}

int main()
{
    node *head = NULL;
    cout << "How many numbers: ";
    int len;
    cin >> len;

    for (int i = 0, x; i < len; i++)
    {
        cout << "Element " << i + 1 << " is ";
        cin >> x;
        insertAtStart(&head, x);
        print(head);
    }
}
