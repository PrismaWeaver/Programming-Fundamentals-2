/*********************
Name: Jade Shackelford
Coding 02
Purpose: define objects of class circle & sphere and display them
**********************/

#include "circle.h"

Circle::Circle() {
	setRadius(0);
}

Circle::Circle(int r) {
	setRadius(r);
}

Circle::~Circle() {
}

int Circle::getRadius() {
	return radius;
}

int Circle::getCircumference() {
	//calculates circumference of a circle
	return 2 * 3.14 * radius;
}

int Circle::getArea() {
	//calculates area of a circle
	return 3.14 * radius * radius;
}

void Circle::setRadius(int r) {
	//check for valid number
	if (r > 0) {
		radius = r;
	}
	else {
		radius = 0;
	}
}
