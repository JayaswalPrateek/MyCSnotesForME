// to delete nth node you need to link n-1 and n+1 th node to each other and free the nth node
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

void del(int n)
{
    node *nMinusOne = head;
    if (n == 1)
    {
        head = nMinusOne->next;
        delete nMinusOne;
        return;
    }
    for (int i = 0; i < n - 2; i++)
        nMinusOne = nMinusOne->next;
    node *nPlusOne = nMinusOne->next->next;
    nMinusOne->next = nPlusOne;
    delete nMinusOne;
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

    cout << "\n\n\n\n";

    for (int i = 0, n; i < len; i++)
    {
        cout << "Remove position: ";
        cin >> n;
        del(n);
        print();
    }
}
