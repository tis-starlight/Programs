/*
Ex.1 : Create a class that imitates part of the functionality of the basic data type int. Call the
class Int (note different capitalization). The only data in this class is an int variable.
Include member functions to initialize an Int to 0, to initialize it to an int value, to display
it (it looks just like an int), and to add two Int values.
Write a program that exercises this class by creating one uninitialized and two initialized
Int values, adding the two initialized values and placing the response in the uninitialized
value, and then displaying this result.
*/

#include <iostream>
using namespace  std;

class Int	//(not the same as int)
{
private:
	int i;

public:
	Int() : i(0) //create an Int
	{}
	Int(int ii) //create and initialize an Int
	{
		i = ii;
	}
	void add(Int i2, Int i3) //add two Ints
	{
		i = i2.i + i3.i;
	}
	void display() //display an Int
	{
		cout << i;
	}
};

int main()
{
	Int Int1(8);		//create and initialize an Int
	Int Int2(10);		//create and initialize an Int
	Int Int3;			//create an Int

	Int3.add(Int1, Int2);					//add two Ints
	cout << "\nInt3 = ";
	Int3.display();							//display result
	cout << endl;

	return 0;
}