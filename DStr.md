# <mark style="background: #FFB86CA6;">Big O</mark>
- `O(1)` algorithms are most efficient as they scale really well because the execution time is independent of the input size
	- like searching a value in map using its key
- `O(n)` means the execution time is linearly dependent on the input size
	- searching for an element in an array
	- we usually take the worst case scenario like if the element we are looking for is at the end of the array of length n then its `O(n)`
	- `O(n)` can be `O(1)` if the element we are looking for is at the 0th index but this is not guaranteed
- nested loop doesn't always imply `O(n^2)`
	- but `O(n^2)` can have nested loops
- if i am searching a 1-D loop twice it is `O(2n)`
	- so if i doing it n times it is `O(n^2)`
- suppose we have a 1-D array of length n and first we traverse from 0th index to (n-1)th index
	- then in the 2nd pass we skip the 0th element and start from 1st element. next pass from 2nd one and so on
	- so we will have a total of n-1 passes for an array of length n
	- if we draw the array one below the other for every pass and erase the block we skip, we will get ◹  shape
		- this has base and height n-1. We ignore 1 so the square has a `O(n^2)` and ◹  shape has `O(n^2/2)` but constant doesn't matter so its still `O(n^2)`
- if a 2-D matrix is not a square and has sides `n x m` then it will have `O(n x m)`
- `O(log n)`
	- we keep shrinking the array in half so we will never have to traverse all the n elements and always less than n so it will be `O(log n)`
	- so n=2^x where n is the length and x is the no of times will have to split in half so take log both sides to get `O(log n)`
	- used for binary trees
	- very efficient for sorted data
- `O(n log n)` is more efficient than `0(n^2)` but less than `O(n)`
- imagine a tree which has 3 branches and each branch has 3 more branches and so on and if the height of the tree is n then `O(3^n)`
- `O(n!)` is the worst
- Efficiency increases from left to right in the graph below:


![time vs input size](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-21%2009-52-29.png)

# <mark style="background: #FFB86CA6;">Arrays</mark>
- Read is `O(1)` but inserting and deleting are `O(n)`
	- Reason: contiguous memory allocation is done so if next address is occupied then the array needs to be copied to another location contiguously can have unused memory

