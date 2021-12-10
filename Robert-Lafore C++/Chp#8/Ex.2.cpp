/*
Ex. 2 : Write a program that substitutes an overloaded += operator for the overloaded + operator
in the STRPLUS program in this chapter. This operator should allow statements like
s1 += s2;
where s2 is added (concatenated) to s1 and the result is left in s1. The operator should
also permit the results of the operation to be used in other calculations, as in
s3 = s1 += s2;
*/

#include <iostream>
#include <cstring>		//for strcpy(), strlen()
#include <process.h>		//for exit()
using namespace std;

class String		//user-defined string type
{
private:
	enum { SZ = 80 };	 //size of String objects
	char str[SZ];		//holds a C-string

public:
	String() 	//no-arg constructor
	{
		strcpy_s(str, "");
	}
	String(const char* s) //1-arg constructor
	{
		strcpy_s(str, s);
	}

	void display() //display the String
	{
		cout << str;
	}
	String operator += (String ss) //add a String to this one
	{		
		//result stays in this one

		if (strlen(str) + strlen(ss.str) >= SZ)
		{
			cout << "\nString overflow"; 
			exit(1);
		}

		strcat_s(str, ss.str); //add the argument string

		return String(str); //return temp String
	}
};

int main()
{
	String s1 = "Hello";	//uses 1-arg ctor
	String s2 = "World!";	//uses 1-arg ctor
	String s3;

	s3 = s1 += s2;			//add s2 to s1, assign to s3

	cout << "\ns1 = "; 
	s1.display();			//display s1

	cout << "\ns2 = "; 
	s2.display();			//display s2

	cout << "\ns3 = "; 
	s3.display();			//display s3

	cout << endl;
	return 0;
}
