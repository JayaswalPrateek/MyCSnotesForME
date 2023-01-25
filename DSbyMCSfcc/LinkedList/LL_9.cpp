// storing reverse of the linked list using recursion
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

void reverse(node *crnt)
{
    if (crnt->next == NULL)
    {
        head = crnt; // head now set to last node crnt which point to NULL
        return;
    }
    reverse(crnt->next);

    node *nxt = crnt->next; // crnt is the 2nd last and nxt is the last node
    nxt->next = crnt;
    crnt->next = NULL;
}
/**
 * head(1,a)      a(2,b)     b(3,c)     c(4,NULL)
 * head points to a which has value 1
 * we move itr till it points to the last node and when it does we shift our head to the last node and the last node points to NULL
 * the recursive control moves to the 2nd last node at c
 * make 4 point to c and 3 point to NULL
 * make 3 point to 2 and make 2 point to NULL
 * make 2 point to a and make a point to NULL
 * DONE!
 */

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

    reverse(head);
    cout << "\n\n\nReversed:" << endl;
    print();
}
