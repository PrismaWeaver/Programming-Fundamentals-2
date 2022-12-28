/*********************
Name: Jade Shackelford
Coding 02
Purpose: define objects of class circle & sphere and display them
**********************/

#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"

class Sphere : public Circle {
	public:
		//contstructors overloaded for with/without param
		Sphere();
		Sphere(int);
		//deconstructor
		~Sphere();
		
		//getters
		int getArea();
		int getVolume();	
};

#endif //CLASSES_SPHERE_H
