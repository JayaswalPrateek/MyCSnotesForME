# <mark style="background: #FFB86CA6;">Big O</mark>
- `O(1)` algorithms are most efficient as they scale really well because the execution time is independent of the input size
	- like searching a value in map using its key
- `O(n)` means the execution time is linearly dependent on the input size
	- searching for an element in an array
	- we usually take the worst case scenario like if the element we are looking for is at the end of the array of length n then its `O(n)`
	- `O(n)` can be `O(1)` if the element we are looking for is at the 0th index but this is not guaranteed
- nested loop doesn't always imply `O(n^2)`
	- but `O(n^2)` can have nested loops
- when searching a 1-D loop twice it is `O(2n)`
	- so doing it n times it is `O(n^2)`
- suppose we have a 1-D array of length n and first we traverse from 0th index to (n-1)th index
	- then in the 2nd pass we skip the 0th element and start from 1st element. next pass from skip the 0th, 1st element and start from 2nd element and so on
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
- in case of recursion if the reucrsive function calls itself 2 times it is `O(2^n)` as each call creates 2 more calls and each of the 2 create 2 more so it can be 2^0, 2^1 or 2^2 calls and so on
	- so if a recursive function is called in a loop m times then it is `O(m^n)`
- `O(n!)` is the worst
- <mark style="background: #D2B3FFA6;">efficiency decreases as gradient increases</mark>
	- ![time vs input size](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-21%2009-52-29.png)
- <mark style="background: #D2B3FFA6;">array/vector/string</mark>
	- read is `O(1)`
	- insert/delete are `O(n)`
- <mark style="background: #D2B3FFA6;">singly linked list(forward_list)</mark>
	- read is `O(n)`
	- insert/delete at the start is `O(1)`
		- at the end is `O(n)`
		- anywhere else `O(n)`
- <mark style="background: #D2B3FFA6;">doubly lined list(list)</mark>
	- read is `O(n)`
	- insert/delete at the start is `O(1)`
		- at the end is `O(1)`
		- anywhere else `O(n)`
- <mark style="background: #D2B3FFA6;">dequeue</mark>
	- read is `O(n)`
	- insert/delete front/end is `O(1)`
- <mark style="background: #D2B3FFA6;">priority queue</mark>
	- read max/min element is `O(1)`
	- insert and delete is `O(log n)`
- <mark style="background: #D2B3FFA6;">stack</mark>
	- push, pop and top are `O(1)`
- <mark style="background: #D2B3FFA6;">queue</mark>
	- same as stack
- <mark style="background: #D2B3FFA6;">set</mark>
	- read, insert and delete is `O(log n)`
- <mark style="background: #D2B3FFA6;">multiset</mark>
	- read and insert are `O(log n)` and delete is `O(k log n)` where k is the number of duplicate entries
- <mark style="background: #D2B3FFA6;">map</mark> / <mark style="background: #D2B3FFA6;">multimap</mark>
	- read, insert and delete are `O(log n)`
- <mark style="background: #D2B3FFA6;">unordered map</mark>
	- read, insert and delete are `O(1)` on average, `O(n)` in the worst case
- <mark style="background: #D2B3FFA6;">pairs</mark>
	- read is `O(1)`

# <mark style="background: #FFB86CA6;">STL ADT</mark>
- c++ STL is a collection of useful algorithms, data structures and functions related to them in form of template classes
- c++ STL  has 4 things: containers, functions, algorithms and iterators
	- containers are the classes for the data structures
	- functions are primitive operations performed on the containers like push, pop
	- algorithms are complex operations performed on the containers like search, sort
	- iterators are used to access containers in a simpler way
