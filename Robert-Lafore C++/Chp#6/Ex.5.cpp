/*
Ex.5 : Start with the date structure in Exercise 5 in Chapter 4 and transform it into a date
class. Its member data should consist of three ints: month, day, and year. It should also
have two member functions: getdate(), which allows the user to enter a date in
12/31/02 format, and showdate(), which displays the date.
*/

#include <iostream>
using namespace std;

class date
{
private:
	int year, month, day;

public:
	date() : year(0), month(0), day(0)
	{}
	void getdate();
	void showdate();
};

void date::getdate() 
{
	char ch;
	cout << "Enter date in this format(dd/mm/yyyy): ";
	cin >> day >> ch >> month >> ch >> year;
}
void date::showdate() 
{
	cout << "the date is: " << day << "/" << month << "/" << year << endl;
}

int main() 
{
	date d1;

	d1.getdate();
	d1.showdate();

	return 0;
}

//////////////////////////////////(OR) Use this Class/////////////////////////////////////
/*
class date
{
private:
	int year, month, day;

public:
	date() : year(0), month(0), day(0)
	{}
	void getdate()
	{
		char ch;
		cout << "Enter date in this format(dd/mm/yyyy): ";
		cin >> day >> ch >> month >> ch >> year;
	}
	void showdate()
	{
		cout << "the date is: " << day << "/" << month << "/" << year << endl;
	}
};
*/