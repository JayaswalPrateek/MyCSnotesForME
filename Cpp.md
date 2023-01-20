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
	- | CODE  | <- read-only section of the memory where the code is loaded after launching the program. global variables are stored here.
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
	- When a function has a local variable and a global variable of the same name then local variable is preferred
		- use `::<nameOfVariable>` to access the global variable in a function that has a local variable of the same name.
		- even if a function ends the changes made to the global variable are preserved.
			- this is useful, but i also want to make sure that the variable is not visible to all the functions of my program
				- solution instead of declaring it as global variable make it a static local variable.
				- they are located in the code section so their content is not lost after a function ends.
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
	- a template function cannot have default arguments
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
		- you cannot return the address of a local variable as it will be destroyed after the function ends. 
			- only HEAP memory address can be returned. 
		- can be used to return arrays
- return by reference 
	- you cannot return the address of a local variable as it will be destroyed after the function ends. 
		- only HEAP memory address can be returned. 
	```cpp
	#include <iostream>
	using namespace std;
	
	int &retByRef(int &x)
	{
		return x;
	}
	
	int main()
	{
		int a = 10;
		cout << a << endl;
		retByRef(a) = 20;
		cout << a; // 20
		
		return 0;
	}
	```
- pointer to a function
	- rule: the name of the pointer variable whenever used with asterisk sign should be enclosed in round brackets.
	```cpp
	#include <iostream>
	using namespace std;
	
	void hello()
	{
	    cout << "hello world" << endl;
	}
	
	int main()
	{
	    // 1st way
	    void (*funptr)() = &hello;
	    (*funptr)();

		// 2nd way
	    void (*anotherfunptr)();
	    anotherfunptr = hello;
	    (*anotherfunptr)();
	
	    return 0;
	}
	```
	- using with arguments to a function
		```cpp
		#include <iostream>
		using namespace std;
		
		int min(int x, int y)
		{
		    return x > y ? y : x;
		}
		
		int max(int x, int y)
		{
		    return x < y ? y : x;
		}
		
		int main()
		{
		    int (*funptr)(int, int) = &min;
		    cout << (*funptr)(10, 20) << endl;
		
		    funptr = max;
		    cout << (*funptr)(10, 20);
		
		    return 0;
		}
		```
- passing array to function
	- when an array is passed as a parameter to a function, it decays into a pointer to the first element of the array
	```cpp
	#include <iostream>
	using namespace std;
	
	int search(const int A[], int len, int key)
	{
	    for (int i = 0; i < len; i++)
	        if (key == A[i])
	            return i;
	    return -1;
	}
	
	int main()
	{
	    const int A[] = {2, 4, 5, 7, 10, 9, 13};
	
	    int k;
	    cout << "Enter an Element to be Searched:";
	    cin >> k;
	
	    int index = search(A, 7, k);
	
	    if (index == -1)
	    {
	        cout << k << "not found";
	        return -1;
	    }
	
	    cout << "Element found at index :" << index << endl;
	
	    return 0;
	}
	```

***OOPS***
- size of a object = size of data types only as functions don't occupy memory
- class doesn't occupy space, object does. Class is a blueprint
- multiple objects have multiple copies of data members in the stack but all objects share the functions between them which are located in the code section.
- pointer to object in STACK
	```cpp
	#include <iostream>
	using namespace std;
	
	class rect
	{
	public:
	    float len, brd;
	
	    void area()
	    {
	        cout << "Area is " << len * brd << " sq. units" << endl;
	    }
	
	    void peri()
	    {
	        cout << "Perimeter is " << 2 * (len + brd) << " units" << endl;
	    }
	};
	
	int main()
	{
	    rect r1;
	    rect *rectptr = &r1;
	    rectptr->len = 123;
	    rectptr->brd = 2;
	    rectptr->area();
	    rectptr->peri();
	
	    return 0;
	}
	```
