***Input Buffer***
- When the user input is `cin>>anInteger;` and the next input on the next line is `cin>>str;` then the enter key pressed after typing the number is saved as input buffer and later take in by the `cin>>str;` to avoid this use **`cin.ignore();`** between `cin>>anInteger;` and `cin>>str;`.

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

***Type Defination***
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
- `for (auto x : A)` where the compiler takes care of the data type of x.
- changing the value of x doesn't change the array element because x is a copy.
	- To avoid this you can used `int &x : A` instead of `int x : A` 