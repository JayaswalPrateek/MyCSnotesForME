# <mark style="background: #FFB86CA6;">Overview of important Algorithms</mark>
- <mark style="background: #D2B3FFA6;">Searching</mark>
	- <mark style="background: #BBFABBA6;">Binary Search</mark>
	- <mark style="background: #BBFABBA6;">Depth First Search</mark> for trees and graphs 
		- uses stack or recursion
		- start from the top of a tree and go as deep as possible along the same branch
		- once you are at the bottom then go to nearest unvisited node usually a sibling of the deepest node
			- this process is called **Backtracking**
		- used to solve a maze, detecting cyclic graphs
		- `O(number of nodes + number of branches)`
	- <mark style="background: #BBFABBA6;">Breadth First Search</mark> for trees and graphs
		- uses queue or recursion
		- you don't go to deepest point like DFS
		- instead you make sure that the sibling node has been visited
		- once you are on a node look at its children and add them to a queue and then you visit the node in the queue and add them to visited array and remove them from sibling queue
		- if the node in the queues has more children then add them to queue when marking it visited
		- used in chess
		- `O(number of nodes + number of branches)`
	- ![BFS and DFS](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/BFS-DFS.png)
- <mark style="background: #D2B3FFA6;">Sorting</mark>
	- <mark style="background: #BBFABBA6;">Insertion Sort</mark>
		- compares the nth element with (n+1)th element and swaps them if nth element is larger
		- best case `O(n)` if everything is already sorted
		- worst case `O(n^2)` when nothing is sorted beforehand
	- <mark style="background: #BBFABBA6;">Merge Sort</mark>
		- divide and conquer and conquer by divide and conquer and so on
		- recursion is used
		- splits array in half till we have pairs of 2
		- then all pairs of 2 are sorted and then 2 pairs of 2 are merged and sorted till the array is completely merged back again
		- best and worst case are same `O(n log n)`
	- <mark style="background: #BBFABBA6;">Quick Sort</mark>
		- recursive like merge sort so divides and conquers
		- we choose a pivot element of the array which is closest to the median of the array elements
		- then we split the lists into 2 such that one list has elements smaller than the pivot element and one where all elements are greater than the pivot element
		- we repeat the same on these 2 lists
		- we move the pivot element to the end of the list
		- we place 2 pointers one on the 0th index and the 2nd on the 2nd last element and compare the two if the 0th one is larger we swap
		- deep doing it till the 2 pointers meet
		- when they meet replace that element with the last one
		- we know have 2 lists like we wanted and we can do the same thing on them individually
		- best case `O(n log n)`
		- worst case `O(n^2)`
		- still can be 2 to 3 times faster than merge sort by reducing the chances of worst case
		- needs less memory `O(log n)` than merge sort `O(n)`
- <mark style="background: #D2B3FFA6;">Greedy Algorithm</mark>
	- it makes the best possible decision at every local step
	- when not to be greedy
		- not meant for efficiency
	- when to be greedy
		- when you don't want to find the most efficient way out of millions of permutations then greedy might be a good enough solution
		- when optimal solution not possible and brute force is not acceptable become greedy

# <mark style="background: #FFB86CA6;">Recursion</mark>
- a recursive function should have a terminating condition also called as a base condition
	- the values in the scope of the function can be used before(ascending) or after(descending) the termination condition and recursive call
		```cpp
		#include <iostream>
		using namespace std;
		
		void head(int n)
		{
		    if (n > 0)
		    {
		        head(n - 1);
		        cout << n << " ";
		    }
		}
		
		void tail(int n)
		{
		    if (n > 0)
		    {
		        cout << n << " ";
		        tail(n - 1);
		    }
		}
		
		int main()
		{
		    head(10);
		    cout << endl;
		    tail(10);
		
		    return 0;
		}
		// 1 2 3 4 5 6 7 8 9 10
		// 10 9 8 7 6 5 4 3 2 1
		```
- use <mark style="background: #D2B3FFA6;">static variables in recursive function when you need a counter and don't want the counter to reset on every recursive call</mark>
	- static variable will have a single copy for all recursive calls and will not be a local variable of the scope of a recursive function
	- it is like global but more restricted 