# <mark style="background: #FFB86CA6;">STL ADT</mark>
- c++ STL is a collection of useful algorithms, data structures and functions related to them in form of template classes
- c++ STL  has 4 things: functions,algorithms, containers and iterators
- containers are the classes for the data structures
- algorithms are complex operations performed on the containers like search, sort
- functions are simpler operations performed on the containers like push, pop
- iterators are used to access containers in a simpler way
- to import all the containers and common header files like iostream etc, use `#include<bits/stdc++.h>`
- <mark style="background: #D2B3FFA6;">Containers</mark>
	1. <mark style="background: #BBFABBA6;">vector</mark>
		- its a large array but not a linked list so when the array is filled then a new array is created and all the contents of the older array is copied to the new array
		- functions: push, pop, insert, remove, size, isempty, front, back
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    vector<int> v;
		
		    v.push_back(1);         // the first element of v becomes 1
		    v.push_back(2);         // the second element of v becomes 1
		    v.emplace_back(2);      // same as push_back but faster
		    v.emplace_back(3);      // same as push_back but faster
		    v.emplace_back(4);      // same as push_back but faster
		    v.emplace_back(5);      // same as push_back but faster
		    v.erase(v.end() - 1);   // exceptional case to remove last element
		    v.erase(v.begin() + 1); // removes 2nd element
		    // v.erase(startingIndexAddress,AdrOfLastElementToBeDeleted+1) can also erase a range of elements if you provide
		    v.insert(v.begin(), 0);
		    // v.insert(address,howManyCopiesOf,ThisElement);
		    // to insert vector cpy into v: v.insert(Address, cpy.begin(),cpy.endl);
		
		    cout << v.front() << " " << v.back() << endl;
		
		    for (auto itr = v.begin(); itr != v.end(); itr++)
		        cout << *itr << " ";
		
		    cout << endl;
		
		    for (auto itr = v.rbegin(); itr != v.rend(); itr++)
		        cout << *itr << " ";
		
		    cout << endl;
		
		    for (auto x : v)
		        cout << x << " ";
		
		    vector<pair<int, int>> vpair;
		    vpair.push_back({1, 2});  // need to use flower braces to specify pair
		    vpair.emplace_back(3, 4); // automatically infers that it is a pair
		
		    vector<int> hundred(5, 100); // creates {100,100,100,100,100}
		    vector<int> bydefault(5);    // creates {0,0,0,0,0}
		
		    vector<int> temp(v); // creates a seperate copy of v and names it temp
		
		    cout << endl
		         << v.size();
		    // v.clear() makes the vector empty
		    // v.empty gives bool if vector v is empty or not
		    return 0;
		}
		```
	2. <mark style="background: #BBFABBA6;">list</mark>
		- doubly linked list
		-  ![doubly linked list](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/DLL1.png)
		- functions: similar to vector
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    list<int> ls; // same as vector but also allows front operations
		    ls.push_back(2);
		    ls.emplace_back(4);
		    ls.push_front(0);
		    ls.emplace_front(-2);
		    ls.pop_front();
		    ls.pop_back();
		    return 0;
		}
		```
	3. <mark style="background: #BBFABBA6;">forward list</mark>
		- same as list but singly linked list instead
		- opposite to array as read is `O(n)`, insert and delete is `O(1)` if at the beginning, `O(n)` if at the end
		- they cannot be indexed like arrays
		- address of the head node is stored as a pointer to the node
	4. <mark style="background: #BBFABBA6;">dequeue</mark>
		- doubly ended queues are queues but elements can be pushed and popped from both ends
		- kinda like vectors but contiguous memory allocations is not guaranteed
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    deque<int> ls; // same as vector but also allows front operations
		    ls.push_back(2);
		    ls.emplace_back(4);
		    ls.push_front(0);
		    ls.emplace_front(-2);
		    ls.pop_front();
		    ls.pop_back();
		    return 0;
		}
		```
	5. <mark style="background: #BBFABBA6;">priority queue</mark>
		- also called max heap
		- pop deletes the largest element 
	6. <mark style="background: #BBFABBA6;">stack</mark>
		- lifo
		- stack of washed plates
		- push,pop and peek are `O(1)`
		- push adds new element at the top of the stack
		- pop removes the topmost element
		- peek reads the topmost element
		- useful for reversing without recursion
		- insert and delete happens from the same end
	7. <mark style="background: #BBFABBA6;">queue</mark>
		- fifo
		- enqueue adds new element at the end of the queue `O(1)`
		- dequeue is the pop for the stack removes front most element `O(1)`
		- front reads the frontmost element `O(1)`
		- more used than stack irl
		- insert happens at one end and delete happens from other
		- used when there is a shared resource and it can only handle only one resource at a time like a printer or a processor
	8. <mark style="background: #BBFABBA6;">set</mark>
		- duplicates are not stored so every element in a set is unique
	9. <mark style="background: #BBFABBA6;">multiset</mark>
		- same as set but allows duplicate
	10. <mark style="background: #BBFABBA6;">map</mark>
		- like arrays but the indices are called keys and keys can be of any data type
		- stores key-value pairs and all keys must be unique and keys are stored in sorted order
		- read, insert and delete are `O(1)`
	11. <mark style="background: #BBFABBA6;">multimap</mark>
		- like a map but allows duplicate keys but the key-value pairs must be unique
	12. <mark style="background: #BBFABBA6;">unordered map</mark>
		- like map but keys are not stored in sorted order
	13. <mark style="background: #BBFABBA6;">pairs and nested pairs</mark> 
		```cpp
			#include <bits/stdc++.h>
			using namespace std;
			int main()
			{
			    pair<int, int> p = {1, 2};
			    cout << p.first << " " << p.second << endl;
			    pair<pair<int, int>, int> np = {p, 3};
			    cout << np.first.first << " " << np.first.second << " " << np.second << endl;
		
			    pair<int, int> pairray[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
			    for (int i = 0; i < sizeof(pairray) / 8; i++)
			        cout << pairray[i].first << " " << pairray[i].second << endl;
			    return 0;
			}	
		```
- <mark style="background: #D2B3FFA6;">Iterators</mark>
	```cpp
	#include <iostream>
	#include <vector>
	using namespace std;
	int main()
	{
	    // vector<int> v;  by default creates a vector of len 16
	    // vector<int> v(50); creates a vector of len 50
	    vector<int> v = {1, 23, 456, 7890};
	    v.push_back(56); // added 56 at the end after 7890
	    v.push_back(69); // added 69 at the end after 56
	    v.pop_back();    // last element is removed
	    for (int x : v)
	        cout << x << " ";
	    cout << endl;
	    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
	        cout << *itr << " "; // becoz itr is a ptr which uses ptr arithmetic
	    return 0;
	}
	// u can replace occurences of vector with list or forward_list or dequeue or set and not other changes are needed
	```
	- using maps
	```cpp
	#include <iostream>
	#include <map>
	using namespace std;
	int main()
	{
	    map<int, string> m;
	    m.insert(pair<int, string>(1, "john"));
	    m.insert(pair<int, string>(2, "ravi"));
	    m.insert(pair<int, string>(3, "khan"));
	
	    map<int, string>::iterator itr;
	    for (itr = m.begin(); itr != m.end(); itr++)
	        cout << itr->first << " " << itr->second << endl;
	
	    map<int, string>::iterator itr1;
	    itr1 = m.find(2);
	    cout << "value found: " << itr1->first << " " << itr1->second << endl;
	    return 0;
	}
	```

# <mark style="background: #FFB86CA6;">CDT: Concrete Data Types</mark> 

<mark style="background: #D2B3FFA6;">Singly Linked List</mark>
```cpp
#include <iostream>
using namespace std;

// Node and its head declaration
struct Node
{
    int data;
    Node *next;
} *head = NULL;

int main()
{
    Node *tmp = new Node();
    tmp->data = 2;
    tmp->next = NULL;
    head = tmp->next;
    delete tmp;
    // linked list has one element that has the value 2

    // to find the last node
    Node *itr = head; // never directly use head otherwise you will lose it
    while (itr->next != NULL)
        itr = itr->next;

    // adding 4 to the end of the list
    tmp = new Node();
    tmp->data = 4;
    tmp->next = NULL;
    itr->next = tmp;
    delete tmp;
    return 0;
}
```
- inserting elements at the beginning of a linked list
```cpp
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = NULL;
// if head is not global then we dont need to make a copy tmp as the pass by value creates own copies for functions

void insertAtStart(int x)
{
    node *tmp = new node();
    tmp->data = x;
    tmp->next = head;
    head = tmp;
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
        insertAtStart(x);
        print();
        return 0;
    }
}
```
- inserting elements at the beginning of the linked list
```cpp
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *insertAtStart(node *head, int x)
{
    node *tmp = new node();
    tmp->data = x;
    tmp->next = head;
    // head = tmp; is redundant
    return tmp;
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
        head = insertAtStart(head, x);
        print(head);
    }
}
```
- inserting elements at the beginning of the linked list
```cpp
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
```
- to insert the node at nth position goto n-1 th node and
	- make sure it points to the node to be inserted and copy the node it is pointing to to the next of the node that will be inserted
```cpp
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
```
- to delete nth node you need to link n-1 and n+1 th node to each other and free the nth node
```cpp
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
```
- reversing the linked list using iteration
```cpp
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
```
- printing reverse of the linked list using recursion
```cpp
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

