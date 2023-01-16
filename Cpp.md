***Input Buffer***
- For the user input `cin>>anInteger;` followed by `cin>>str;` on the next line, then the enter key pressed after typing the number is saved as input buffer and later accepted by `cin>>str;` and to avoid this use **`cin.ignore();`** between `cin>>anInteger;` and `cin>>str;`

***Enum***
- User defined data types such that we can link a commonly used term with a constant integer:
		**`enum day {mon,tue,wed,thr,fri,sat,sun};`** creates
				0: mon
				1: tue
				2: wed
				3: thr
				4: fri
				5: sat
				6: sun
			which is same as
				`const int mon = 0;`
				`const int tue = 1;`
				`const int wed = 2;`
				`const int thr = 3;`
				`const int fri = 4;`
				`const int sat = 5;`
				`const int sun = 6;`
- day is a user defined data type which can only have names mon,tue,wed,thr,fri,sat,sun automatically it gets a value.
		`day d;
		*`d = jan; // error`*
		`d = tue;
		`cout << d; // 1`
	`enum day {mon=4,tue,wed,thr,fri,sat,sun};`
		mon =4 tue=5 wed=6 thr=7 fri=8 sat=9 sun=10
	`enum day {mon=4,tue,wed,thr,fri=13,sat,sun};`
		mon=4 tue=5 wed=6 thr=7 fri=13 sat=14 sun=15
	`enum day {mon=4,tue,wed,thr,fri=6,sat,sun};`
		mon=4 tue=5 wed=6 thr=7 fri=6 sat=7 sun=8

***Type Definition***
- Used to make variables more readable.
- So lets say a school app has `int m1,m2,m3,r1,r2,r3` where mX are marks in subject X and rN is the roll number N.
- To make it more readable we use typedef to alias the data type of mX from int to marks and rN from int to roll.
	`typedef int marks;`
	`typedef int roll;`
	`marks m1, m2, m3;`
	`roll r1, r2, r3;`

***For Each Loop***
- let `int A[] = {1, 2, 3, 4, 5};` then 
- `for (int x : A)`
	`cout << x;`
- `for (auto x : A)` where the compiler takes care of the data type of x.
- changing the value of x doesn't change the array element because x is a copy.
	- To avoid this you can used `int &x : A` instead of `int x : A`
	- `auto &x : A` is also allowed

***Binary Search***
```cpp
#include <iostream>
using namespace std;
int main()
{
    const int A[] = {4, 8, 24, 42, 101, 404, 1234};
    int key, l = 0, h = (sizeof(A) / 4) - 1;

    cout << "Enter Key: ";
    cin >> key;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (key == A[mid])
        {
            cout << "Found at " << mid;
            return 0;
        }
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    cout << "Not Found";
    return -1;
}
```

***Finding Min and Max of an Array***
```cpp
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    const int A[] = {4, 8, 24, 42, 101, 404, 1234};
    int min = INT_MAX, max = INT_MIN;

    for (auto x : A)
    {
        min = x < min ? x : min;
        max = x > max ? x : max;
    }

    cout << "Min = " << min << endl;
    cout << "Max = " << max;

    return 0;
}
```

***Note on Arrays***
- When an Array of length n is created and when m elements are hard coded then remaining n-m elements are automatically initialized to 0.
- `A[i]` is always equal to `i[A]` where A is an array and i is an integer counter variable of a for loop because `*(A+i)` is same as `*(i+A)`
- When `int *p = A` and A is an array then we can used `p[i]` instead of `A[i]`
- When a 2-D Array is created, all the elements are contiguous in the memory just like a 1-D array.
- Need to use reference of x when A is 2-D array in a for each loop but you still need to use nested for each loop.
	```cpp
	#include <iostream>
	using namespace std;
	int main()
	{
	    const int A[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
	
	    for (auto &i : A)
	    {
	        for (auto j : i)
	            cout << j << " ";
	        cout << endl;
	    }
	
	    return 0;
	}
	```
	- `const int A[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}};` is invalid


