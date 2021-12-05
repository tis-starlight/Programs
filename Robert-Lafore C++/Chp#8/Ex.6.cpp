/*
Ex.6 : Add to the time class of Exercise 5 the ability to subtract two time values using the
overloaded (-) operator, and to multiply a time value by a number of type float, using
the overloaded (*) operator.
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
		int h = hours;
		int m = minutes;
		int s = seconds;

		if (s > 59) 
		{
			s -= 60;
			m++;
		}
		if (m > 59) 
		{
			m -= 60;
			h++;
		}

		cout << "Time: " << h << ":" << m << ":" << s << endl;
	}

	Time operator -(Time other);
	Time operator *(float);
};

Time Time::operator -(Time other) 
{
	return Time(abs(other.hours - hours), abs(other.minutes - minutes), abs(other.seconds - seconds));
}

Time Time::operator *(float fl) 
{
	int h = int(fl * hours);
	int m = int(fl * minutes);
	int s = int(fl * seconds);

	if (s > 59) 
	{
		s -= 60;
		m++;
	}
	if (m > 59) 
	{
		m -= 60;
		h++;
	}

	return Time(h, m, s);
}

int main() 
{
	Time time1, time2, time3, time4;

	time1 = { 6, 34, 29 };
	time2 = { 8, 47, 36 };

	time3 = time1 - time2;
	time3.display();

	time4 = time1 * 4.3;
	time4.display();

	return 0;
}