***Input Buffer***
- When the user input is `cin>>anInteger;` and the next input on the next line is `cin>>str;` then the enter key pressed after typing the number is saved as input buffer and later take in by the `cin>>str;` to avoid this use **`cin.ignore();`** between `cin>>anInteger;` and `cin>>str;`

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
- day is a user defined data type which can only have names mon,tue,wed,thr,fri,sat,sun automatically it gets a value
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
- So lets say a school app has `int m1,m2,m3,r1,r2,r3` where mX are marks in subject X and rX is the roll number X
- To make it more readable we use typedef to alias the data type of rX from int to roll and of mX from int to marks
	`typedef int marks;`
	`typedef int roll;`
	`marks m1, m2, m3;`
	`roll r1, r2, r3;`

***For Each Loop***
- if `int A[] = {1, 2, 3, 4, 5};` and 
- `for (int x : A)`
	`cout << x;`
- `for (auto x : A)` where the compiler takes care of the data type of x
- changing the value of x doesn't change the array element because x is a copy
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
- When a 2-D Array is created, all the elements are contiguous in the memory.
- Have to use reference of x when A is 2-D array in a for each loop but you still need to use nested for each loop. 
	```cpp
	#include <iostream>
	using namespace std;
	int main()
	{
	    const int A[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

	    for (auto &i : A)
	    {
	        for (auto &j : i)
	            cout << j << " ";
	        cout << endl;
	    }

	    return 0;
	}
	```
	- `const int A[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}};` is invalid


