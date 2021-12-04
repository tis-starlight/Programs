/*
Ex.9 : Transform the fraction structure from Exercise 8 in Chapter 4 into a fraction class.
Member data is the fraction’s numerator and denominator. Member functions should
accept input from the user in the form 3/5, and output the fraction’s value in the same
format. Another member function should add two fraction values. Write a main() program
that allows the user to repeatedly input two fractions and then displays their sum. After
each operation, ask whether the user wants to continue.
*/

#include <iostream>
using namespace std;

class fraction 
{
private:
	int numerator;
	int denominator;
	char ch;

public:
	void setter(int, int);
	fraction sumOfFraction(fraction, fraction);

	void display();
};

void fraction::setter(int n, int d) 
{
	numerator = n;
	denominator = d;
	//ch = c;
}
fraction fraction::sumOfFraction(fraction f1, fraction f2) 
{
	fraction f;
	f.numerator = (f1.numerator * f2.denominator) + (f1.denominator * f2.numerator);
	f.denominator = f1.denominator * f2.denominator;
	return f;
}

void fraction::display() 
{
	cout << "The result of this two fractions: " << numerator << "/" << denominator << endl;
}

int main() 
{
	fraction fr1, fr2, fr3;
	char ch;

	do {
		int nn, dd; char cc;

		cout << "Enter first fraction (in this format x/y): ";
		cin >> nn >> cc >> dd;
		fr1.setter(nn, dd);

		cout << "Enter second fraction (in this format x/y): ";
		cin >> nn >> cc >> dd;
		fr2.setter(nn, dd);

		cout << "Do you want to sum this fractions?" << endl;
		cout << "if yes press to \'Y\' :";
		cin >> cc;

		if (cc == 'Y' || cc == 'y') 
		{
			fr3 = fr3.sumOfFraction(fr1, fr2);
			cout << "The sum of this fractions is: "; 
			fr3.display();
		}
		cout << "\nIf you want to continue press \'Y\' else press \'N\' :";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');

	return 0;
}
