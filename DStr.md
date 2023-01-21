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
	- if we draw the array one below the other for every pass and erase the block we skip, we will get 
		```
		------------,
		\			|
		  \			|
			\		|
			  \		|
			    \   |
				  \ |
		```
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
![[Screenshot from 2023-01-21 09-52-29.png]]
***Bird Eye View***
- Arrays
	- Read is O(1) but inserting and deleting is O(n)
	- Reason: contiguous memory allocation is done so if next address is occupied then the array needs to be copied to another location contiguously
- Linked list:
	- opposite of array
	- read is O(n) insert and delete is O(1)
	- they dont have indexes
- hash maps are like arrays but indices can be of any data type
	- read insert delete are all O(1)
- stack: stack of washed plates
	- lifo
	- push,pop and peek are O(1)
	- push adds new element at the top of the stack
	- pop removes the topmost element
	- peek reads the topmost element
- queue 
	- fifo
	- enqueue adds new element at the end of the queue O(1)
	- dequeue is the pop for the stack removes front most element O(1)
	- front reads the frontmost element O(1)
	- more used than stack
- binary search trees
	- used for searching efficiently
	- a tree where every node can have only 2 child nodes and the left child node should be lesser than parent node and the right child node should be greater than the parent node 
- graphs 
	- linked lists and binary search trees are also types of graphs
	- less restrictions than linked lists and binary search trees