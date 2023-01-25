// to insert the node at nth position goto n-1 th node and
// make sure it points to the node to be inserted and copy the node it is pointing to to the next of the node that will be inserted
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = NULL;

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

void insert(int x, int n)
{
    node *tmp = new node();
    tmp->data = x;
    tmp->next = NULL;
    if (n == 1)
    {
        tmp->next = head;
        head = tmp;
        print();
        return;
    }
    // else we will goto the n-1 th node
    node *itr = head;
    for (int i = 0; i < n - 2; i++)
        itr = itr->next;
    tmp->next = itr->next;
    itr->next = tmp;
    print();
}

int main()
{
    insert(2, 1); // 2
    insert(3, 2); // 2,3
    insert(4, 1); // 4,2,3
    insert(5, 2); // 4,5,2,3
}