- to import all the containers and common header files like iostream etc, use `#include<bits/stdc++.h>`
- <mark style="background: #D2B3FFA6;">Containers</mark>
	1. <mark style="background: #BBFABBA6;">array</mark>
		- inside the array template class a primitive array is used and `.data()` is a function that returns that underlying primitive array
		- an STL array can be indexed using overloaded `[]` operator or using `.at(x)` function
			- `.at(x)` function will throw an exception if the index is out of bounds but `[]` will give garbage value instead
		- length provided during declaration has to be a constant and can never be a variable so you cant user input the length
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		    cout << arr.at(4) << endl;   // 1
		    cout << arr.front() << endl; // 1
		    cout << arr.back() << endl;  // 10 returns the last element of the array container
		    cout << arr.size();          // 10 len of array
		
		    cout << *arr.begin() << endl;      // 1 returns the address of the first element of the array container and is used for looping
		    cout << *(arr.end() - 1) << endl;  // 10
		    cout << *arr.rbegin() << endl;     // 10
		    cout << *(arr.rend() - 1) << endl; // 1
		    cout << arr.empty() << endl;       // 0 checks if the array container is empty or not
		
		    // cout<<arr.swap(anotherArrContainer);
		
		    arr.fill(7); // array has all 10 elements equal to 7 and fill function is used to initialise
		
		    return 0;
		}
		```
	2. <mark style="background: #BBFABBA6;">vector</mark>
		- its a large array but not a linked list so when the array is filled then a new array is created and all the contents of the older array is copied to the new array
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    vector<int> v;
		
		    v.push_back(1); // {1}
		    v.push_back(2); // {1, 2}
		
		    // emplace_back is faster than push_back
		    v.emplace_back(3); // [1, 2, 3]
		    v.emplace_back(4); // [1, 2, 3, 4]
		    v.emplace_back(5); // [1, 2, 3, 4, 5]
		    v.emplace_back(6); // [1, 2, 3, 4, 5, 6]
		
		    v.erase(v.end() - 1); // to remove last element [1, 2, 3, 4, 5]
		    v.erase(v.begin());   // removes 1st element [2, 3, 4, 5]
		    // v.erase(startingIndexAddress,AdrOfLastElementToBeDeleted+1) can erase a range of elements if you provide
		
		    v.insert(v.begin(), 0); // [0, 2, 3, 4, 5]
		    // v.insert(address,howManyCopiesOf,ThisElement);
		    // to insert vector cpy into v: v.insert(Address, cpy.begin(),cpy.endl);
		
		    cout << v.front() << " " << v.back() << endl; // 0 5
		
		    for (auto itr = v.begin(); itr != v.end(); itr++) // 0 2 3 4 5
		        cout << *itr << " ";
		
		    cout << endl;
		
		    for (auto itr = v.rbegin(); itr != v.rend(); itr++) // 5 4 3 2 0
		        cout << *itr << " ";
		
		    cout << endl;
		
		    v.assign({1, 2, 3, 4, 5});
		    for (auto x : v) // 1 2 3 4 5
		        cout << x << " ";
		
		    cout << endl;
		
		    // v.capacity() is the max length of the vector including buffer capacity
		    // v.resize() changes the size and not the capacity but can change capacity if the size is full
		    // v.reserve() changes the capacity
		    // v.clear() resets the vector
		    // v.shrink_to_fit() releases unused memory
		    // v.at(), v.swap(), v.data(), v.empty(), v.size() is same as arrays
		
		    vector<pair<int, int>> vpair;
		    vpair.push_back({1, 2});  // need to use flower braces to specify a pair
		    vpair.emplace_back(3, 4); // automatically infers that it is a pair with emplace_back
		
		    vector<int> hundred(5, 100); // creates {100,100,100,100,100}
		    vector<int> bydefault(5);    // creates {0,0,0,0,0}
		
		    vector<int> temp(v); // creates a seperate copy of v and names it temp
		
		    return 0;
		}
		```
	3. <mark style="background: #BBFABBA6;">list</mark>
		- doubly linked list
		-  ![doubly linked list](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/DLL1.png)
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
	4. <mark style="background: #BBFABBA6;">forward list</mark>
		- same as list but singly linked list instead
		- can traverse only in one direction
	5. <mark style="background: #BBFABBA6;">dequeue</mark>
		- doubly ended queues are queues but elements can be pushed and popped from both ends
			- ![dequeue](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/deque.png)
		- kinda like vectors but contiguous memory allocations is not guaranteed but front operations are allowed along with back operations
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    deque<int> dq;
		    // dq.assign();
		    // dq.at();
		    // dq.front();
		    // dq.back();
		    // dq.begin();
		    // dq.end();
		    // dq.emplace_back();
		    // dq.emplace_front();
		    // dq.pop_back();
		    // dq.push_front();
		
		    // dq.clear();
		    // dq.empty();
		    // dq.erase();
		
		    // dq.insert();
		    // dq.resize();
		    // dq.shrink_to_fit();
		    // dq.size();
		    // dq.swap();
		    return 0;
		}
		```
	6. <mark style="background: #BBFABBA6;">priority queue</mark>
		- also called max heap
			- like a heap(FIFO) that stores the largest element on the top
		- pop deletes the largest element 
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    priority_queue<int> pq;
		    // pq.emplace(); // emplace_back obviously as no front operations possible
		    // pq.empty();
		    // pq.pop(); // removes largest element
		    // pq.push();
		    // pq.size();
		    // pq.swap();
		    // pq.top(); // returns the topmost element of the heap which it the largest one
		    return 0;
		}
		```
	7. <mark style="background: #BBFABBA6;">stack</mark>
		- LIFO
		- stack of washed plates
		- same functions as priority_queue
		- push adds new element at the top of the stack
		- pop removes the topmost element
		- top reads the topmost element
		- useful for reversing without recursion
		- insert and delete happens from the same end
		```cpp
		// reverse string using stack
		#include <iostream>
		#include <stack>
		#include <cstring>
		using namespace std;
		
		void reverse(char str[], int len)
		{
		    stack<char> strack;
		    for (int i = 0; i < len; i++)
		        strack.push(str[i]);
		    for (int i = 0; i < len; i++)
		    {
		        str[i] = strack.top();
		        strack.pop();
		    }
		}
		
		int main()
		{
		    char str[50];
		    cout << "Enter String: ";
		    cin >> str;
		    reverse(str, strlen(str));
		    cout << str;
		    return 0;
		}
		```
		- <mark style="background: #FF5582A6;">bracket balancing</mark>
			- in code editors the linter checks if an opening bracket in a expression is closed before the expression ends
			- this operation uses stack and is called check for balanced parenthesis
			- every opening bracket should have a closing pair so that it is balanced and expression is valid
			- saying number of opening brackets should be equal to number of closing ones is incomplete as `)a+b(` or `[(])` are invalid
			- so the rules are:
				- an opening bracket should have a closing one to its right and not its left
				- a bracket can be closed only if all the brackets opened inside it are already closed
				- last unclosed bracket should be closed first `[()()]`
				- scan from left to right
				- if opening bracket add it to the stack and if closing found then remove the topmost closing bracket type from the stack
				- at the end the stack should be empty to conclude the expression as valid
	8. <mark style="background: #BBFABBA6;">queue</mark>
		- FIFO
		- more used than stack irl
		- used when there is a shared resource and it can only handle only one resource at a time like a printer or a processor
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    queue<int> q;
		    // q.front();
		    // q.back();
		    // q.empty();
		    // q.pop();
		    // q.push();
		    // q.size();
		    // q.swap();
		    return 0;
		}
		```
	9. <mark style="background: #BBFABBA6;">set</mark>
		- no duplicates so every element in a set is unique
		- stored as sorted
		```cpp
		#include <bits/stdc++.h>
		using namespace std;
		int main()
		{
		    set<int> s;
		
		    s.count(); // returns number of occurences of an element in the set and makes sense only for multisets as fo sets it is always 1
		
		    // s.find(); // returns iterator pointing to the desired element and returns s.end() if not found
		    // s.insert(); // element to be inserted is passed and it returns a pair of the iterator pointing to place where it might be inserted, bool if it was inserted or not
		
		    // s.emplace();
		    // s.begin();
		    // s.end();
		    // s.clear();
		    // s.empty();
		    // s.erase();
		    // s.size();
		    // s.swap();
		    return 0;
		}
		```
	10. <mark style="background: #BBFABBA6;">multiset</mark>
		- same as set with the same functions but allows duplicate entries and still are sorted
	11. <mark style="background: #BBFABBA6;">map</mark>
		- like arrays but the indices are called keys and keys can be of any data type
		- stores key-value pairs and all keys must be unique and keys are stored in sorted order
		- functions like set
	12. <mark style="background: #BBFABBA6;">multimap</mark>
		- same functions as a map but allows duplicate keys but the key-value pairs must be unique
			- hence `.at()` function not available
	13. <mark style="background: #BBFABBA6;">unordered map</mark>
		- like map but keys are not stored in sorted order
		- has some unique bucket functions
	14. <mark style="background: #BBFABBA6;">pairs and nested pairs</mark> 
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
	- there are different iterators for different containers
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
	// we can replace occurences of vector with list or forward_list or dequeue or set and not other changes are needed
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
<mark style="background: #D2B3FFA6;">Array</mark>
```cpp
#include <iostream>
using namespace std;
class concreteArray
{
    int *arrptr, size, len;
    void swap(int *x, int *y);

public:
    concreteArray(int size = 10)
    {
        this->size = size;
        len = 0;
        arrptr = new int[size];
    }
    ~concreteArray()
    {
        delete[] arrptr;
    }
    void Print(), Append(int x), Insert(int index, int x), Set(int index, int x) throw(string), ReverseMethodOne(), ReverseMethodTwo(), InsertSort(int x);
    int Delete(int index) throw(string), LinearSearch(int key), BinarySearch(int key), Get(int index), Min(), Max(), Sum();
    float Avg();
    bool isSorted();
};

