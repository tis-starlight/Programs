/*
Ex.3 : Modify the time class from Exercise 3 in Chapter 6 so that instead of a function
add_time() it uses the overloaded + operator to add two times. Write a program to test
this class.
*/

#include <iostream>
using namespace std;

class Time
{
private:
	int hrs, mins, secs;
public:
	Time() : hrs(0), mins(0), secs(0)		 //no-arg constructor
	{ } 
	//3-arg constructor
	Time(int h, int m, int s) : hrs(h), mins(m), secs(s)
	{ }

	void display()		//format 11:59:59
	{
		cout << hrs << ":" << mins << " : " << secs;
	}
	Time operator + (Time t2)		//add two times
	{	
		int s = secs + t2.secs;		//add seconds
		int m = mins + t2.mins;		//add minutes
		int h = hrs + t2.hrs;		//add hours
		if (s > 59)					//if secs overflow,
		{
			s -= 60; m++;
		} // carry a minute
		if (m > 59) //if mins overflow,
		{
			m -= 60; h++;
		} // carry an hour
		return Time(h, m, s); //return temp value
	}
};

int main()
{
	Time t1(5, 59, 59);			//create and initialze
	Time t2(4, 30, 30);			// two times
	Time t3;						//create another time

	t3 = t1 + t2;			//add two times

	cout << "\ntime3 = "; 
	t3.display();		//display result

	cout << endl;
	return 0;
}