void reversePrinter(node *itr)
{
    if (itr == NULL)
        return;
    reversePrinter(itr->next);
    cout << itr->data << " ";
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

    cout << "\n\n\nReversed:" << endl;
    reversePrinter(head);
}
```
- storing reverse of the linked list using recursion
```cpp
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
```

<mark style="background: #D2B3FFA6;">Doubly Linked List</mark>
```cpp
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
```

<mark style="background: #D2B3FFA6;">Binary Search Trees</mark>
- is a binary tree with left child node of a parent node always smaller than or equal to the parent node and the right child node of a parent node always larger than or equal to the parent node
- used for effectively searching
- recursion is used for common operations as tree has unidirectional next nodes, we use stack of activation record of functions in recursive calls to remember the address of parental nodes
- to check validity, n nodes = n-1 connecting links
- depth
	- depth is measured from the topmost node of the tree
	- So root of the tree has depth 0
- height
	- height of a node in a tree is equal to the number of connecting links needed to reach that node from the furthest leaf(a node without any child) under the node
	- so height of all leaves is 0
	- height of a tree is height of the topmost node of the tree
- max number of nodes for a node at height h = 2^h




	 - a tree where every node can have only 2 child nodes and the left child node should be lesser than parent node and the right child node should be greater than the parent node
	 - number of nodes at height h = 2^h so we can find max number of nodes of the BINARY tree if we know the ht of the BINARY tree
	 - for a BINARY tree of ht h, max nodes = 2^h - 1
	 - a binary tree where a node can only have 2 or no nodes is called a perfect binary tree and its height is floor of log base2 n
	 - cost proportional to ht of tree
		 - ht is less if the tree is dense and more like a perfect binary tree
		 - opposite of a perfect binary tree is a linked list
			 - min ht can be floor of log base2 n
			 - max ht is n-1
			 - n is the number of nodes
		- so tree has O(ht)
			- perfect hai toh O(log base2 n)
			- linked list toh O(n)
		- ht of empty tree = -1 as no node
		- ht of tree w/ 1 node is 0
		- for n nodes its n-1 which is same as number of links
	- try keeping tree balanced, balanced tree is one for which (ht of left child subtree of parent) - (ht of right child subtree of parent) = 0 or 1
	- ![binary tree array](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-23%2022-31-43.png)
	- ![why use binary search tree](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-23%2023-18-36.png)
	- in a binary search tree at every step you compare the value you are looking for with the value at the node and if it is match you stop
		- else you discard left or right sub tree
	- ![this is insertion](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-23%2023-29-47.png)














































- graphs
	- linked lists and binary search trees are also types of graphs
	- no restrictions than linked lists and binary search trees
	- G=(V,E) where G is an ordered pair of vertices and edges
		- every edge can be directed(one way) or undirected(2 way)
	- an edge can have weight like distance between 2 places
		- with weights we cannot just rely on the number of edges between 2 vertices to find the shortest path
		- when no weights given assume all weights are equal to 1
	- a self loop means the vertex has an edge that points to itself
		- many websites have links to the same page and that is an example of self loop
	- multi edge when there are multiple edges between 2 vertices like airlines between 2 airports
	- a simple graph has no self loop or multiedges
	- in a simple directed graph the max number of edges for n vertices is n(n-1) where n is not -ve
		- for simple undirected it will be n(n-1)/2
	- a dense graph has edges near to max possible else it is sparse
	- for dense graph we use adjacency matrix and for sparse it it an adjacency list
	- path
		- simple path when vertices/edges are not repeated
		- if repeated it is a walk
			- closed walk when start and end is the same vertex also called cycle
				- tree is acyclic
		- trail when edges are not repeated but vertices can be
		- creating graph data str in the memory
			- use 2 vectors
			- one stores the content of the vertex called vertex list
			- and edge list which is a struct of edge (and it weight also if needed) and stores 2 ints
			- we know every vertex stored in the vertex list vector has an index
			- we can imagine that an edge connects these indices instead of pointing to them
			- ![creating a graph](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-25%2014-25-06.png)
		- common operations
			- finding adjacent nodes
			- checking if 2 nodes are connected
			- every time this will take O(number of Edges or |E|)
				- this is nearly O(n^2) as we know the formula for max number of edges from the number of nodes
			- a O(n) is considered acceptable: which technically is O(number of vertices or |V|)
			- Solution: Adjacency Matrix and Adjacency List
			- Adjacency Matrix of order |V| x |V|
				- better for dense graphs beacuse we will store many 0s for a sparse graph
				- huge storage footprint
				- rows are corresponding to the vertex list and 1 in columns represent that they are connected
				- remaining values are set to zero
				- for undirected grpah the matrix will be symmetric so Aij == Aji so we can omit upper or lower triangular matrix with diagonal of matrix as the hypotenuse
				- ![adjacency matrix of a graph](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-25%2014-39-31.png)
				- to find adjacent nodes we do a linear search on the vertex list and then do a linear search on the row of adjacency matrix corresponding to the index in vertex list
				- so it is O(V+V) = O(2V) = O(V)
				- to find if 2 nodes are connected or not we can pass their indices i and j we just need to find the value of `A[i][j]` in the Adjacency matrix and see if it is 0 or 1
				- so its a O(1)
					- if the names are given then we need to do a linear search on the vertex list making it O(V)
						- this can be avoided by using hash map so it will always be O(1)
				- for weighted graphs:
					- replace 1 with edge weights and 0 with INT_MAX
				- for facebook, using adjacent matrix optimally means for 1 billion users everyone is a friend of everyone else
					- this is impossible implying we will waste lot of memory
				- we are storing what nodes are connected to each other and also the ones that are not
					- this is redundant info as it can be deduced from knowing what nodes are connected to each other
			- adjacency list is an array of pointers
				- less memory as space complexity is O(number of edges) as e << v^2
				- ![Adjacency List](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-25%2021-00-55.png)
				- we need to perform linear search or binary search on the adjacency list so for finding if 2 nodes are connected O(v) or O(log v)
					- v is the number of vertices
					- O(1) in the matrix
				- for finding adjacent nodes (all the neighbors of a node) then O(v)
					- also O(v) in matrix
				- still practically list is better most of the times
					- use matrix if the graph is dense and the v and e are small values.
			- adding a new edge now
				- for a matrix flip a zero to one
				- for a list if we are using array of pointers we need to create a new array and copy previous elements into it and then add the new one
					- so use linked list? yes and each pointer in the array points to the head of a linked list
						- technically this is an Adjacency list!
						- the node will store weight if the graph is weighted