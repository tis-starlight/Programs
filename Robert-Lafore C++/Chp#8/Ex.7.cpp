/*
Ex. 7 : Modify the fraction class in the four-function fraction calculator from Exercise 11 in
Chapter 6 so that it uses overloaded operators for addition, subtraction, multiplication,
and division. (Remember the rules for fraction arithmetic in Exercise 12 in Chapter 3,
“Loops and Decisions.”) Also overload the == and != comparison operators, and use them
to exit from the loop if the user enters 0/1, 0/1 for the values of the two input fractions.

You may want to modify the lowterms() function so that it returns the value of its argument
reduced to lowest terms. This makes it more useful in the arithmetic functions, where it
can be applied just before the answer is returned.
*/

#include <iostream>
using namespace std;

class fraction 
{
private:
	int numerator;
	int denominator;

public:
	void set_fraction(int, int);
	void display();
	void lowestTerms();

	fraction operator +(fraction other);
	fraction operator *(fraction other);
	fraction operator -(fraction other);
	fraction operator /(fraction other);

	bool operator ==(fraction other);
	bool operator !=(fraction other);
};

fraction fraction::operator +(fraction other) 
{
	fraction temp;
	temp.numerator = numerator * other.denominator + denominator * other.numerator;
	temp.denominator = denominator * other.denominator;
	return temp;
}

fraction fraction::operator *(fraction other) 
{
	fraction temp;
	temp.numerator = numerator * other.numerator;
	temp.denominator = denominator * other.denominator;
	return temp;
}

fraction fraction::operator -(fraction other) 
{
	fraction temp;
	temp.numerator = numerator * other.denominator - denominator * other.numerator;
	temp.denominator = denominator * other.denominator;
	return temp;
}

fraction fraction::operator /(fraction other) 
{
	fraction temp;
	temp.numerator = numerator * other.denominator;
	temp.denominator = denominator * other.numerator;
	return temp;
}

bool fraction::operator ==(fraction other) 
{
	return (numerator / denominator == other.numerator / other.denominator) ? true : false;
}

bool fraction::operator !=(fraction other) 
{
	return (numerator / denominator != other.numerator / other.denominator) ? false : true;
}

void fraction::set_fraction(int n, int d) 
{
	numerator = n;
	denominator = d;
}

void fraction::lowestTerms() 
{
	long tnum, tden, temp, gcd;

	tnum = labs(numerator);
	tden = labs(denominator);

	if (tden == 0) 
	{
		cout << "Illegasl fraction: division by 0";
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

	cout << "The result of this frations is: " << numerator << "/" << denominator;
	cout << endl;
}

void fraction::display() 
{
	cout << "The result of this frations is: " << numerator << "/" << denominator << endl;
}

int main() 
{
	fraction fr1, fr2, fr3;
	char ch;

	do {
		int n, d;
		char c;

		cout << "Enter the first fraction (in this format x/y): ";
		cin >> n >> c >> d;
		fr1.set_fraction(n, d);

		cout << "Enter the second fraction (in this format x/y): ";
		cin >> n >> c >> d;
		fr2.set_fraction(n, d);

		if (fr1 == fr2) 
		{
			cout << "first fraction equal second fraction." << endl;
		}
		else 
		{
			cout << "first fraction not equal second fraction." << endl;
		}

		cout << "Enter the operator(+, -, *, /): ";
		cin >> c;

		switch (c) 
		{
		case '+':
			fr3 = fr1 + fr2;
			fr3.lowestTerms();
			break;
		case '*':
			fr3 = fr1 * fr2;
			fr3.lowestTerms();
			break;
		case '-':
			fr3 = fr1 - fr2;
			fr3.lowestTerms();
			break;
		case '/':
			fr3 = fr1 / fr2;
			fr3.lowestTerms();
			break;
		}
		cout << "Do you want to continue? (Y/N) ";
		cin >> ch;

	} while (ch == 'Y' || ch == 'y');

	return 0;
}