- types of recursion
	- <mark style="background: #D2B3FFA6;">tail</mark>
		- when the function calls itself in the last line of the function
		- easier to convert recursive logic to iterative
	- <mark style="background: #D2B3FFA6;">head</mark>
		- when the function calls itself in the first line of the function
		- harder to convert recursive logic to iterative 
	- <mark style="background: #D2B3FFA6;">tree</mark>
		- opposite of tree recursion is linear recursion when the recursive function calls itself only one time
		- in tree recursion the recursive function calls itself more than one times
		```cpp
		#include <iostream>
		using namespace std;
		void tree(int n)
		{
		    if (n > 0)
		    {
		        cout << n << " ";
		        tree(n - 1);
		        tree(n - 1);
		    }
		}
		
		int main()
		{
		    tree(3);
		    return 0;
		}
		// 3 2 1 1 2 1 1
		// Time O(2^n)
		// Space O(n)
		```
		- ![tree recursion](https://github.com/JayaswalPrateek/MyCSnotesForME/blob/main/Attachments/Screenshot%20from%202023-02-02%2010-09-59.png?raw=true)
	- <mark style="background: #D2B3FFA6;">indirect</mark>
		- when a function A calls B and B calls C and C calls A 
		```cpp
		#include <iostream>
		using namespace std;
		void funB(int n);
		
		void funA(int n)
		{
		    if (n > 0)
		    {
		        cout << n << " ";
		        funB(n - 1);
		    }
		}
		void funB(int n)
		{
		    if (n > 1)
		    {
		        cout << "\n"
		             << n << " ";
		        funA(n / 2);
		    }
		}
		
		int main()
		{
		    funA(20);
		    return 0;
		}
		// 20
		// 19 9
		// 8 4
		// 3 1
		```
		- ![indirect recursion](https://github.com/JayaswalPrateek/MyCSnotesForME/blob/main/Attachments/Screenshot%20from%202023-02-02%2010-26-43.png?raw=true)
	- <mark style="background: #D2B3FFA6;">nested</mark>
		- parameter of a recursive call function is the same function
		```cpp
		#include <iostream>
		using namespace std;
		int fun(int n)
		{
		    if (n > 100)
		        return n - 10;
		    return fun(fun(n + 11));
		}
		int main()
		{
		    cout << fun(95); // 91
			return 0;
		}
		```
		- ![nested recursion](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-02-02%2013-20-47.png)
- <mark style="background: #FF5582A6;">Implementing pow function from cmath using recursion</mark>
	```cpp
	#include <iostream>
	using namespace std;
	int pow(int k, int p) { return p == 0 ? 1 : pow(k, p - 1) * k; }
	int main()
	{
	    cout << "Enter constant and power: ";
	    int con, pwr;
	    cin >> con >> pwr;
	    cout << con << "^" << pwr << " = " << pow(con, pwr);
	    return 0;
	}
	```
	- <mark style="background: #FF5582A6;">optimization</mark> for 2^8 instead of multiplying 2 8 times shouldn't we half and square like (2^2)^4 = 4^4
		- this way we can reduce the stack height and increase memory efficiency
		- <mark style="background: #BBFABBA6;">so if the power is even we half it and then we square the constant</mark>
		- <mark style="background: #BBFABBA6;">else if the power is odd like 2^9 we can still do 2 x 2^8 and so on</mark> 
		```cpp
		#include <iostream>
		using namespace std;
		int pow(int k, int p) { return p == 0 ? 1 : p % 2 == 0 ? pow(k * k, p / 2)
		                                                       : k * pow(k * k, (p - 1) / 2); }
		int main()
		{
		    cout << "Enter constant and power: ";
		    int con, pwr;
		    cin >> con >> pwr;
		    cout << con << "^" << pwr << " = " << pow(con, pwr);
		    return 0;
		}
		```
- <mark style="background: #FF5582A6;">Taylor Series using recursion is a combination of sum till n, power, factorial using recursion</mark>
	- to print `e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + ... till n terms`
	- we <mark style="background: #BBFABBA6;">need to use static variables as 3 variables are involved but we can return only one</mark>
		- <mark style="background: #BBFABBA6;">the program will be less efficient if we don't use power and factorial as static variables as we will have to calculate the complete factorial over and over again</mark>
			- <mark style="background: #BBFABBA6;">if factorial would have been static we just need to multiply a new number with the factorial of the previous number as n! = n x (n-1)!</mark>
			- <mark style="background: #BBFABBA6;">similarly we have to find x^n every time but if static we can store x^(n-1) and  multiply x once</mark>
	```cpp
	#include <iostream>
	using namespace std;
	float e(int x, int n)
	{
	    if (n == 0)
	        return 1;
	
	    static float pwr = 1, fac = 1;
	    float res = e(x, n - 1);
	    pwr *= x;
	    fac *= n;
	    return res + pwr / fac;
	}
	int main()
	{
	    cout << "Enter x and n: ";
	    int x, n;
	    cin >> x >> n;
	    cout << "e^" << x << " till n precision is " << e(x, n);
	    return 0;
	}
	```
	- <mark style="background: #FF5582A6;">optimizing using Horner's Rule</mark>
		- earlier the number of times we were multiplying was `O(n^2)` but using Horner's Rule it can be `O(1)`
		- to print `e^x = 1 + x/1(1 + x/2(1 + x/3(1 + x/4 + ... till n terms)))`
			- we <mark style="background: #BBFABBA6;">keep taking commons out and this reduces number of multiplications that are needed to be performed</mark>
			- we <mark style="background: #BBFABBA6;">find the value for the innermost bracket lets say (1+ x/4) here and multiply it with the common multiple x/3 and add 1 to it and go on recursively</mark>
			- using iteration
				```cpp
				#include <iostream>
				using namespace std;
				float e(int x, int n)
				{
				    int res = 1;
				    for (; n > 0; n--)
				        res = 1 + x * res / n;
				    return res;
				}
				int main()
				{
				    cout << "Enter x and n: ";
				    int x, n;
				    cin >> x >> n;
				    cout << "e^" << x << " till n precision is " << e(x, n);
				    return 0;
				}
				```
			- using recursion
				```cpp
				#include <iostream>
				using namespace std;
				float e(int x, int n)
				{
				    static int res = 1;
				    if (n == 0)
				        return res;
				    res = 1 + x * res / n;
				    return e(x, n - 1);
				}
				int main()
				{
				    cout << "Enter x and n: ";
				    int x, n;
				    cin >> x >> n;
				    cout << "e^" << x << " till n precision is " << e(x, n);
				    return 0;
				}
				```
- <mark style="background: #FF5582A6;">Fibonacci Series</mark>
	- using recursion `O(2^n)`
		```cpp
		#include <iostream>
		using namespace std;
		int fibo(int n)
		{
		    if (n <= 1)
		        return n;
		    return fibo(n - 2) + fibo(n - 1); // as the function calls itself 2 times with n as arg so O(2^n)
		}
		```
		- ![fibonacci recursion tree](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-02-03%2023-24-52.png)
		- here we can see that fib(3) and fib(2) get calculated over and over as the value is not stored
			- it is a case of excessive recursion and we can fix it by using static variables
				- we create a static array that stores the fib(n) at index n and the default values for all the elements is -1 so we can check do we need to find fib(n) at every step so `O(n)` 
				- this process is called <mark style="background: #D2B3FFA6;">memoization</mark>
				```cpp
				#include <bits/stdc++.h>
				using namespace std;
				int fibo(int n)
				{
				    static vector<int> memo(n + 1, -1);
				    if (n <= 1)
				    {
				        memo[n] = n;
				        return n;
				    }
				    else if (memo[n - 2] == -1)
				        memo[n - 2] = fibo(n - 2);
				    if (memo[n - 1] == -1)
				        memo[n - 1] = fibo(n - 1);
				    return memo[n - 2] + memo[n - 1];
				}
				```
	- using iteration `O(n)`
		```cpp
		#include <iostream>
		using namespace std;
		int fibo(int n)
		{
		    if (n <= 1)
		        return n;
		    int t0 = 0, t1 = 1, s = 0;
		    for (int i = 2; i <= n; i++)
		    {
		        s = t0 + t1;
		        t0 = t1;
		        t1 = s;
		    }
		    return s;
		}
		```
-  <mark style="background: #FF5582A6;">nCr = n!/(r!*(n-r)!)</mark>
	- using iteration
		```cpp
		#include <iostream>
		using namespace std;
		int fac(int n)
		{
		    int res = 1;
		    for (int i = 1; i <= n; i++)
		        res *= i;
		    return res;
		}
		int main()
		{
		    cout << "Enter n and r: ";
		    int n, r;
		    cin >> n >> r;
		    if (r > n)
		    {
		        cout << "Invalid Input " << r << " grtr than " << n;
		        return -1;
		    }
		    cout << n << "C" << r << " = " << fac(n) / (fac(r) * fac(n - r));
		    return 0;
		}
		```
	- <mark style="background: #FF5582A6;">for recursion we need to use Pascal's Triangle</mark>
		- ![pascals triangle](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-02-04%2009-04-11.png)
			- here we have rows and cols and an element having both `\` and `/` points to elements whose sum is equal to itself
				- observe how 2C1 points to above elements 1C0 and 1C1 and 2C1 = 2 = 1C0 + 1C1 = 1 + 1
				- so we can say 6 is 4C2 is obtained from 3+3 of 3C1 and 3C2 which themselves are obtained from a sum
				- our base condition can be outlined by observing that the extreme leftmost and rightmost elements are always 1 and the topmost element is also always 1
				- so `nCr = (n-1)C(r-1) + (n-1)Cr`
				- we go bottom to up for recursion and then come down from top to bottom when returning
				```cpp
				#include <iostream>
				using namespace std;
				int C(int n, int r)
				{
				    if (r == 0 || n == r)
				        return 1; // extreme left and right base condition
				    return C(n - 1, r - 1) + C(n - 1, r);
				}
				int main()
				{
				    cout << "Enter n and r: ";
				    int n, r;
				    cin >> n >> r;
				    if (r > n)
				    {
				        cout << "Invalid Input " << r << " grtr than " << n;
				        return -1;
				    }
				    cout << n << "C" << r << " = " << C(n, r);
				    return 0;
				}
				```
- <mark style="background: #FF5582A6;">Tower of Hanoi</mark>
	- Question:
		- ![tower of hanoi question](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/tower_of_hanoi-6667.jpg)
		- Auxiliary pole is for helping like temp variable for swapping
			- discs are always sorted in the source pole
	- Procedure to Solution: `O(2^n)`
		- ![procedure to solution for tower of hanoi question](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Towers-Of-Hanoi.png)
	-  cases
		- <mark style="background: #BBFABBA6;">if the number of discs is one then just move it from pole 1 to 3</mark>
		- <mark style="background: #BBFABBA6;">if the number of discs are 2 then</mark>
			1. move the smaller disc to middle pole
			2. move the larger disc from 1st to the 3rd pole
			3. move the smallest disc from 2nd to 3rd pole
		- <mark style="background: #BBFABBA6;">if number of discs are 3 then</mark>
			1. ignore the largest disc (3rd disc) and move the 2 discs to 2nd pole as if the number of discs were 2
			2. move the largest disc to 3rd pole
			3. move the 2 discs in 2nd pole to the 3rd pole as if the number of discs were 2
		- <mark style="background: #BBFABBA6;">if number of discs are n then</mark>
			1. ignore the largest disc (nth disc) and move the n-1 discs to 2nd pole as if the number of discs were n and do this recursively
			2. move the largest disc (nth disc) to 3rd pole
			3. move the n-1 discs in 2nd pole to the 3rd pole as if the number of discs were n
		- ![tower of hanoi recursion tree](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/Screenshot%20from%202023-02-04%2010-07-15.png)
	```cpp
	#include <iostream>
	using namespace std;
	
	void toh(int n, int sp1, int mp2, int dp3)
	// source pole 1, middle pole 2 and destination pole 3 are just pole numbers and n discs are stored in sp1 and we want to move it to dp3 in a specific order
	{
	    if (n < 0)
	        return;
	    static int ctr = 0;
	    toh(n - 1, sp1, dp3, mp2); // move (n-1)th disc from sp1 to mp2 using dp3 as Auxiliary Pole
	    ctr++;
	    cout << "[Step " << ctr << "] move disc from " << sp1 << " to " << dp3 << endl; // print what was done in the above step
	    toh(n - 1, mp2, sp1, dp3);                                             // move (n-1)th disc from mp2 to dp3 using sp1 as Auxiliary Pole
	    // when n=1 the topmost pole is moved and then n=2 so the one below it is moved and so on
	}
	
	int main()
	{
	    toh(2, 1, 2, 3); // means sp1 is the 1st pole, mp2 is the 2nd pole and dp3 is the 3rd pole
	    return 0;
	}
	
	/**
	[Step 1] move disc from 1 to 3
	[Step 2] move disc from 1 to 2
	[Step 3] move disc from 3 to 2
	[Step 4] move disc from 1 to 3
	[Step 5] move disc from 2 to 1
	[Step 6] move disc from 2 to 3
	[Step 7] move disc from 1 to 3
	*/
	```
- <mark style="background: #FF5582A6;">Permutations of a String without swapping</mark>
	- number of possible permutations = (length of the string)!
	- imagine a tree which has the original string as the root node 
		- the number of children to this root node = length of the string and each child will be an element of the string(underlined in 2nd row)
			- these children will each be a parent to length - 1 nodes(the ones that are not underlined in the 3rd row) 
			- ![string permutation recursion tree](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/recursion-permutation-swap.jpg)
				-  a tree whose leaf nodes are the solution to the program is called a state space tree
	- we need a static flag array so that we can find out what elements of the string can be children as child and parent cannot be the same element
		- i is the counter variable for this array initially pointing to the 0th index
	- we also need a static result array to store the permutations of the original string
		- k is the counter variable for this array initially pointing to the 0th index
		- when we have used all the characters from the original string then the all flag array elements will be set to true then we can add the `\0` at the end and print it
		- so adding any element at index n of the original array to the result array leads to toggling of nth index of flag array to true meaning that the index or original array is already used once in the resultant array
	- check flag array for the first occurrence of `result[i]` is false
		- when found at i set `result[k] = original[i]` 
	- recursive call with k+1 and i should automatically reset to 0
	- backtracking is used as it is depth first algorithm
		- so below the recursive call reset the flag array at index i back to false
	```cpp
	#include <iostream>
	using namespace std;
	void permute(char strray[], int k = 0)
	{
	    static bool flag[10];
	    static char result[10];
	    if (strray[k] == '\0')
	    {
	        result[k] = '\0';
	        cout << result << endl;
	        return;
	    }
	    for (int i = 0; strray[i] != '\0'; i++)
	    {
	        bool *isOccupied = &flag[i];
	        if (!*isOccupied)
	        {
	            result[k] = strray[i];
	            *isOccupied = true;
	            permute(strray, k + 1);
	            *isOccupied = false;
	        }
	    }
	}
	
	int main()
	{
	    char s[] = "ABC";
	    permute(s);
	    return 0;
	}
	```
- <mark style="background: #FF5582A6;">Permutations of a String with swapping</mark>
	- 0th index is variable `l` and (length-1)th index is variable `h` and `i` is a local variable equal to `l` that increments till it is equal to (length-1)
	- swap element at `l` and element at `i`(which might be the same)
	- recursive call with `l+1` instead
		- base condition is to print string permutation when `l==i`
		- ![string permutation recursion tree](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/NewPermutation.png)
```cpp
#include <iostream>
#include <cstring>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void permute(char strray[], int h, int l = 0)
{
    if (l == h)
    {
        cout << strray << endl;
        return;
    }
    for (int i = l; i <= h; i++)
    {
        swap(strray[l], strray[i]);
        permute(strray, h, l + 1);
        swap(strray[l], strray[i]);
    }
}

int main()
{
    char s[] = "ABC";
    permute(s, strlen(s) - 1); // without -1 we will end up swapping '\0' as well so the elements after it will be ignored by cout
    return 0;
}
``` 

# <mark style="background: #FFB86CA6;">Matrices</mark>
- <mark style="background: #D2B3FFA6;">assuming square matrices are of order n start from index 1 and arrays start from index 0 so i, j is actually i-1, j-1</mark>
- <mark style="background: #D2B3FFA6;">2-D arrays can quickly get inefficient</mark> and end up wasting memory by storing information we don't need. Still they can be quickly read due to contagious memory allocations
- <mark style="background: #D2B3FFA6;">a diagonal matrix has all non diagonal elements equal to zero and the amount of space wasted increases as we increase order of a diagonal matrix</mark>
	- which <mark style="background: #BBFABBA6;">can instead be represented by a linear array of just the diagonal elements</mark>
	- so when i equals j then use ith or jth index of the linear array else use 0 and <mark style="background: #BBFABBA6;">this is called mapping</mark>
	- as performing operations on a diagonal matrix introduces lot of redundancy in the operations as we perform more operations on the zeroes instead of the diagonal elements
- <mark style="background: #D2B3FFA6;">a lower triangular matrix has all elements above the diagonal equal to zero(excluding the diagonal)</mark>
	- element at i,j is 0 when `i<j` and non-zero for `i>=j`
	- total number of non zero elements is `n(n+1)/2` and total number of zero elements are `(n^2)-(n(n+1)/2) = n(n-1)/2`
	- to store the elements below diagonal and including diagonal elements we need a linear array of size `n(n+1)2`
	- <mark style="background: #BBFABBA6;">row major mapping</mark>
		- 1st row of matrix has one non zero element, 2nd has 2, 3rd has 3 and so on  **◺**
			- the 1st element of the linear array is the 1st element of the 1st row
			- the 2nd element of the linear array marks the start of the 2nd row and the 3rd element marks the end
			- the 4th element of the linear array marks the start of the 3rd row and the 5th element marks its end 
		- i,j(they start from 1 not 0) of the 2-D matrix can be mapped to `(i(i-1)/2)+j-1`th index of the linear array
			- <mark style="background: #BBFABBA6;">the above mapping is called row major mapping as we fill the linear array by scanning the matrix from left to right then top to bottom like breadth first or row by row</mark>
	- <mark style="background: #BBFABBA6;">in column major mapping we fill the array column by column(top to bottom) then left to right</mark>
		- 1st column has n elements 2nd has n-1 and 3rd has n-2 and so on  **◺**
			- the 1st element of the linear array is the first element of the 1st column and the nth element of linear array marks the end of the 1st column
			- the (n+1)th element of the linear array marks the start of the 2nd column and is the 1st element of the 2nd column and the 2nd column ends at (n+n-1)th element of the linear array
		- i,j(they start from 1 not 0) of the 2-D matrix can be mapped to `(n(j-1)-((j-2)(j-1))/2)+i-j`th index of the linear array
			- <mark style="background: #BBFABBA6;">the above mapping is called column major mapping</mark>
- <mark style="background: #D2B3FFA6;">an upper triangular matrix has all elements below the diagonal equal to zero(excluding the diagonal as well)</mark>
	- element at i,j is 0 when `i>j` and non-zero for `i<=j` <mark style="background: #BBFABBA6;">(sign flipped)</mark>
	- total number of non zero elements is `n(n+1)/2` and total number of zero elements are `(n^2)-(n(n+1)/2) = n(n-1)/2` <mark style="background: #BBFABBA6;">(same as lower triangular matrix)</mark>
	- to store the elements below diagonal and including diagonal elements we need a linear array of size `n(n+1)2` <mark style="background: #BBFABBA6;">(same as lower triangular matrix)</mark>
	- <mark style="background: #BBFABBA6;">row major mapping:</mark> `(n(i-1)-((i-2)(i-1))/2)+j-i` <mark style="background: #BBFABBA6;">(interchange i and j of column major mapping of lower triangular matrix)</mark>
	- <mark style="background: #BBFABBA6;">column major mapping:</mark> `(j(j-1)/2)+i-1` <mark style="background: #BBFABBA6;">(interchange i and j of row major mapping of lower triangular matrix)</mark>
- <mark style="background: #D2B3FFA6;">symmetric matrices:</mark> when <mark style="background: #BBFABBA6;">element at i,j is equal to the element at j,i</mark> then the matrix is symmetric
	- so <mark style="background: #BBFABBA6;">we don't need to store duplicates, we can discard either the lower triangle or the upper triangle(always excluding the diagonal</mark> as for <mark style="background: #BBFABBA6;">every diagonal element</mark> `i==j` <mark style="background: #BBFABBA6;">is unique)</mark>
- <mark style="background: #D2B3FFA6;">tridiagonal matrix</mark>
	- ![tridiagonal matrix](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/tridiagonalMatrix.png)
		- as we can see for the diagonal elements `i==j` so i-j=0
			- similarly for the lower diagonal matrix i-j=1
			- and for upper diagonal matrix i-j=-1
			- we can say that for a non zero element `|i-j| <= 1` and for a zero element `|i-j| > 1`
		- total number of non zero elements are `3n-2`
		- <mark style="background: #BBFABBA6;">the linear array is first populated with lower diagonal elements followed by actual diagonal elements followed by upper diagonal elements</mark> 
		- <mark style="background: #BBFABBA6;">mapping</mark> non zero elements to a linear array
			- when `i-j=1` then i,j of matrix is mapped with `index i-1` of the linear array
			- when `i-j=0` the i,j of matrix is mapped with `index n-1+i-1` of the linear array
			- when `i-j=-1` the i,j of matrix is mapped with `index 2n-1+i-1` of the linear array
- <mark style="background: #D2B3FFA6;">square band matrix</mark>
	- tridiagonal matrix had one upper diagonal and one lower diagonal above and below the actual diagonal
	- <mark style="background: #BBFABBA6;">a triangular matrix is the simplest type of square band matrix as a square band matrix can have x upper diagonals and x lower diagonals above and below the actual diagonal</mark>
		- so it will have `2x+1` diagonals
- <mark style="background: #D2B3FFA6;">toeplitz matrix</mark>
	- <mark style="background: #BBFABBA6;">all elements are diagonally same</mark>
	- `M[i][j] == M[i-1][j-1]`
	- then <mark style="background: #BBFABBA6;">we don't need to store duplicates</mark>
		- <mark style="background: #BBFABBA6;">only need to store the 1st row followed by 1st column elements in an linear array</mark>
		- so linear array has length `n+n-1`
	- ![toeplitz matrix mapped](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/toeplitz-mapped.png)
		- <mark style="background: #BBFABBA6;">notice how we can get the other elements just by storing the first row and first column</mark>
	- <mark style="background: #BBFABBA6;">mapping</mark> i and j of the toeplitz matrix to an linear array
		- if `i<=j` then element is in or above actual diagonal which are stored first in the linear array as shown as blue boxes in the image can be mapped with `(j-i)`th index on linear array
		- if `i>j` the element is below the actual diagonal which is stored after the 1st row in the linear array as shown as green boxes in the image can be mapped with (n-1+i-j)th index on linear array

# <mark style="background: #FFB86CA6;">Sparse Matrices</mark>
- <mark style="background: #D2B3FFA6;">when number of zeroes in a matrix >> number of non zero elements</mark>
- 2 ways to represent such sparse matrices
	1. <mark style="background: #D2B3FFA6;">coordinate lists/3 column representation</mark>
		- ![3 column representation](https://raw.githubusercontent.com/JayaswalPrateek/MyCSnotesForME/main/Attachments/sparse-form.jpg)
	2. <mark style="background: #D2B3FFA6;">compressed sparse row</mark>
		- <mark style="background: #BBFABBA6;">3 arrays are needed</mark>
			1. <mark style="background: #BBFABBA6;">list of non zero elements in order of traversing left to right and top to bottom</mark>
			2. <mark style="background: #BBFABBA6;">an array of size equal to the number of rows in the sparse matrix where every index stores the number of non zero elements in and above that row</mark>
				- the 1st element is the number of non zero elements in the 1st row
				- the 2nd element is the number of non zero elements in 1st + 2nd row
				- the 3rd element is the number of non zero elements in 1st + 2nd + 3rd row and so on
			3. <mark style="background: #BBFABBA6;">an array such that index i of this array stores the column number of the non zero element at index i of the 1st array </mark>
- <mark style="background: #D2B3FFA6;">addition of 2 sparse matrices</mark>
	- precondition: the dimensions of the two matrices to be added should be same and the number of non zero elements need not be same
		- so the <mark style="background: #BBFABBA6;">dimensions of resultant matrix is predefined but we increment/decrement the number of non zero elements when we add individual elements from the 2 matrices and by default it is 0</mark>
	- <mark style="background: #BBFABBA6;">addition is done by scanning the row number in the coordinate lists of the 2 matrices to be added</mark>
	- <mark style="background: #BBFABBA6;">i and j point initially point to the 2nd row of both coordinate lists</mark> because 1st row stores the dimensions and the number of non zero elements in the matrix
		- <mark style="background: #BBFABBA6;">if the row number is unequal then add the element with smaller row number to the new list and increment either i or j</mark> (the one which was associated with it)
		- <mark style="background: #BBFABBA6;">if the row number is equal and column number is also equal then add the non zero elements and store them and increment both i and j</mark>
		- <mark style="background: #BBFABBA6;">if the row number is equal but column number is unequal then add the element with smaller column number to the new list and increment either i or j</mark> (the one which was associated with it)
	- <mark style="background: #D2B3FFA6;">same for subtraction</mark>
- <mark style="background: #D2B3FFA6;">creating and displaying and adding a coordinate list</mark>
	```cpp
	#include <iostream>
	using namespace std;
	struct sparse
	{
	    int m, n, num; // m*n matrix with num non zero elements
	    struct element // embedded coordinate list
	    {
	        int i, j, x;
	    } *e; // will dynamically create array for the coordinate list
	};
	
	void create(sparse *s)
	{
	    cout << "Enter Dimension: ";
	    cin >> s->m >> s->n;
	
	    do
	    {
	        cout << "How many non zero elements does it have? ";
	        cin >> s->num;
	        if (s->m * s->n < s->num)
	            cout << "Matrix can hold upto " << s->m * s->n << " elements" << endl;
	    } while (s->m * s->n < s->num);
	
	    s->e = new sparse::element[s->num]; // creates the coordinate list
	
	    for (int i = 0; i < s->num; i++)
	    {
	        cout << "Enter Row,Column number for an element followed by the element: ";
	        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
	        if (s->e[i].x == 0)
	        {
	            cout << "zero value not stored" << endl;
	            i--; // will overewrite the zero value on next iteration
	        }
	    }
	}
	
	void display(sparse s)
	{
	    for (int i = 0, k = 0; i < s.m; i++)
	    {
	        for (int j = 0; j < s.n; j++)
	            if (k < s.num && i == s.e[k].i && j == s.e[k].j) // we need to check k < s.num as c++ if statements short circuit if a single condition is false with && or true with &&
	                cout << s.e[k++].x << " ";
	            else
	                cout << "0 ";
	        cout << "\n";
	    }
	}
	
	sparse *add(sparse s1, sparse s2)
	{
	    if (s1.m != s2.m || s1.n != s2.n)
	        throw string("BadDimensions");
	    sparse *sum = new sparse;
	    sum->m = s1.m;
	    sum->n = s1.n;
	    sum->num = 0;
	    // s1.num + s2.num is the max number of non zero elements the sum can have, so we will create a coordinate list of s1.num + s2.num which still could be underutilized
	    sum->e = new sparse::element[s1.num + s2.num];
	    int i = 0, j = 0, k = 0;
	    for (; i < s1.num && j < s2.num; k++)
	        if (s1.e[i].i < s2.e[j].i) // when row number of s2 is greater than row number of s1
	            sum->e[k] = s1.e[i++];
	        else if (s1.e[i].i > s2.e[j].i) // when row number of s1 is greater than row number of s2
	            sum->e[k] = s2.e[j++];
	        // if control reaches here, implies row numbers of s1 and s2 are same so we compare column numbers
	        else if (s1.e[i].j < s2.e[j].j) // when row numbers are same and column number of s2 is greater than column number of s1
	            sum->e[k] = s1.e[i++];
	        else if (s1.e[i].j > s2.e[j].j) // when row numbers are same and column number of s1 is greater than column number of s2
	            sum->e[k] = s2.e[j++];
	        else // when row numbers are same and column numbers are also same
	        {
	            sum->e[k] = s1.e[i++];
	            sum->e[k].x += s2.e[j++].x;
	        }
	    while (i < s1.num)
	    {
	        sum->e[k] = s1.e[i++];
	        k = k + 1;
	    }
	    while (j < s2.num)
	    {
	        sum->e[k] = s2.e[j++];
	        k = k + 1;
	    }
	    sum->num = k;
	    return sum;
	}
	
	int main()
	{
	    sparse s1;
	    create(&s1);
	    display(s1);
	    sparse s2;
	    create(&s2);
	    display(s2);
	    try
	    {
	        sparse *sum = add(s1, s2);
	        cout << "The sum is: " << endl;
	        display(*sum);
	        delete[] sum->e;
	        delete sum;
	    }
	    catch (const string &err)
	    {
	        cout << "dissimilar matrices cannot be added [BadDimensions]" << endl;
	    }
	
	    delete[] s1.e;
	    delete[] s2.e;
	    return 0;
	}
	
	```

# <mark style="background: #FFB86CA6;">Polynomial Representation</mark>
- to represent expressions like `3x^5 + 2x^4 + 5x^2 + 2x +7` 
```cpp
#include <iostream>
#include <cmath>
using namespace std;
struct poly
{
    int totalTerms;
    struct term
    {
        int coeff, exp;
    } *aTerm;
};
int main()
{
    poly p;
    do
    {
        cout << "enter number of non zero terms: ";
        cin >> p.totalTerms;
        if (p.totalTerms < 0)
            cout << "it cannot be lesser than 1, r";
    } while (p.totalTerms < 0);

    p.aTerm = new poly::term[p.totalTerms];

    for (int i = 0; i < p.totalTerms; i++)
    {
        cout << "Enter Coeff. & Power of term " << i + 1 << ": ";
        cin >> p.aTerm[i].coeff >> p.aTerm[i].exp;
    }

    cout << "The expression is p(x) = ";
    for (int i = 0; i < p.totalTerms; i++)
    {
        if (p.aTerm[i].exp != 0 && p.aTerm[i].coeff != 0)
            cout << p.aTerm[i].coeff << "x^" << p.aTerm[i].exp;
        else if (p.aTerm[i].exp == 0 && p.aTerm[i].coeff != 0)
            cout << p.aTerm[i].coeff;
        if (i < p.totalTerms - 1 && p.aTerm[i + 1].coeff != 0)
            cout << " + ";
    }

    cout << "\nEnter value of x: ";
    int x, sum = 0;
    cin >> x;

    for (int i = 0; i < p.totalTerms; i++)
        sum += p.aTerm[i].coeff * pow(x, p.aTerm[i].exp);
    cout << "p(" << x << ") = " << sum << endl;

    delete[] p.aTerm;
    return 0;
}

/**
enter number of non zero terms: 4
Enter Coeff. & Power of term 1: 4 2
Enter Coeff. & Power of term 2: 8 1
Enter Coeff. & Power of term 3: 24 0
Enter Coeff. & Power of term 4: 0 48
The expression is p(x) = 4x^2 + 8x^1 + 24
Enter value of x: 2
p(2) = 56
*/
```

# <mark style="background: #FFB86CA6;">Prime Numbers</mark>
- to find the primality of a number instead of checking divisibility form 2 to one less than the number itself `O(n)`, we can check it from 2 to √number `O(√n)`
- Sieve of Eratosthenes algorithm to find prime numbers till n
	- initially we assume that all numbers from 2 to n are prime by creating an array of length+1 and setting all to true
	- we then loop over this list and we can say as 2 is a prime number, all multiples of 2 will never be prime and same for 3 and its multiples
		- so we set these multiples as false
		- note that all multiples will be greater than the number itself
		- we can further optimize it as we know that if the factor of a number doesn't exist till √number then it is prime
			- one factor is less than/equal to and other one is greater than/equal to √number
			- so we can run the outermost loop till √number
	- time complexity is `O(n log(logn))` as per a proof
		- we check the worst case on the most nested statement for time complexity analysis
	```cpp
	#include <cmath>
	#include <iostream>
	using namespace std;
	int main() {
		cout << "Enter number: ";
		int n;
		cin >> n;
		if (n <= 1) {
			cout << "not prime";
			return 0;
		}
	
		bool primes[n + 1];
		for (bool& x : primes)
			x = true;
		primes[0] = primes[1] = false;
	
		for (int i = 2; i <= sqrt(n); i++)
			if (primes[i])
				for (int j = 2; i * j < n; j++)
					primes[i * j] = false;
	
		return 0;
	```

# <mark style="background: #FFB86CA6;">GCD by Euclid's Algorithm</mark>
- fastest algorithm to compute GCD(Greatest Common Denominator)
- `gcd(a,b) = g` where `g` is the maximum possible value for `g%a==0 and g/b==0`
- gcd of 105 and 350 is 35
	- 105 = 5 x 7 x 3 and 350 = 5 x 7 x 5 x 2
		- 5 and 7 are common so gcd = 35
		- note that no factor can be greater than square root of the number itself
	- above is not Euclid's Algorithm
- Euclid's Algorithm
	1. modulo the larger number by the smaller number
	2. modulo the smaller number by the remainder found from above step
	3. stop when the modulo is zero (denominator is zero)
	4. and in the last step the numerator is the gcd 
	```cpp
	#include <iostream>
	using namespace std;
	int main() {
		cout << "Enter 2 numbers: ";
		int num, den;
		cin >> num >> den;
	
		// this snippet is not needed as this will automatically happen in the while loop
		// if (num < den) {
		// 	int tmp = num;
		// 	num = den;
		// 	den = tmp;
		// }
	
		while (den != 0) {
			int remainder = num % den;
			num = den;
			den = remainder;
		}
		cout << "GCD IS " << num;
		return 0;
	}
	```
	- each line take `O(1)` to execute but we don't know how many times will the while loop run
		- let the while loop run `x` times and let `f(x)` be a function of variables `num` and `den`
		- the while loop executes 4  `O(1)` operations which is one comparison and 3 assignments `x` times so it is `O(x)` time complexity
			- in the 1800s it was proven that this `x` is proportional to the number of digits in the smaller number which is always the denominator
				- in binary search we used to divide by 2 over and over so it became `O(log base2 n)`
				- similarly to find the number of digits in a number we keep on dividing by 10 so it is `O(log base10 den)`
					- we can ignore the base of logs like coefficients of polynomials when calculating the time complexity so `O(log den)`
	- recursive function
		- disadvantage is higher space complexity
		- advantage is readability
		```cpp
		int euclidGCDrecursion(int num, int den) {
			return den == 0 ? num : euclidGCDrecursion(den, num % den);
		}
		```