/*********************
Name: Jade Shackelford
Coding 02
Purpose: define objects of class circle & sphere and display them
**********************/

#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

class Circle {
	
	public:
		//contstructors overloaded for with/without param
		Circle();
		Circle(int);
		//deconstructor
		~Circle();
		
		//getters
		int getRadius();
		int getCircumference();
		int getArea();
		
		//setters
		void setRadius(int);	
protected: 
		//private variables
		int radius;
};

#endif //CLASSES_CIRCLE_H
