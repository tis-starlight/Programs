/*
Ex.5 : Augment the time class referred to in Exercise 3 to include overloaded increment (++)
and decrement (--) operators that operate in both prefix and postfix notation and return
values. Add statements to main() to test these operators.
*/

#include <iostream>
using namespace std;

class Time 
{
private:
	int hours, minutes, seconds;

public:
	Time() : hours(0), minutes(0), seconds(0) 
	{}
	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) 
	{}

	void display() 
	{
		cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
	}

	void operator ++();
	void operator ++(int);
	void operator --();
	void operator --(int);
};

void Time::operator ++() 
{
	++hours;
	++minutes;
	++seconds;

	if (seconds > 59) 
	{
		seconds %= 60;
		minutes++;
	}
	else if (minutes > 59) 
	{
		minutes %= 60;
		hours++;
	}
}
void Time::operator ++(int) 
{
	hours++;
	minutes++;
	seconds++;
	if (seconds > 59) 
	{
		seconds %= 60;
		minutes++;
	}
	else if (minutes > 59) 
	{
		minutes %= 60;
		hours++;
	}
}
void Time::operator --() 
{
	--hours;
	--minutes;
	--seconds;
	if (seconds > 59) 
	{
		seconds %= 60;
		minutes++;
	}
	else if (minutes > 59) 
	{
		minutes %= 60;
		hours++;
	}
}
void Time::operator --(int) 
{
	hours--;
	minutes--;
	seconds--;
	if (seconds > 59) {
		seconds %= 60;
		minutes++;
	}
	else if (minutes > 59) 
	{
		minutes %= 60;
		hours++;
	}
}
int main() 
{
	Time time1, time2, time3, time4;

	time1 = { 6, 34, 29 };
	time2 = { 6, 25, 30 };

	++time1;
	++time2;

	time1++;
	time2++;

	time1.display();
	time2.display();

	--time1;
	time2--;
	time1--;
	time2--;

	time1.display();
	time2.display();

	return 0;
}