/*
Ex.4 : Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
comprise an int for storing the employee number and a float for storing the employee’s
compensation. Member functions should allow the user to enter this data and display it.
Write a main() that allows the user to enter data for three employees and display it.
*/

#include <iostream>
using namespace std;

class employee 
{
private:
	int number_of_employee;
	float compensation;

public:
	employee() : number_of_employee(0), compensation(0.0)
	{}
	void getData(int n, float c) 
	{
		number_of_employee = n;
		compensation = c;
	}
	void display() 
	{
		cout << "Number of employee: " << number_of_employee << "\n";
		cout << "Compesation of employee: " << compensation << "\n";
	}
};

int main() 
{
	employee emp[3]{};

	for (int i = 0; i < 3; i++) 
	{
		int n(0);
		float f(0.0);

		cout << "Enter the number of empolyee: "; 
		cin >> n;
		cout << "Enter the compensation of employee: "; 
		cin >> f;

		emp[i].getData(n, f);
	}

	cout << "\n\n---------The data of employees: \n\n";

	for (int i = 0; i < 3; i++)
		emp[i].display();

	return 0;
}