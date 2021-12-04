/*
Ex.2 : Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent
toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps
track of the number of cars that have gone by, and of the total amount of money collected.

Model this tollbooth with a class called tollBooth. The two data items are a type
unsigned int to hold the total number of cars, and a type double to hold the total amount
of money collected. A constructor initializes both of these to 0. A member function called
payingCar() increments the car total and adds 0.50 to the cash total. Another function,
called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a
member function called display() displays the two totals. Make appropriate member
functions const.

Include a program to test this class. This program should allow the user to push one key
to count a paying car, and another to count a nonpaying car. Pushing the Esc key should
cause the program to print out the total cars and total cash and then exit.
*/

#include <iostream>
#include <conio.h>		//for _getch()
using namespace std;

const char ESC = 27;		//escape-key ASCII code
const double TOLL = 0.5;	//toll is 50 cents (0.50)

class tollBooth
{
private:
	unsigned int totalCars; //total cars passed today
	double totalCash; //total money collected today

public: 
	tollBooth() : totalCars(0), totalCash(0.0)	//constructor
	{ }
	void payingCar()	//a car paid
	{
		totalCars++; totalCash += TOLL;
	}
	void nopayCar()		//a car didn’t pay
	{
		totalCars++;
	}
	void display() const //display totals
	{
		cout << "\nCars = " << totalCars
			 << ", Cash = " << totalCash
			 << endl;
	}
};

int main()
{
	tollBooth booth1;		//create a toll booth
	char ch(0);

	cout << "Press	0 for each non-paying car, "
		 << "\n		1 for each paying car, "
		 << "\n		Esc to exit the program.\n";

	do {
		ch = _getch();		//get character, getch() is deprecated

		if (ch == '0')		//if it’s 0, car didn’t pay
			booth1.nopayCar();

		if (ch == '1')		//if it’s 1, car paid
			booth1.payingCar();

	} while (ch != ESC);	//exit loop on Esc key

	booth1.display();		//display totals

	return 0;
}