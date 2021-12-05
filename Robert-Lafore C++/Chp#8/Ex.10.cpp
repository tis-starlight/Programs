/*
Ex.10 : For math buffs only: Create a class Polar that represents the points on the plain as polar
coordinates (radius and angle). Create an overloaded +operator for addition of two
Polar quantities. “Adding” two points on the plain can be accomplished by adding their
X coordinates and then adding their Y coordinates. This gives the X and Y coordinates of
the “answer.” Thus you’ll need to convert two sets of polar coordinates to rectangular
coordinates, add them, then convert the resulting rectangular representation back to polar.
*/

#include <iostream>
#include <cmath>

#define Pi 3.14

using namespace std;

class Polar 
{
	float radius, angle, angular, xco, yco;

public:
	Polar() 
	{}
	Polar(float r, float a) : radius(r), angle(a) 
	{ 
		deg_to_rad(); 
		polar_to_rect(); 
	}

	void deg_to_rad() 
	{
		angular = angle * Pi / 180;
	}

	void rad_to_deg() 
	{
		angular = angular * 180 / Pi;
	}

	void polar_to_rect();
	void rect_to_polar();

	void get_polar();
	void display()const;

	Polar operator +(Polar);
};

int main() 
{
	Polar p1, p2, ps;

	cout << "Enter polar coordinate p1: \n";
	p1.get_polar();

	cout << "Enter polar coordinate p2: \n";
	p2.get_polar();

	cout << "p1= "; p1.display();
	cout << "\np2= "; p2.display();

	ps = p1 + p2;
	cout << "\nps(=p1+p2)= "; ps.display();

	return 0;
}

void Polar::polar_to_rect() 
{
	xco = radius * cos(angular);
	yco = radius * sin(angular);
}

void Polar::rect_to_polar() 
{
	radius = sqrt(pow(xco, 2) + pow(yco, 2));
	angular = atan(yco / xco);
	rad_to_deg();
}

void Polar::get_polar() 
{
	cout << "Enter radius: "; 
	cin >> radius;

	cout << "Enter angle in degrees: "; 
	cin >> angle;

	deg_to_rad();
	polar_to_rect();
}

void Polar::display()const 
{
	cout << radius << "\u2220" << angle << "ْْْْْْْْ°";
}

Polar Polar::operator +(Polar p2) 
{
	Polar p;
	p.xco = xco + p2.xco;
	p.yco = yco + p2.yco;

	p.rect_to_polar();
	p.rad_to_deg();

	return p;
}