/*
Ex.12 : Note that one advantage of the OOP approach is that an entire class can be used, without
modification, in a different program. Use the fraction class from Exercise 11 in a program
that generates a multiplication table for fractions. Let the user input a denominator,
and then generate all combinations of two such fractions that are between 0 and 1, and
multiply them together. Here’s an example of the output if the denominator is 6:
1/6 1/3 1/2 2/3 5/6
-----------------------------------------
1/6 1/36 1/18 1/12 1/9 5/36
1/3 1/18 1/9 1/6 2/9 5/18
1/2 1/12 1/6 1/4 1/3 5/12
2/3 1/9 2/9 1/3 4/9 5/9
5/6 5/36 5/18 5/12 5/9 25/36
*/

#include <iostream>
#include <iomanip> // for setw manipulator
using namespace std;

class fraction 
{
	int numerator;
	int denominator;

public:
	fraction(int n, int d) : numerator(n), denominator(d) 
	{}

	void calc(fraction f1, fraction f2) 
	{
		numerator = f1.numerator * f2.numerator;
		denominator = f1.denominator * f2.denominator;
	}
	void set_data(int n, int d) 
	{ 
		numerator = n, denominator = d; 
	}
	void displayN() 
	{ 
		cout << numerator << "/" << denominator; 
	}
	void display() 
	{ 
		cout << setw(8) << numerator << "/" << denominator; 
	}
	void lowestTerm();
};

void fraction::lowestTerm() 
{
	long tnum, tden, temp, gcd;

	tnum = labs(numerator);
	tden = labs(denominator);

	if (tden == 0) 
	{
		cout << "Illegal fraction: division by 0";
		exit(1);
	}
	else if (tnum == 0) 
	{
		numerator = 0;
		denominator = 1;
		return;
	}

	while (tnum != 0) 
	{
		if (tnum < tden) 
		{
			temp = tnum;
			tnum = tden;
			tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	numerator = numerator / gcd;
	denominator = denominator / gcd;
}

int main() 
{
	fraction f1(0, 0), f2(0, 0), f3(0, 0);
	int x;
	char ch;

	do {
		cout << "Enter a number: ";
		cin >> x;
		cout << "   ";

		for (int i = 1; i < x; i++) 
		{
			f1.set_data(i, x);
			f1.lowestTerm();
			f1.display();
		}
		for (int j = 1; j < x; j++) 
		{
			cout << "\n";
			f1.set_data(j, x);
			f1.lowestTerm();
			f1.displayN();

			for (int k = 1; k < x; k++) 
			{
				f2.set_data(k, x);
				f3.set_data(j, x);
				f1.calc(f2, f3);
				f1.lowestTerm();
				f1.display();

			}
		}

		cout << "\nWould you want to continue? (Y/N)";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');

	return 0;
}