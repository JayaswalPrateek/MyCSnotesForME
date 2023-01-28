 ***Big O***
- O(1) are the most efficient algorithms as they scale really well because the execution time is independent of the input size
	- like searching a value in map using its key.
- O(n) means the execution time is linearly dependent on the input size
	- searching for an element in an array
	- we usually take the worst case scenario like if the element we are looking for is at the end of the array for an array of length n then its O(n)
	- O(n) can be O(1) if the element we are looking for is at the 0th index but this is not guaranteed
- nested loop doesn't always imply O(n^2)
- but O(n^2) can have nested loops
- if i am searching i 1-D loop twice it is O(2n)
	- so if i doing it n times it is O(n^2)
- suppose we have a 1-D array of length n and first we traverse from 0th index to (n-1)th index
	- then in the 2nd pass we skip the 0th element and start from 1st element. next pass from 2nd one and so on.
	- so we will have a total of n passes for an array of length n
	- if we draw the array one below the other for every pass and erase the block we skip, we will get ◹
		- this has base and height n. the square had a O(n^2) this has O(n^2/2) but constant doesn't matter so its still O(n^2)
- if a 2-D matrix is not a square and has sides nxm then it will have O(n x M)
- O(log n)
	- we keep shrinking the array in half so we will never have to traverse all the n elements and always less than n so it will be O(log n)
	- so n=2^x where n is the length and x is the no of times will have to split in half so take log both sides to get O(log n)
	- also used for binary trees
	- very efficient
- O(n log n ) is more efficient than 0(n^2) but less than O(n)
- imagine a tree which has 3 branches and each branch has 3 more branches and so on and if the height of the tree is n then O(3^n)
- O(n!) is very very bad and inefficient
- Efficiency increases from left to right


![time vs input size](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-01-21%2009-52-29.png)

***STL***
- classes that bundle common data structures and all the functions related to it.
- it has 4 things: functions,algorithms, containers and iterators
	- the operations to be performed on the data structures are called algorithms like sort and search and functions are like pop and push, union, intersection, begin end rbegin rend
	- the classes for data structures are called containers
		- this is STL: standard template classes as containers are of generic types
			- vector: dynamic array but not a linked list. copies the content of smaller array to larger one. not to be confused with string class
				- supports push back, pop back, insert, remove, is empty, size
			- list: are doubly linked list and have two nodes fwd and backward in the struct
				- functions same as vectors+ push front, pop front, front, back
			- forward list: singly linked list with functions same as doubly
			- dequeue: double ended queue, similar to vector but with functions like lists
			- priority queue: means max heap: so the largest element is deleted first
				- push, pop, empty, size
			- stack: lifo with same funcs as priority queue
			- set: duplicates are not allowed and order of storage is not guaranteed with func same as priority queue
			- multiset: same as set but allows duplicate
			- map is used to store key value pairs with all keys unique stores keys in sorted order
			- multi map allows duplicate keys but key value pair should be unique
			- unordered map needs unique keys but keys are not sorted
	- iterators are used to access container data
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
    {
        cout << x << " ";
    }
    cout << endl;
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " "; // becoz itr is a ptr which uses ptr arithmetic
    }
}
// u can replace occurences of vector with list or forward_list or dequeue or set
```
- for maps:
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
}
```

STL:
- to import all the containers and common header files like iostream etc, use `#include<bits/stdc++.h>`
- pairs and nested pairs
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
	}
	```
- vector are arrays with dynamic length without being a linked list.
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
	}
	```
- list
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
}
```
- dequeue
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
}
```
-  stack (lifo)
	- values are stored from bottom up using push/emplace and the last element is at the `top()`
	- cannot index like an array.
- queue (fifo)
	- `back()` instead of `top()`
- priority queue
	- largest element stays at the top of the stack called max heap
	- smallest element stays at the top of the stack called min heap
- set
	- stores only unique elements in a sorted order max heap
	- `someset.find(3);` returns them memory location of 3 in the set
		- if not in the set then it returns `someset.end();` which points after the end of the last element
- multiset
	- like set as in stores sorted like max heap while allowing duplicate elements
	- `.erase(3)` removes all occurrences of 3
		- to erase only a particular instance proved the address using .find which is always unique
	- `.count(3)` counts number of 3 in multiset
- unordered set
	- same as set but doesn't sort like max heap



***Bird Eye View***
- Arrays
	- Read is O(1) but inserting and deleting is O(n)
	- Reason: contiguous memory allocation is done so if next address is occupied then the array needs to be copied to another location contiguously
	can have unused memory
- singly Linked list:
	- opposite of array
	- read is O(n), insert and delete is O(1) if at the beginning, O(n) if at the end
	- they dont have indexes like arrays
	- address of the head node is stored and used and the last nodes points to null
	- no unused memory but pointer needs memory
- doubly linked list:
	- ![doubly linked list](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/DLL1.png)
- hash maps are like arrays but indices can be of any data type
	- read insert delete are all O(1)
- stack: stack of washed plates
	- lifo
	- push,pop and peek are O(1)
	- push adds new element at the top of the stack
	- pop removes the topmost element
	- peek reads the topmost element
	- useful for reversing without recursion
	- inset and delete happen from the same end
- queue
	- fifo
	- enqueue adds new element at the end of the queue O(1)
	- dequeue is the pop for the stack removes front most element O(1)
	- front reads the frontmost element O(1)
	- more used than stack
	- insert happens at one end and delete happens from other
	- used when there is a shared resource and it can only handle only one resource at a time like printer or processor
- binary search trees
	- a binary search tree is a binary tree that has the left child node lesser than or equal to the parent node and the right child node larger than or equal to the parent node
	- a right child node of a left parent node cannot be greater than the grandparent node
	- used for searching efficiently
	- recursive data structure
		- as tree has unidirectional links, recursion allows to maintain previous nodes in stack's activation record
	- a tree with n nodes has n-1 links always. used to check validity of tree
	- depth and height
		- root has depth 0, depth measured from topmost root
		- height of some node is the number of links to reach it from the furthest child so measured from leaf(childless node) and height of a leaf=0
			- ht of tree=ht of node
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
