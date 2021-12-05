/*
Ex.4 : Create a class Int based on Exercise 1 in Chapter 6. Overload four integer arithmetic
operators (+, -, *, and /) so that they operate on objects of type Int. If the result of any
such arithmetic operation exceeds the normal range of ints (in a 32-bit environment)—
from 2,147,483,648 to –2,147,483,647—have the operator print a warning and terminate
the program. Such a data type might be useful where mistakes caused by arithmetic overflow
are unacceptable. Hint: To facilitate checking for overflow, perform the calculations
using type long double. Write a program to test this class.
*/

#include <iostream>
#include <process.h>	//for exit()
using namespace std;

class Int
{
private:
	int i;

public:
	Int() : i(0)			//no-arg constructor
	{ }
	Int(int ii) : i(ii)		//1-arg constructor
	{ }						// (int to Int)

	void putInt()			//display Int
	{
		cout << i;
	}
	void getInt()			//read Int from kbd
	{
		cin >> i;
	}
	operator int()			//conversion operator
	{
		return i;
	}	// (Int to int)

	Int operator + (Int i2)		//addition
	{
		return checkit(long double(i) + long double(i2));
	}
	Int operator - (Int i2)		//subtraction
	{
		return checkit(long double(i) - long double(i2));
	}
	Int operator * (Int i2)		//multiplication
	{
		return checkit(long double(i) * long double(i2));
	}
	Int operator / (Int i2)		//division
	{
		return checkit(long double(i) / long double(i2));
	}
	Int checkit(long double answer)		//check results
	{
		if (answer > 2147483647.0L || answer < -2147483647.0L)
		{
			cout << "\nOverflow Error\n"; 
			exit(1);
		}
		return Int(int(answer));
	}
};

int main()
{
	Int alpha = 20;
	Int beta = 7;
	Int delta, gamma;

	gamma = alpha + beta;		//27
	cout << "\ngamma = "; 
	gamma.putInt();

	gamma = alpha - beta;		//13
	cout << "\ngamma = "; 
	gamma.putInt();

	gamma = alpha * beta;		//140
	cout << "\ngamma = "; 
	gamma.putInt();

	gamma = alpha / beta;		//2
	cout << "\ngamma = "; 
	gamma.putInt();

	delta = 2147483647;

	gamma = delta + alpha;		//overflow error

	delta = -2147483647;

	gamma = delta - alpha;		//overflow error

	cout << endl;
	return 0;
}