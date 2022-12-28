/*********************
Name: Jade Shackelford
Coding 02
Purpose: define objects of class circle & sphere and display them
**********************/

#include "sphere.h"

Sphere::Sphere() {
	setRadius(0);
}

Sphere::Sphere(int r){
	setRadius(r);
}

Sphere::~Sphere() {
}

int Sphere::getArea() {
	return 4 * 3.14 * radius * radius;
}

int Sphere::getVolume() {
	return 4 / 3 * 3.14 * radius * radius * radius;
}