- pointer to object in HEAP
	```cpp
	#include <iostream>
	using namespace std;
	
	class rect
	{
	public:
	    float len, brd;
	
	    void area()
	    {
	        cout << "Area is " << len * brd << " sq. units" << endl;
	    }
	
	    void peri()
	    {
	        cout << "Perimeter is " << 2 * (len + brd) << " units" << endl;
	    }
	};
	
	int main()
	{
	    rect *rectptr = new rect;
	    rectptr->len = 123;
	    rectptr->brd = 2;
	    rectptr->area();
	    rectptr->peri();
	
	    delete rectptr;
	    rectptr = nullptr;
	
	    return 0;
	}
	```
- getters and setters / accessor and mutator
	- setter functions of the class a public functions that get the value in a function call and assign it to initialize private variables
	- getters are functions that just return the value of the private variable.
	- if a variable has getter and no setter it becomes read only
	- if a variable has a setter and no getter then it becomes write only (example passwords)
- we should use constructor to assign default value instead of expecting that setters will always be used before getters. 
	- if getters are used before setters we might see garbage value and we thus assign default values
	- parameterized constructor can call setters as well
- ideally a class should have a copy constructor and a parameterized constructor with default values. 
- prefer writing functions outside class
	- functions declared outside the class have their machine code outside the main function's machine code.
	- if they are declared in the class they become inline functions and their machine code is inside the machine code of main
		- inline function cannot have complex logic. so if you have complex logic use scope resolution operator for those functions.
- so all functions defined in a class are inline and all functions outside it defined with scope resolution operator are not inline
- to make a function inline explicitly write `inline` before the return type of the function
- struct and class are same in c++ as both of them can store variables and functions unlike c where structs can only store variables.
	- the difference is that in a struct everything is public
- operator overloading
	```cpp
	#include <iostream>
	using namespace std;
	class complex
	{
	public:
	    int r, i;
	
	    complex(int r = 0, int i = 0)
	    {
	        this->r = r;
	        this->i = i;
	    }
	
	    complex operator+(complex c)
	    {
	        complex temp;
	        temp.r = c.r + r;
	        temp.i = c.i + i;
	        return temp;
	    }
	
	} c1(1, 2), c2(3, 4), c3;
	
	int main()
	{
	    c3 = c1 + c2;
	    cout << c1.r << " + " << c2.r << " = " << c3.r << endl;
	    cout << c1.i << "i + " << c2.i << "i = " << c3.i << "i ";
	
	    return 0;
	}
	```
- friend operator overloading
	```cpp
	#include <iostream>
	using namespace std;
	class complex
	{
	public:
	    int r, i;
	
	    complex(int r = 0, int i = 0)
	    {
	        this->r = r;
	        this->i = i;
	    }
	
	    friend complex operator+(complex c1, complex c2);
	
	} c1(1, 2), c2(3, 4), c3;
	
	complex operator+(complex c1, complex c2)
	{
	    complex temp;
	    temp.r = c1.r + c2.r;
	    temp.i = c1.i + c2.i;
	    return temp;
	}
	
	int main()
	{
	    c3 = c1 + c2;
	    cout << c1.r << " + " << c2.r << " = " << c3.r << endl;
	    cout << c1.i << "i + " << c2.i << "i = " << c3.i << "i ";
	
	    return 0;
	}
	```
	- reason for using friend: the friend function accepts 2 objects c1 and c2 of class complex
		- objects c1 and c2 are not available in the scope of the class
- insertion operator loading using `cout<<c`
	- where c is a complex number and we will overload insertion operator `<<` to print both real and imaginary parts.
	- we will have to use a friend function and also pass `cout` to it
	```cpp
	#include <iostream>
	using namespace std;
	class complex
	{
	public:
	    int r, i;
	
	    complex(int r = 0, int i = 0)
	    {
	        this->r = r;
	        this->i = i;
	    }
	
	    friend ostream &operator<<(ostream &out, complex &c);
	} cnum(1, 2);
	
	ostream &operator<<(ostream &out, complex &c)
	{
	    out << c.r << " + " << c.i << "i";
	    return out;
	}
	
	int main()
	{
	    cout << cnum;
	    return 0;
	}
	```
	- we are returning `ostream` so that insertion operator can be chained
		- `cout<<cnum<<endl;` is valid
		- if we replace `ostream` return type with void then we cannot chain insertion operator.

