/*
Ex.3 : Create a class called time that has separate int member data for hours, minutes, and
seconds. One constructor should initialize this data to 0, and another should initialize it
to fixed values. Another member function should display it, in 11:59:59 format. The final
member function should add two objects of type time passed as arguments.

A main() program should create two initialized time objects (should they be const?) and
one that isn’t initialized. Then it should add the two initialized values together, leaving the
result in the third time variable. Finally it should display the value of this third variable.
Make appropriate member functions const.
*/

#include <iostream>
using namespace std;

class Time
{
private:
	int hrs, mins, secs;

public:
	Time() : hrs(0), mins(0), secs(0) //no-arg constructor
	{ }
	//3-arg constructor
	Time(int h, int m, int s) : hrs(h), mins(m), secs(s)
	{ }
	void display() const			//format 11:59:59
	{
		cout << hrs << " hours : " << mins << " minutes : " << secs << " seconds";
	}
	void add_Time(Time t1, Time t2)		//add two times
	{
		secs = t1.secs + t2.secs;		//add seconds

		if (secs > 59)					//if overflow,
		{
			secs -= 60; mins++;
		} // carry a minute

		mins += t1.mins + t2.mins; //add minutes

		if (mins > 59) //if overflow,
		{
			mins -= 60; hrs++;
		} // carry an hour

		hrs += t1.hrs + t2.hrs; //add hours
	}
};

int main()
{
	const Time t1(5, 59, 59); //creates and initialze
	const Time t2(4, 30, 30); // two times
	Time t3;				//create another time

	t3.add_Time(t1, t2);	//add two times

	cout << "t3 = "; 
	t3.display();			//display result
	cout << endl;

	return 0;
}