***Pointer***
- Size of a pointer is independent of data type and always takes 8 bytes.
- *Memory Layout*
	- | HEAP  |
	- | STACK | <- declarations like `int i = 0` are stored in STACK. Students heavily use it. Automatically deleted when out of scope.
	- | CODE  | <- is the read-only section of the memory where the code is loaded after launching the program. No external programs can modify this section.
		- The CODE section can access STACK and itself. Not the HEAP.
		- To access the HEAP from the CODE section you need to create a pointer to a memory address in HEAP and the pointer is created in the STACK from the CODE section.
			- Thus HEAP can only be accessed using pointers.
			- Accessing Files and hardware devices is also done using pointers.
		- Accessing HEAP using `new` 
			- example: `int *p = new int[5]`
			- If not freed at the end, we get a Memory Leak. Use `delete[] p` and then `p = nullptr`
				- if you do `p = nullptr` first then you won't be able to free HEAP later.
			- once an array is declared in the STACK you cannot change its size but it is possible if it is in the HEAP.
			```cpp
			#include <iostream>
			using namespace std;
			int main()
			{
			    int *p = new int[5];
			
			    for (int i = 0; i < 5; i++)
			    {
			        p[i] = i + 1;
			        cout << p[i] << " ";
			    }
		
				delete[] p; // to avoid leaking of {1, 2, 3, 4, 5}
				p = new int[10]; // new memory gets allocated pointing to {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		
			    delete[] p;
			    p = nullptr;
			
			    return 0;
			}
			```
- *Pointer Arithmetic*
	- dereferencing is not needed.
	- subtracting 2 pointers pointing to different indices of an integer Array gives how many indices far are the 2 pointers without dividing by 4.
	- doing `p+=2` moves the pointer by 8 bytes instead of 2 bytes if it is pointing to integer array.
	- this is
		```cpp
		#include <iostream>
		using namespace std;
		int main()
		{
		    int A[] = {1, 2, 3, 4, 5};
		    int *p = A; // Same as int *p = &A[0]
		
		    for (int i = 0; i < sizeof(A) / 4; i++, p++)
		        cout << *p;
		
		    return 0;
		}
		```
	- same as this
		```cpp
		#include <iostream>
		using namespace std;
		int main()
		{
		    int A[] = {1, 2, 3, 4, 5};
		
		    for (int i = 0; i < sizeof(A) / 4; i++)
		        cout << *(A + i);
		
		    return 0;
		}
		```
- *Runtime gotchas w/ pointers*
	- Memory Leak when HEAP allocations are not freed.
	- uninitialized pointer
		- `int *p = 25` where 25 is not stored in a variable.
			- you can use `int *p = &n` or `int *p = new int`
	- dangling pointer
		- If a pointer is having an address of a memory location which is already deallocated.
		- when a pointer is passed to another function and freed at the end of that function and if the pointer is accessed again after the control is returned to the calling function then we have a runtime error but not a memory leak.
- *References*
	- `int x = 10` allocates a box in the memory named x which stores 10.
	- `int &y = x` creates an alias of x which is y.
		- So x and y will always have the same value and changes to one can be reflected from the other variable as well.
	- doesn't consume memory
	- &x is always same as &y
	- declaration without initialization is an error.
	- later on you cannot reassign to reference so if `int z = 12` and `&y = z` is invalid since y is already a reference of x.

***Strings***
- 2 ways to create a string
	- using class string
	- using array of char
		- without pointer: `char str[] = "Hello"`
			- `char str[10]` can store 9 letters as 10th one has to be `\0` to identify the char array as a string.
		- with pointer: `char *s = "H"` 
			- stored in HEAP
- 2 ways to get user input
	- if using class string
		- `cin>>str` accepts one word
		- `getline(cin,str)` accepts words with white spaces
	- if using array of char
		- `cin>>str` accepts one word
		- `cin.getline(str,50)`
			- where 50 is the max length of string which is same as the length of the array of char.
