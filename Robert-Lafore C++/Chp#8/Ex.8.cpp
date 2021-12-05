/*
Ex.8 : Modify the bMoney class from Exercise 12 in Chapter 7, “Arrays and Strings,” to include
the following arithmetic operations, performed with overloaded operators:
bMoney = bMoney + bMoney
bMoney = bMoney - bMoney
bMoney = bMoney * long double (price per widget times number of widgets)
long double = bMoney / bMoney (total price divided by price per widget)
bMoney = bMoney / long double (total price divided by number of widgets)
Notice that the / operator is overloaded twice. The compiler can distinguish between the
two usages because the arguments are different. Remember that it’s easy to perform
arithmetic operations on bMoney objects by performing the same operation on their long
double data.

Make sure the main() program asks the user to enter two money strings and a floatingpoint
number. It should then carry out all five operations and display the results. This
should happen in a loop, so the user can enter more numbers if desired.

Some money operations don’t make sense: bMoney * bMoney doesn’t represent anything
real, since there is no such thing as square money; and you can’t add bMoney to long
double (what’s dollars plus widgets?). To make it impossible to compile such illegal
operations, don’t include conversion operators for bMoney to long double or long
double to bMoney. 

If you do, and you write an expression like
bmon2 = bmon1 + widgets; // doesn’t make sense
then the compiler will automatically convert widgets to bMoney and carry out the addition.
Without them, the compiler will flag such conversions as errors, making it easier to catch
conceptual mistakes. Also, make any conversion constructors explicit.
There are some other plausible money operations that we don’t yet know how to perform
with overloaded operators, since they require an object on the right side of the operator
but not the left:
long double * bMoney // can’t do this yet: bMoney only on right
long double / bMoney // can’t do this yet: bMoney only on right
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath> 

using namespace std;

long double mstold(string s);
string ldtoms(long double sum);

class bMoney 
{
	long double money;

public:
	bMoney();
	bMoney(long double m);

	void madd(bMoney m1, bMoney m2);
	void getmoney();
	void putmoney();

	bMoney operator +(bMoney other) 
	{
		return bMoney(other.money + money);
	}

	bMoney operator -(bMoney other) 
	{
		return bMoney(money - other.money);
	}

	bMoney operator *(bMoney other) 
	{
		return bMoney(other.money * money);
	}

	bMoney operator /(bMoney other) 
	{
		return bMoney(money / other.money);
	}

	bMoney operator *(long double n) 
	{
		return bMoney(money * n);
	}

	/*friend long double operator /(bMoney b1, bMoney b2) 
	{
		long double temp;
		temp = b1.money + b2.money;
		return temp;
	}*/
};

bMoney::bMoney() 
{ 
	money = 0; 
}

bMoney::bMoney(long double m) 
{ 
	money = m; 
}

void bMoney::madd(bMoney m1, bMoney m2) 
{
	money = m1.money + m2.money;
}

void bMoney::getmoney() 
{
	string s;
	cin >> s;
	money = mstold(s);
}

void bMoney::putmoney() 
{
	string s = ldtoms(money);
	cout << s << endl;
}

int main() 
{
	bMoney b1, b2, b3;
	char ch;

	do {
		cout << "Enter amount of money: ";
		b1.getmoney();

		cout << "Enter amount of money: ";
		b2.getmoney();

		cout << "The sum of this money amounts: ";
		b3 = b1 + b2; b3.putmoney();

		cout << "The substraction of this money amounts: ";
		b3 = b1 - b2; b3.putmoney();

		cout << "The multiple of this money amounts: ";
		b3 = b1 * b2; b3.putmoney();

		cout << "The divide of this money amounts: ";
		b3 = b1 / b2; b3.putmoney();

		cout << "The multiple of first money amount with another which is out of class: ";
		b3 = b1 * 251348751; b3.putmoney();

		cout << "Would you want to continue? (y/n)";
		cin >> ch;

	} while (ch == 'y');

	return 0;
}

long double mstold(string s) {
	long double sum = 0;
	int p = 0;
	for (int i = 1; i < s.size(); i++) {
		if (48 <= static_cast<int>(s[i]) && static_cast<int>(s[i]) <= 57)
			sum = sum * 10 + static_cast<int>(s[i]) - 48;
		else if (s[i] == '.')
			p = i;
	}
	long double frac_part = pow(10, s.size() - 1 - p);
	sum /= frac_part;
	return sum;
}
string ldtoms(long double sum) {
	stringstream ss(stringstream::in | stringstream::out);
	ss.setf(ios::fixed);
	ss << setprecision(2) << sum;
	string s = ss.str();
	s.insert(0, "$");
	int p = s.find('.') - 1, n = 0;
	for (int i = p; i > 0; i--)
		if (++n % 3 == 0)
			s.insert(i, ",");
	return s;
}