void concreteArray::Print()
{
    if (len == 0)
    {
        cout << "Array is empty";
        return;
    }
    cout << "[ ";
    for (int i = 0; i < len; i++)
        cout << arrptr[i] << " ";
    cout << "]" << endl;
}

void concreteArray::Append(int x)
{
    if (len == size)
    {
        cout << "Array is full, cannot append" << endl;
        return;
    }
    arrptr[len] = x;
    len++;
}

void concreteArray::Insert(int index, int x)
{
    if (len == size)
    {
        cout << "Array is full, cannot insert" << endl;
        return;
    }
    else if (index < 0 || index > len)
    {
        cout << "Invalid index" << endl;
        return;
    }
    for (int i = len; i > index; i++)
        arrptr[i] = arrptr[i - 1];
    arrptr[index] = x;
    len++;
}

int concreteArray::Delete(int index) throw(string)
{
    if (index < 0 || index > len)
    {
        cout << "Invalid index" << endl;
        throw string("badIndex");
    }
    int deletedValue = arrptr[index];
    for (int i = index; i < len - 1; i++)
        arrptr[i] = arrptr[i + 1];
    len--;
    return deletedValue;
}

void concreteArray::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int concreteArray::LinearSearch(int key)
{
    for (int i = 0; i < len; i++)
        if (arrptr[i] == key)
        {
            if (i != 0)
                swap(&arrptr[i], &arrptr[0]);
            return i;
        }
    return -1;
}