***Inheritance***
- well designed classes using inheritance
	```cpp
	#include <iostream>
	using namespace std;
	
	class rectangle
	{
	    int len, brd;
	public:
	    rectangle(int len = 0, int brd = 0);
	    int getLen();
	    int getBrd();
	    int validator(int qty);
	    void setLen(int len);
	    void setBrd(int brd);
	    int area();
	    int peri();
	};
	rectangle::rectangle(int len, int brd) // default values are not repeated again
	{
	    this->len = len;
	    this->brd = brd;
	}
	int rectangle::getLen()
	{
	    return len;
	}
	int rectangle::getBrd()
	{
	    return brd;
	}
	int rectangle::validator(int qty)
	{
	    if (qty < 0)
	    {
	        cout << qty << "is a non positive number, invalid input";
	        exit(0);
	    }
	    return qty;
	}
	void rectangle::setLen(int len)
	{
	    this->len = validator(len);
	}
	void rectangle::setBrd(int brd)
	{
	    this->brd = validator(brd);
	}
	int rectangle::area()
	{
	    return len * brd;
	}
	int rectangle::peri()
	{
	    return 2 * (len + brd);
	}
	
	class cuboid : public rectangle
	{
	    int hgt;
	public:
	    cuboid(int len = 0, int brd = 0, int hgt = 0);
	    int getHgt();
	    void setHgt(int brd);
	    int volume();
	};
	cuboid::cuboid(int len, int brd, int hgt)
	{
	    this->hgt = hgt;
	    setLen(validator(len));
	    setBrd(validator(brd));
	}
	int cuboid::getHgt()
	{
	    return hgt;
	}
	void cuboid::setHgt(int hgt)
	{
	    this->hgt = validator(hgt);
	}
	int cuboid::volume()
	{
	    return getLen() * getBrd() * hgt;
	}
	```
- if you are inheriting a class then you cannot rely on the constructor of that class
	- so you need to make sure that the constructor of the child function can also initialize parent variables 
- note that when using scope resolution operator `::` to write functions outside the class then don't need to rewrite the default values outside the class
	- it is considered re declaration of the function 
- constructors in inheritance
	- if a child class is inheriting from the parent class in public mode such that a default constructor in parent class exists then when the object of the derived class is created then the default constructor of parent class is called first followed by a constructor of child class
		- how to call the parameterized constructor of the parent class ?
			```cpp
			#include <iostream>
			using namespace std;
			
			class papa
			{
			public:
			    papa(int x) { cout << "Papa has " << x << endl; }
			};
			
			class son : public papa
			{
			public:
			    son(int y, int z) : papa(z) // we write this becuase the constructor cannot be called like a setter function.
			    {
			        cout << "son has " << y << endl;
			        cout << "papa has " << z;
			    }
			};
			
			int main()
			{
			    son betaji(10, 20);
			
			    return 0;
			}
			
			// Papa has 20
			// son has 10
			// papa has 20
			```
			- when the constructor of the child class is called then its not immediately executed, instead the parameterized parent class constructor is called by giving it one parameter of the parameterized child class constructor. After the parameterized parent class constructor executes the control goes back to the parameterized base class constructor and it gets executed.
- isA and hasA
	- a class can be used by another class in two ways: one by inheriting it (isA) and one by creating an object of it (hasA).
	- when a class cuboid inherits a class rectangle, the cuboid is a rectangle.
	- when a class table uses an object of rectangle then the table has a rectangle.
- virtual parent classes
	- 2 parent classes inherit from a grandparent class and a child class inherits from both the parent classes
		- then the functions of the grandparent class can be accessed by 2 paths. This is multi path inheritance.
			- to remove this ambiguity we use virtual parent classes
				- just add keyword `virtual` before inheritance mode for the 2 parents
- inheritance mode:
	- if a class is inherited in public mode
		- private cannot be accessed but public remains public and protected remains protected.
	- protected mode:
		- public and protected variables and functions of the parent class become protected in the child class and private is not accessible.
		- further inheritance is possible but the protected members cannot be accessed outside the parent and child class. 0
	- private mode:
		- public and protected variables and functions of the parent class become private in the child class.
		- further inheritance is not possible
