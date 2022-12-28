/*********************
Name: Jade Shackelford
Coding 02
Purpose: define objects of class circle & sphere and display them
**********************/

#include "main.h"

int main(int argc, char** argv) {
	//create circle objects using both constructors
	Circle myCircle1;
	Circle myCircle2(3);
	
	//does the same as the above but with the Sphere class
	Sphere mySphere1;
	Sphere mySphere2(2);
	
	//these call the functions which display the values of the sphere
	displayCircle(&myCircle1);
	displayCircle(&myCircle2);
	
	displaySphere(&mySphere1);
	displaySphere(&mySphere2);
	
	return 0;
}
