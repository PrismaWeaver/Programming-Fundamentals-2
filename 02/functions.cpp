/*********************
Name: Jade Shackelford
Coding 02
Purpose: define objects of class circle & sphere and display them
**********************/

#include "functions.h"

void displayCircle(Circle *myCircle) {
	std::cout << "circle radius: " << myCircle->getRadius() << std::endl;
	std::cout << "circle circumference: " << myCircle->getCircumference() << std::endl;
	std::cout << "circle area: " << myCircle->getArea() << std::endl;
	std::cout << std::endl;
}

void displaySphere(Sphere *mySphere) {
	std::cout << "sphere radius: " << mySphere->getRadius() << std::endl;
	std::cout << "sphere surface area: " << mySphere->getArea() << std::endl;
	std::cout << "sphere volume: " << mySphere->getVolume() << std::endl;
	std::cout << std::endl;
}