- 2 ways to use inheritance
	- to generalize: you have square rectangle parallelogram trapezium so you can create a parent class quadrilateral
	- to specialize: you have parallelogram, you can create child classes square and rectangle 
- parent class pointer and child class object `beta b; papa *papaptr = &b` or `papa *papaptr = new beta();`
	- if you use have a child class publicly inheriting from the parent class such that the child class object is created first and the parent class pointer points to the object of the child class (usually both should be same data type) and then you cannot call functions of the child class
	- suppose a class cuboid is the child class which inherits from parent class rectangle such that the pointer points to rectangle papa and is allocated heap address using new cuboid which is the child instead of rectangle papa then using pointer we can only call the function of rectangle papa and not the function of cuboid beta.
	- the opposite: child class pointer and parent class object is not possible and is an error   
	- the constructors are called from child to parent
- function overriding 
	- if the child class beta inherits from parent class papa such that there is a function which has the same name and parameters in both the classes and an object of beta is created and that function with common name is called, then how do we get to control which of the 2 functions are called?
		- example if a beta is a new car and papa is the old car which has manual windows and the new car has power windows then the function is same but there is variation
	- without making any manual effort to address this, if an object of beta is created and that function is called with a common name the compiler calls the one in the child class as it is closer in scope.
	- if the name of the two functions are same and there is a variation in the parameters it takes then whenever you call the papa ke functions then it becomes function overloading instead of overriding
	- if we have the same situation (same name functions in 2 classes that have inheritance relationship) with parent class pointer and child class object and call that function the parent class function is called and not the one nearer to the scope which is in the beta class.
		- if 2 functions have common name in separate classes having a inheritance relationship with parent class pointer and child class object then if we make on such function virtual by adding virtual keyword before return type then the non virtual function is called
- so we can demonstrate run time polymorphism by using virtual functions with function overriding with parent class pointer and child class object  
	```cpp
	#include <iostream>
	using namespace std;
	class anyCar
	{
	public:
	    virtual void start() = 0;
	    // {cout << "started a generic car" << endl;}
	    virtual void stop() = 0;
	    // {cout << "stopped a generic car" << endl;}
	};
	
	class swift : public anyCar
	{
	public:
	    void start()
	    {
	        cout << "started swift" << endl;
	    }
	    void stop()
	    {
	        cout << "stopped swift" << endl;
	    }
	};
	class innova : public anyCar
	{
	public:
	    void start()
	    {
	        cout << "started innova" << endl;
	    }
	    void stop()
	    {
	        cout << "stopped innova" << endl;
	    }
	};
	
	int main()
	{
	    anyCar *ptr = new swift();
	    ptr->start();
	    ptr->stop();
	    ptr = new innova();
	    ptr->start();
	    ptr->stop();
	
	    return 0;
	}
	```
		- genrealization of swift and innova so we can get away by just decalering empty virtual functions as we will never start a generic car, it has to have a modelbut when u do this make virtual functions = 0 then they are called pure virtual functions.
		- a class with pure virtual function is called abstract class
		- you cannot create objects of abstract classes but you can make pointer objects to them
		- 3 possible use cases of inheritance 
			- if all functions of the class are non virtual then the its use is reusability 
			- if some functions are virtual then both uses reusability and polymorphism 
			- and if all virtual functions then only use is to achieve polymorphism and such a class is called an interface
- Friend functions
	- functions outside the class which want to access the private and protected variables/functions can be declared as friend functions inside the class to give them the access.
	- we add `friend` before the return type of the function in the class. 
- friend class  
	- if an external class uses an object of another class as its data members then if it wants to access the private and protected variables/functions we use a friend class
	- declare the class which wants to access private and protected variables/functions as friend class inside the class whose object its creating. 
	- add line `friend <name of the class that wants to access the private and protected variables/functions using objects of the class this line is in>`
- a friend relationship cannot modify data and is read only
- static variables:
	- memory allocated by declaring a variable as static is shared between objects and changes to them are persistent across the lifetime of objects 
	- static members can be used outside the class using scope resolution operator without having to create an object of the class
- static functions are similar but cannot access non static variable
- nested class can access members of outer class if they are static
	- but it can create an object of the outer class to access its members
	- a nested class acts independently as if it were an outer class

