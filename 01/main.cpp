/*********************
Name: Jade Shackelford
Coding 01
Purpose: simple "hello world" program which outputs text
**********************/

#include "main.h"

int main(int argc, char** argv) {
    std::cout << "My Command line analyzer..." << std::endl;
	std::cout << "The number of command line parameters are: " << argc << std::endl; 
	//gets the number of characters in the first parameter, which is the portion of the command which calls "a.exe"
	//this works only when you execute a.exe by itself, running via ./a.exe sets argv[0] to the entire directory path
	//I designed a whole while loop that attempted to erase the erronious characters, but it over complicated what is supposed to be a simple program
	std::cout << "The length of the name of the program is: " << string_length(argv[0]) << std::endl;
	//argc in this example should always be at least 1 as running "a.exe" counts as 1 parameter
	if (argc > 1) {
		//parameterNumber is an incrimental used in conjunction with a while loop to progress through the argv array
		//its initialized with 1 to skip "a.exe"
		int parameterNumber = 1;
		//the while loop allows the function to account for large argc numbers
		//the condition exits the loop once it reaches the last parameter in the argv array
		while (parameterNumber < argc){
			std::cout << "The length of parameter " << parameterNumber << " is " << string_length(argv[parameterNumber]) << std::endl;
			//incrimental
			parameterNumber += 1;
		}
	} 
    return 0;
}