- 2 ways to find length(doesn't count `\0`)
	- if using string class, use `str.length()`
	- if using char array, use `strlen(str)` and `#include<cstring>`
- `cstring` functions: 
	- `strcat(destination, source)`
		- removes `\0` from source and merges them.
		- `strncat(destination, source, length)`
			- the length of the source to be concatenated.
	- `strcpy(destination, source)` or `strncpy(destination, source, length)`
	- `strstr(str,subStr)`
		- used to check for sub string `subStr` in string `str`
			- if found returns sub string from the first occurrence to the end of the string including the sub string.
			- else it returns `NULL`
				- `NULL` cannot be printed by `cout` so write `cout` in if block that checks if `strstr(str,subStr)` doesn't return `NULL`.
	- `strchr(str, ch)`
		- used to check occurrence of `char ch` in `string str` and return the string ahead of it including ch itself.
	- `strrchr(str, ch)` same as `strchr(str, ch)` but checks from Right to Left.
	- `strcmp(s1,s2)` gives -ve, 0, +ve value
	- `strtol(str,NULL,10)` converts string to long
		- 10 means decimal system, 2 means binary system
	- `strtof(str,NULL)` converts string to float
	- `strtok(str,"=;")`
		- Tokeniser function
		```cpp
		#include <iostream>
		#include <cstring>
		using namespace std;
		int main()
		{
		    char str[20] = "x=10;y=20;z=35";
		    char *token = strtok(str, "=;");
		
		    while (token != NULL)
		    {
		        cout << token << endl;
		        token = strtok(NULL, "=;");
		    }
		
		    return 0;
		}
		/**
		x
		10
		y
		20
		z
		35
		
		*/
		```
		- `strtok(str,";")`
			```cpp
			#include <iostream>
			#include <cstring>
			using namespace std;
			int main()
			{
			    char str[20] = "x=10;y=20;z=35";
			    char *token = strtok(str, ";");
			
			    while (token != NULL)
			    {
			        cout << token << endl;
			        token = strtok(NULL, ";");
			    }
			
			    return 0;
			}
			/**
			x=10
			y=20
			z=35
			
			*/
			```
- string class
	- creates an array bigger than the number of characters to maintain buffer capacity.
	- if a modification adds characters more than the available buffer capacity then it internally creates another copy of the array, makes the modification and still leaves some buffer capacity to the newly copied array.
	- `str.length()` gives length of string excluding `\0`
		- `str.size()` is same as `str.length()`
	- `str.capcity()` gives the actual capacity of the string including `str.length()`+ 1 due to `\0` + buffer capacity
	- `str.resize(newCapacity)` changes the capacity of `str` from `str.Capacity()` to `newCapacity` + buffer capacity
	- `str.max_size()` gives the max size of a string the compiler supports
		- depends on the CPU architecture and OS
	- `str.clear()` to empty a string
		- contains only `\0`
			- so `str.length()` is 0 
	- `str.empty()` checks if the string is empty or not
		- `str.erase()` is same as `str.empty()`
	- `str.append(anotherStr)` appends `anotherStr` at the end of string `str` by removing `\0` at the end of `str` before appending
	- `str.insert(strIndex, snippetStr)`
		- inserts `snippetStr` in `str` at `strIndex`
		- 0th index of `snippetStr` becomes `strIndex`th index of `str`
		- `str.insert(strIndex, snippetStr, n)`
			- inserted till (n-1)th index of `snippetStr`
	- `str.replace(strIndex, howMany, snippetStr)`
		- it replaces `howMany` letters from `strIndex`th index with `snippetStr`
	- `str1.swap(str2)` 
	- Stack operations
		- `str.push_back(ch)`
			- adds char ch at the end of `str`
		- `str.pop_back()`
			- removes last char of `str` 
	- `str.copy(chArray,str.length())` 
		- copies string `str` into char array `chArray`. 2nd arg is the length of `str` to be copied.
		- doesn't add `\0` so need to do it manually
			- `string str = "Welcome"`
			- `char chArray[10]`
			- `str.copy(chArray, 3)` <- `Wel` is stored in `chArray`
			- `chArray[3] = '\0'` <- now `chArray` can be printed by `cout` as it identifies as a string
	- `str.find(subStr)` or `str.find(ch)`
		- returns the index of first occurrence of `ch` in `str` if char is used as arg
		- if string is used then if the string `subStr` exists in `str` then the index of first occurrence of first letter of `subStr` in `str` is returned
		- `str.rfind(subStr)` or `str.rfind(ch)` does the same thing but from Right to Left
			- if not found then it returns an invalid index that doesn't lie between 0 and `str.length()`
	- `str.find_first_of(ch)` or `str.find_first_of(ch, startingIndex)`
		- `startingIndex` is the index from where searching starts
		- gives the first occurrence of char `ch` in string `str`
		-  `str.find_last_of(ch)` or `str.find_last_of(ch, startingIndex)`
		- if a string is given its not a syntax error
			- it traverses `str` char by char and as soon as a char at `str` also exists in the string arg then it returns the index for that char in `str` which will always be the first occurrence. 
	- `str.substr(lowerLim, upperLim)`
		- returns sub string of `str` from index `lowerLim` till index `upperLim`
			- `upperLim` is not mandatory, when not provided, it is equal to `str.length()`
		- returned string includes the char at index `lowerLim` of `str`
	- `str.compare` same as `strcmp(s1,s2)` of `cstring`
	- `str.at(ind)` returns char at index `ind` of string `str`
		- same as writing `str[ind]`
			- string is a class so `[]` operator is overloaded
	- `str.front()` gives first char of string `str`
	- `str.back()` gives last char of string `str`
	- + operator can be used to concatenate strings
		- + is also overloaded
	- = operator copies the content of r value to l value
		- = is also overloaded
	- String iterations
		- 2 ways: `iterator` and `reverse_iterator`
			- the iterator is pointer for the array of chars in the string class and we use pointer arithmetic to iterate using the string class
			```cpp
			#include <iostream>
			using namespace std;
			int main()
			{
			    string str = "Hello World";
			
			    for (string::iterator it = str.begin(); it != str.end(); it++)
			        cout << *it;
			    cout << endl;
			    for (string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
			        cout << *it;
			
			    return 0;
			}
			```
			- `rbegin` and `rend` are same as `begin` and `end` respectively but are used with `reverse_iterator` instead.
			- similar to `for(int i = 0; str[i] != '\0'; i++`

***Functions***
- avoid user input in functions, that should happen in the main function
- return types are not a deciding factor in function overloading
- Function Templates (Generics)
	- overloaded functions may have entirely same logic but deal with different data type so we need to overload function for every data type
		```cpp
		#include <iostream>
		using namespace std;
		
		int getmax(int a, int b)
		{
		    return a > b ? a : b;
		}
		float getmax(float a, float b)
		{
		    return a > b ? a : b;
		}
		
		int main()
		{
		    cout << getmax(4, 8) << endl;
		    cout << getmax(4.8f, 8.4f); // without specifying f they are doubles by default
		
		    return 0;
		}
		```
	- to avoid this we can create a generic data type using function templates.
		```cpp
		#include <iostream>
		using namespace std;
		
		template <class T>
		T getmax(T a, T b)
		{
		    return a > b ? a : b;
		}
		
		int main()
		{
		    cout << getmax(4, 8) << endl;
		    cout << getmax(4.8f, 8.4f);
		
		    return 0;
		}
		```
		- Here the data type of T is decided dynamically.
		- T can also be an object.
		- data types of both a and b should be same.
			- if we pass an int and double then we get an error
- Default arguments of a function
	```cpp
	#include <iostream>
	using namespace std;
	
	int add(int x, int y, int z = 0)
	{
	    return x + y + z;
	}
	
	int main()
	{
	    cout << add(1, 2) << endl;
	    cout << add(1, 2, 3);
	
		return 0;
	}
	```
	- here the default arguments of variable z is 0 so if the value of z is not provided in the function call then it fall backs to the default value
	- this way using one function we can add 2 or 3 numbers.
	- allows to combine otherwise overloaded functions.
	- rule: default arguments should be declared from right to left and you cannot have a variable with no default argument in between 2 variables which have default arguments.
	- all variables can have default arguments, but if one of them doesn't have one then it should be the leftmost variable and cannot lie between any 2 variables.
		- `int add(int x = 0, int y, int z = 0)` is an error
		- `int add(int y, int x=0, int z = 0)` is correct.
	- It is a good practice to use `nullptr` as the default argument for functions that accept pointers, as it clearly indicates that the pointer is not pointing to a valid memory location. This can help prevent issues such as dereferencing a null pointer, which can lead to undefined behavior and crashes.
	- call by reference functions are handled differently by the compiler.
		- its machine code gets inserted in the machine code of the function calling another function by reference and pointers are not involved
			- the function called by reference acts as if its content was in the calling function at the line where the function call happens
			- all functions that are called by reference become inline functions because their machine code get copied to the function calling them 
			- avoid loops in functions that are called by reference as the loop or any other complex code can change the nature of the call and it may not be by reference 
	- return by address
		- functions perform operation on heap and return an address without freeing it to the calling function which can be used to read and print by dereferencing the address
			```cpp
			#include <iostream>
			using namespace std;
			
			int *retByAdd(int size)
			{
			    int *p = new int[size];
			    for (int i = 0; i < size; i++)
			        p[i] = i + 1;
			
			    return p;
			}
			
			int main()
			{
			    int *ptr = retByAdd(5);
			    for (int i = 0; i < 5; i++)
			        cout << ptr[i] << " ";
			
			    delete[] ptr;
			    ptr = nullptr;
			
			    return 0;
			}
			```