***exception handling***
- during runtime errors
- if there is any error in the try block then the control moves to the catch block
	- the remaining lines of try block are not executed
	- catch block will not execute if no errors in try block
- to move the control use throw in the try block.
- `throw var` then var needs to be a parameter of the catch block
	- `var` usually used to throw codes
```cpp
#include <iostream>
using namespace std;

int divider(int x, int y)
{
    if (y == 0)
    {
        throw 404;
    }
    return x / y;
}

int main()
{
    try
    {
        divider(10, 0);
        cout << "I am bout to divide by 0";
    }
    catch (int err)
    {
        cout << "Oops, ";
    }
    cout << "Pakad liya";

    return 0;
}
// Oops, Pakad liya
```
- the main use of try catch is when a function is expected to return a value but is not able to then what should it return? ans throw exception.
	- if we know that the function can throw exception call it in try block
- you can throw any data type including object of a class
	- when throwing an object of a class, a good practice is to make sure that the class that might throw exception is inheriting publicly from c++'s built in class called exception
	- Throwing a constructor will create the object and then throw.
- you can declare what a function throws by appending `throw (<data type thrown>)` at the end of the function signature but this step is optional 
	- if you keep this round bracket empty means that the function throws no exception.
```cpp
#include <iostream>
using namespace std;

int divider(int x, int y)
{
    if (y == 0)
    {
        throw string("DivZer0");
    }
    return x / y;
}

int main()
{
    try
    {
        divider(10, 0);
        cout << "Lets Divide!" << endl;
    }
    catch (const string &err)
    {
        cout << "Oops, Error:" << err << endl;
    }
    cout << "Program Ended";

    return 0;
}
// Oops, Error:DivZer0
// Program Ended
```
- you can write multiple catch blocks for single try block that handle different data types of thrown variables
	- if you do `catch(...)` then the catch block can catch all thrown exceptions regardless of their type 
	- write this as the last catch block and not the first one if you are using multiple catch blocks
		- otherwise if the catch all block is at the top then it will handle all exceptions and the catch blocks below it will always be unused
	- if you are throwing objects of multiple classes in a try block such that the classes have an inheritance relationship then the catch block at the top should deal with the child class and the next catch block should deal with the parent class 

***Template functions and classes***
- used for generic programming
```cpp
#include <iostream>
using namespace std;

template <class T>
T adder(T x, T y) { return x + y; }

int main()
{
    cout << adder(10, 5) << endl;
    cout << adder(3.14, 6.023) << endl;

    return 0;
}
```
	- here the function can only accept variables that are of the same data type
- for a function to accept 2 generic variables of two different types'
	```cpp
	#include <iostream>
	using namespace std;
	
	template <class T, class R>
	R adder(T x, R y) { return x + y; }
	
	int main()
	{
	    cout << adder(10, 3) << endl;
	    cout << adder(10, 3.14) << endl;
	
	    return 0;
	}
	```
		- we can still pass two variables of the same data type
- useful if you are going to create generic data structures and perform operations on them
	```cpp
	#include <iostream>
	using namespace std;
	
	template <class T>
	class Stack
	{
	    T *stk;
	    int top;
	    int size;
	
	public:
	    Stack(int sz)
	    {
	        size = sz;
	        top = -1;
	        stk = new T[size];
	    }
	    void push(T x);
	    T pop();
	};
	template <class T>
	void Stack<T>::push(T x)
	{
	    if (top == size - 1)
	        cout << "Stack is Full";
	    else
	    {
	        top++;
	        stk[top] = x;
	    }
	}
	template <class T>
	T Stack<T>::pop()
	{
	    T x = 0;
	    if (top == -1)
	        cout << "Stack is Empty" << endl;
	    else
	    {
	        x = stk[top];
	        top--;
	    }
	    return x;
	}
	int main()
	{
	    Stack<float> s(10);
	    s.push(10);
	    s.push(23);
	    s.push(33);
	}
	```

