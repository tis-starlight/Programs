/*
Ex. 9 : Augment the safearay class in the ARROVER3 program in this chapter so that the user
can specify both the upper and lower bound of the array (indexes running from 100 to
200, for example). Have the overloaded subscript operator check the index each time the
array is accessed to ensure that it is not out of bounds. You’ll need to add a twoargument
constructor that specifies the upper and lower bounds. Since we have not yet
learned how to allocate memory dynamically, the member data will still be an array that
starts at 0 and runs up to 99, but perhaps you can map the indexes for the safearay into
different indexes in the real int array. For example, if the client selects a range from 100
to 175, you could map this into the range from arr[0] to arr[75].
*/

#include <iostream>
#include <process.h> 

using namespace std;

const int limit = 100;

class safearray 
{
	int arr[limit], min, max;

public:
	safearray() 
	{}
	safearray(int mx, int mn) : min(mn), max(mx) 
	{}

	int& operator [](int index) 
	{
		if (index > max || index < min) 
		{
			cout << "Index out of bounds." << endl;
			exit(1);
		}
		else
			return arr[index];
	}

	void arange();
};

void safearray::arange() 
{
	cout << "Enter the upper of array: "; 
	cin >> max;
	cout << "Enter the lower of array: "; 
	cin >> min;

	if (max - min >= limit) 
	{
		cout << "No of element greater than array size" << endl;
		exit(1);
	}
}

int main() 
{
	safearray sa;
	char ch, choise;
	int index, value;

	cout << "-------------------- Enter the range of upper and lower ----------------------- " << endl;
	sa.arange();

	do {
		cout << "Press P to put element, S to search about element: ";
		cin >> choise;

		if (choise == 'p' || choise == 'P') 
		{
			cout << "Enter index and value to put: ";
			cin >> index >> value;
			sa[index] = value;
		}
		else if (choise == 's' || choise == 'S') 
		{
			cout << "Enter index to search about its vlue: ";
			cin >> index;
			cout << "The value of this index is: " << sa[index] << endl;
		}

		cout << "Would you want to continue?(y/n)";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');

	return 0;
}