int concreteArray::BinarySearch(int key)
{
    int l = 0, h = len - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (key == arrptr[mid])
            return mid;
        else if (key < arrptr[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int concreteArray::Get(int index) { return (index < 0 || index > len) ? -1 : arrptr[index]; }

void concreteArray::Set(int index, int x) throw(string)
{
    if (index < 0 || index > len)
    {
        cout << "Invalid index" << endl;
        throw string("badIndex");
    }
    arrptr[index] = x;
}

int concreteArray::Max()
{
    int max = arrptr[0];
    for (int i = 1; i < len; i++)
        max = arrptr[i] > max ? arrptr[i] : max;
    return max;
}

int concreteArray::Min()
{
    int min = arrptr[0];
    for (int i = 1; i < len; i++)
        min = arrptr[i] < min ? arrptr[i] : min;
    return min;
}

int concreteArray::Sum()
{
    int sum = arrptr[0];
    for (int i = 1; i < len; i++)
        sum += arrptr[i];
    return sum;
}

float concreteArray::Avg() { return (float)(Sum() / len); }

void concreteArray::ReverseMethodOne()
{
    int *temparrptr = new int[size];
    for (int i = 0; i < len; i++)
        temparrptr[len - 1 - i] = arrptr[i];
    delete[] arrptr;
    arrptr = temparrptr;
    temparrptr = nullptr;
}

void concreteArray::ReverseMethodTwo()
{
    for (int i = 0; i < len; i++)
        swap(&arrptr[i], &arrptr[len - 1 - i]);
}

void concreteArray::InsertSort(int x)
{
    if (len == size)
    {
        cout << "Array is full, cannot insert" << endl;
        return;
    }
    int i;
    for (i = len - 1; i >= 0 && arrptr[i] > x; i--)
        arrptr[i + 1] = arrptr[i];
    arrptr[i + 1] = x;
    len++;
}

bool concreteArray::isSorted()
{
    for (int i = 0; i < len - 1; i++)
        if (arrptr[i] > arrptr[i + 1])
            return false;
    return true;
}t
```

<mark style="background: #D2B3FFA6;">Singly Linked List</mark>
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
- is a binary tree with value of <mark style="background: #BBFABBA6;">left child node</mark> of a parent node always <mark style="background: #BBFABBA6;">smaller than or equal to</mark> the value of <mark style="background: #BBFABBA6;">parent node</mark> and the value of <mark style="background: #BBFABBA6;">right child node</mark> of a parent node always <mark style="background: #BBFABBA6;">larger than or equal to</mark> the value of <mark style="background: #BBFABBA6;">parent node</mark>
- used for effectively searching
- <mark style="background: #BBFABBA6;">recursion is used for common operations as tree has unidirectional next nodes, </mark> we use stack of activation record of function in recursive calls to remember the address of parental nodes
- to check validity, n nodes = n-1 connecting links
- <mark style="background: #BBFABBA6;">depth</mark>
	- depth is measured <mark style="background: #BBFABBA6;">from the topmost node of the tree</mark>
	- So <mark style="background: #BBFABBA6;">root of the tree has depth 0</mark>
- <mark style="background: #BBFABBA6;">height</mark>
	- height of a node in a tree is equal to <mark style="background: #BBFABBA6;">the number of connecting links needed to reach that node from the furthest leaf(a node without any child) under that node</mark>
	- <mark style="background: #BBFABBA6;">height of all leaves is 0</mark>
	- <mark style="background: #BBFABBA6;">height of a tree is height of the topmost node of the tree</mark>
	- <mark style="background: #BBFABBA6;">height if an empty tree is -1</mark>
	- <mark style="background: #BBFABBA6;">height of a tree with one node is 0</mark> and so on
	- <mark style="background: #BBFABBA6;">height if a tree with n nodes is n-1</mark> which is equal to the number of connecting links
- <mark style="background: #BBFABBA6;">max number of nodes for a node at height h</mark> `= (2^h)-1`
- <mark style="background: #BBFABBA6;">a binary tree for which any node either has 2 or 0 nodes</mark> is called a <mark style="background: #BBFABBA6;">perfect binary tree and height of a perfect binary tree</mark> `= floor(log base2 of n)` where n is number of nodes
- <mark style="background: #BBFABBA6;">cost is proportional to the height of the tree</mark>
	- the <mark style="background: #BBFABBA6;">height is lesser if the tree is denser and a tree is denser if it is a perfect binary tree</mark>
	- more a <mark style="background: #BBFABBA6;">binary tree is perfect, denser it is</mark>
	- <mark style="background: #BBFABBA6;">linked list is the most imperfect binary tree as every node will have one node</mark>
	- tree operations are `O(height)` so for a perfect binary tree `O(log base2 of n)` and `O(n)` for a linked list
	- for tree `O(n)` is worse than `O(height)` as `height = log base2 of n`
- <mark style="background: #BBFABBA6;">try keeping the tree balanced</mark>, a balanced tree is one <mark style="background: #BBFABBA6;">for which (ht of left child sub tree of parent) - (ht of right child sub tree of parent) = 0 or 1</mark>
- ![binary tree array](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-23%2022-31-43.png)
- ![why use binary search tree](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-23%2023-18-36.png)
- in a binary search tree <mark style="background: #BBFABBA6;">at every step you compare the value you are looking for with the value at the node and if it is match you stop</mark>
	- <mark style="background: #BBFABBA6;">else you discard left or right sub tree after comparing</mark> the value you are looking for with the value at the current node
- ![this is insertion](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-23%2023-29-47.png)
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
} *rootptr = NULL; // this points to the root node and is not the root node itself

node *getsetNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *rootptr, int data)
{
    if (rootptr == NULL) // breaking condition for recursion
        rootptr = getsetNode(data);
    // these ifs below help to locate the position for new node in the tree and the new node can only be inserted if the left or right of another node points to NULL
    else if (data <= rootptr->data)
        rootptr->left = insert(rootptr->left, data);
    else
        rootptr->right = insert(rootptr->right, data);
    return rootptr;
}
/**
 * for deleting a node which has 2 child subtree we find the min of right subtree and replace it with the node to be deleted and remove the duplicate in right tree
 * max of left is also allowed
 */

bool search(node *rootptr, int target)
{
    if (rootptr == NULL)
        return false;
    else if (rootptr->data == target)
        return true;
    else if (target <= rootptr->data)
        return search(rootptr->left, target);
    else
        return search(rootptr->right, target);
}

/**
 * to find the ht of the tree: O(n) where n is the number of nodes
 * pseudo code
 * findht(root){
 *      if root is null return -1 // if we find a leaf node its ht will be 0 which is -1 + 1
 *      leftht=findht(root->left)
 *      rightht=findht(root->right)
 *      return (max of leftht and rightht)+1
 * }
 */

int findht(node *rootptr)
{
    if (rootptr == NULL)
        return -1;
    int leftht = findht(rootptr->left);
    int rightht = findht(rootptr->right);
    return leftht > rightht ? leftht + 1 : rightht + 1;
}

/**
 * bfs uses queue. s soon as we find a node we add its address to the queue
 * then u access it and pop the last node from queue and enqueue its child nodes
 * traversal is completed when the queue is empty
 * time complexity: O(n)
 * space complexity: O(n) in perfect tree or O(1) in linked list
 */
void printBFS(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop();
    }
    cout << endl;
}

int main()
{
    cout << "[1] to insert\n[2] to search\n[3] to show ht\n[4] BFS print\n[5] to quit\n\n";
    int ch;
    while (true)
    {
        do
        {
            cout << "Enter choice: ";
            cin >> ch;
        } while (ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5);
        switch (ch)
        {
        case 1:
            cout << "Insert: ";
            int ins;
            cin >> ins;
            rootptr = insert(rootptr, ins);
            break;
        case 2:
            cout << "Enter Query: ";
            int query;
            cin >> query;
            if (search(rootptr, query))
                cout << "Found" << endl;
            else
                cout << "NOT Found" << endl;
            break;
        case 3:
            cout << "Ht of BINARY SEARCH TREE IS " << findht(rootptr) << endl;
            break;
        case 4:
            printBFS(rootptr);
            break;
        case 5:
            return 0;
        }
    }
}
/**
 * binary tree traversal is visiting all the elements of the tree exactly once
 * 2 ways
 * bfs is visiting all nodes at a level(top to bottom) from left to right
 * dfs if we area at a child then we completely visit the entire subtree of that child
 *      3 ways
 *      preorder    root->left subtree->right subtree short form data left right dlr
 *      inorder     left subtree->root->right subtree short form left data right dlr
 *      postorder   left subtree->right subtree->root short form left right data dlr
 *      data means read or access the data before moving to the next subtree
 */
```

<mark style="background: #D2B3FFA6;">Graphs</mark>
- <mark style="background: #BBFABBA6;">linked list and trees are also graphs</mark>
- <mark style="background: #BBFABBA6;">graphs have no restrictions on connecting links between nodes</mark>
- a graph is represented as G=(V,E) where G is an ordered pair of vertices and edges
	- <mark style="background: #BBFABBA6;">vertices are nodes</mark>
	- an <mark style="background: #BBFABBA6;">edge is the connecting link between two nodes</mark>
		- <mark style="background: #BBFABBA6;">an edge can be directed(one way) or undirected(two way)</mark>
		- <mark style="background: #BBFABBA6;">an edge can have weights like distance between two cities</mark>
			- <mark style="background: #BBFABBA6;">when graph is weighted</mark> we cannot just rely on the number of edges between 2 vertices <mark style="background: #BBFABBA6;">to find the shortest path as we need to consider weights</mark>
			- <mark style="background: #BBFABBA6;">all weights for an unweighted graphs are 1</mark>
- <mark style="background: #BBFABBA6;">graph can have self loops</mark> <mark style="background: #BBFABBA6;">meaning vertex has an edge pointing to itself</mark>
	- <mark style="background: #BBFABBA6;">like how many websites have links to the same page</mark> and that is an example of self loop
	- <mark style="background: #BBFABBA6;">refresh page on the browser leads to the same page</mark>
- <mark style="background: #BBFABBA6;">two vertices can have multiple edges between them example multiple airlines fly between 2 same airports</mark>
-<mark style="background: #BBFABBA6;"> a simple graph has no self loop or multiple edges</mark>
- for a <mark style="background: #BBFABBA6;">simple directed graph the max number of edges for n vertices</mark> `= n(n-1)`
- for a <mark style="background: #BBFABBA6;">simple undirected graph the max number of edges for n vertices</mark> `= n(n-1)/2` 
- <mark style="background: #BBFABBA6;">a denser graph has number of edges closer to the max limit else its sparse</mark>
	- <mark style="background: #BBFABBA6;">for a dense graph we use adjacency matrix and for sparse we use adjacency list</mark>
- <mark style="background: #BBFABBA6;">path</mark>
	- <mark style="background: #BBFABBA6;">simple path when vertices/edges are not repeated</mark>
	- <mark style="background: #BBFABBA6;">if repeated it is a walk</mark>
		- <mark style="background: #BBFABBA6;">closed walk when start and end is the same vertex</mark> <mark style="background: #BBFABBA6;">also called cycle</mark>
			- trees are acyclic
			- singly and doubly linked lists are acyclic but we also have <mark style="background: #BBFABBA6;">cyclic/circular linked list where the last node points to the 1st node (not the head)</mark>
	- <mark style="background: #BBFABBA6;">trail when edges are not repeated but vertices are</mark>
	- <mark style="background: #BBFABBA6;">representing graph</mark> in memory
		- <mark style="background: #BBFABBA6;">using 2 vectors</mark>
			- <mark style="background: #BBFABBA6;">one stores the content of the vertex called vertex list</mark>
			- and <mark style="background: #BBFABBA6;">edge list which is a vector of a struct</mark> and <mark style="background: #BBFABBA6;">stores 2 integers that indicate a link between the same indices corresponding to the vertex list</mark> <mark style="background: #BBFABBA6;">(and weight also if needed)</mark>
			- we know every vertex stored in the vertex list vector has an index
			- we can imagine that an edge connects these indices instead of pointing to them
			- ![creating a graph](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-25%2014-25-06.png)
-  <mark style="background: #D2B3FFA6;">Common Operations</mark>
	- <mark style="background: #BBFABBA6;">finding adjacent nodes,</mark> <mark style="background: #BBFABBA6;">checking if 2 nodes are connected is</mark> `O(number of Edges or |E|)` which is nearly `O(n^2)` as we know the formula for max number of edges from the number of nodes
	- `O(n)` is acceptable which is `O(number of vertices or |V|)` for graphs <mark style="background: #BBFABBA6;">Using Adjacency Matrix and Adjacency List</mark>
		- <mark style="background: #BBFABBA6;">Adjacency Matrix</mark> of order `|V| x |V|`
			- <mark style="background: #BBFABBA6;">better for dense graphs because we will store many 0s for a sparse graph</mark>
			- <mark style="background: #BBFABBA6;">huge storage footprint</mark>
			- <mark style="background: #BBFABBA6;">we have a vertex list of length equal to the total number of vertices in the graph</mark>
				- if the length of vertex list be p then the adjacency matrix is `pxp` 
			- <mark style="background: #BBFABBA6;">for any element at index i of the vertex list, row i of adjacency matrix has values 0 or 1 for every column</mark>
				- for column number c and row number r of the adjacency matrix if the value is 1 it means that the element at index r of the vertex list is connected to the element at index c of the vertex list in the graph and 0 means it is not connected
			- <mark style="background: #BBFABBA6;">for any undirected graph the adjacency matrix will be symmetric</mark> so `Aij == Aji` so we can omit upper or lower triangular matrix with diagonal of matrix as the hypotenuse
			-  ![adjacency matrix of a graph](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-25%2014-39-31.png)
			- <mark style="background: #BBFABBA6;">to find adjacent nodes we do a linear search on the vertex list and then do a linear search on the row of adjacency matrix</mark> corresponding to the index found in vertex list
				- which is `O(V+V) = O(2V) = O(V)`
			- <mark style="background: #BBFABBA6;">to find if 2 nodes are connected or not</mark> we can pass their indices i and j and we just need to <mark style="background: #BBFABBA6;">find the value of A[i][j] in the Adjacency matrix and see if it is 0 or 1</mark> which is `O(1)`
				- if the alphabets are given then we need to do a linear search to find the index in the vertex list making it `O(V)`
				- this can be avoided by using hash map so it will always be `O(1)`
			- <mark style="background: #BBFABBA6;">for weighted graph replace 1 with edge weight and 0 with INT_MAX</mark>
			- <mark style="background: #BBFABBA6;">for facebook, using adjacent matrix optimally means for 1 billion users everyone is a friend of everyone else which is impossible so lot of memory is wasted in storing who is not a friend of whom which is redundant as we can figure that out if we just knew who is a friend of who which is infact more important</mark>
		- So we use <mark style="background: #BBFABBA6;">Adjacency List</mark> which is an array of pointers
			- less memory as space complexity is `O(number of edges)` as `|E| << |V|^2`
			- ![Adjacency List](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-25%2021-00-55.png)
			- we <mark style="background: #BBFABBA6;">need to perform linear search or binary search on the adjacency list so for finding if 2 nodes are connected</mark> `O(|V|)` or `O(log |V|)` which was `O(1)` in Adjacency Matrix
			- <mark style="background: #BBFABBA6;">finding adjacent nodes(all the neighbors of a node) is O(v) same as Adjacency Matrix</mark>
			- <mark style="background: #BBFABBA6;">Adjacency Matrix used when the graphs is dense</mark> and |V| and |E| are small otherwise Adjacency List is practically preferred over Adjacency Matrix most of the time
	- <mark style="background: #BBFABBA6;">adding a new edge</mark>
		- <mark style="background: #BBFABBA6;">for adjacency matrix flip a zero to one</mark>
		- <mark style="background: #BBFABBA6;">for a list if we are using array of pointers we need to create a new array and copy previous elements into it and then add the new one</mark>
			- so <mark style="background: #BBFABBA6;">use linked list instead? yes</mark> and each pointer in the array points to the head of a linked list and the node will store weight if the graph is weighted
			- <mark style="background: #BBFABBA6;">Adjacency List always uses Linked List and not array or vector</mark>