***pointers and constants***
```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 10;

    int *ptr = &x;
    (*ptr)++;

    int const *ptr2 = &x;
    // (*ptr2)++; error
    int y = 20;
    ptr2 = &y;
    // (*ptr2)++; error

    int *const ptr3 = &y;
    (*ptr3)++;
    // ptr3 = &x; error

    const int *const ptr4 = &y;
    // (*ptr4)++; error
    // ptr4 = &x; error

    cout << x << " " << y << " " << *ptr2 << " " << *ptr4;
}
// 11 21 21 21
```
	- if variable is const and a ptr is pointing to it then the pointer ptr should be const of the data type not as a pointer which it can also be at the same time but will require 2 consts in declaration.
	- you cann still point to the const of a data type of a variable without it having to be a constant

***if we write `const` at the end of a function signature in a class then the compiler will  not allow that functions to modify values of the class***
	- you can also make a parameter in call by reference const to add some restrictions on what a function can do with the variables.

***pre-processor directives***
- if a constant is needed across all files
```cpp
#define x 10
#define c cout
#include <iostream>
using namespace std;
int main()
{
    c << x;
}
```
- we can also define functions:
```cpp
#define sqr(x) (x * x)
#define show(x) (cout << x);
#include <iostream>
using namespace std;
int main()
{
    show(sqr(5));
}
```
- we use ifndef to def only if not defined already
```cpp
#ifndef sqr
#define sqr(x) (x * x)
#endif

#ifndef show
#define show(x) (cout << x);
#endif

#include <iostream>
using namespace std;
int main()
{
    show(sqr(5));
}
```

***Destructors***
- called when the object goes out of the scope
- if the object is created in HEAP and deleted then the destructor gets called
- if a file is opened in  a class then it should be closed in the destructor
- or any HEAP allocations made in the class should be deleted in the destructor
- during inheritance
	- first the parent constructor is called
	- the the child constructor is called
	- at the end the child destructor is called
	- then the parent destructor is called
	- if we have a parent pointer and child object and used delete ptr then
		- only parent class destructor will be called
		- to fix this make the parent class destructor virtual
			- then parent class destructor is called the child class

***Streams***
- for input and output
- iostream has istream for input and ostream for output
- cin is an object of istream and cout is an object os ostream
- insertions and extraction operator are used and sometimes overloaded
- File handling:
	- writing
		```cpp
		#include <fstream>
		using namespace std;
		int main()
		{
		    ofstream outfile("hello.txt");
		    // if the file doesn't exist, it is created anf if it does then it becomes empty
		    // if you dont want to lose the pre existing data and want to append instead specify append mode app or truncate mode trunc(default)
		    // ofstream outfile("hello.txt",ios::app);
		    outfile << "HI" << endl;
		    outfile << 123 << endl;
		    outfile.close();
		}
		```
	- reading
		```cpp
		#include <iostream>
		#include <fstream>
		using namespace std;
		int main()
		{
		    ifstream infile;
		    infile.open("hello.txt");
		    if (!infile.is_open())
		        cout << "Cannot open file, maybe invalid name";
		    string str;
		    int n;
		    infile >> str;
		    infile >> n;
		    cout << str << endl << n;
		    infile.close();
		}
		```

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
			- map is used to store key value pairs with all keys unique
			- multi map allows duplicate keys but key value pair should be unique
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

`decltype(x) y` is used to create a variable y of data type x;

if a class is marked final by adding keyword final after the class name then the class cannot be inherited further
In C++, the `final` keyword can be used to prevent a virtual function from being overridden in child classes

lambda functions are unnamed functions
- `[](){cout<<"Hello World";}();`
- `[](int a , int b){cout<<"Sum is = "<<a+b;}(10,5);`
- `int x = [](int a , int b){return a+b;}(10,5);`
- `auto f = [](){cout<<"Hello World";};` and f() can be used later
- we can specify return type but not compulsory `int x = [](int a , int b)->int{return a+b;}(10,5);` 
- accessing variables outside the lambda expression
	```cpp
	#include <iostream>
	using namespace std;
	int main()
	{
	    int a = 10, b = 20, c = 30;
	    [&a, &b](){ cout << a << " " << b<< endl; }();
	    [&](){ cout << a << " " << b << " " << c; }();
	}
	```

smart pointer:
- deallocates itself when ptr not in scope

ellipsis `...`
- allows a function to take multiple args


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