/*********************
Name: Jade Shackelford
Coding 03
Purpose: create and test a simple stack
**********************/

#include "main.h"

int main(int argc, char** argv) {
    //this uses the system clock as a seed for the random number generator
    srand(time(0));
    Stack s1;
    int count = 0, input, output, option;
    bool success;
    std::cout << "will now test stack's ability to handle overflow\n";
    while (count <= (STACK_SIZE + 1)) {
        success = s1.push(count);
        if (success) {
            std::cout << "value " << count << " added to stack\n";
        }
        else {
            std::cout << "stack overflow\n";
        }
        count++;
    }
    std::cout << "will now test stack's ability to handle peek when in overflow\n";
    try {
        output = s1.peek();
        std::cout << "value " << output << " on stack\n";
    }
    catch (int e) {
        std::cout << "stack underflow\n";
    }
    count = 0;
    std::cout << "\n\nwill now test stack's ability to handle underflow\n";
    while (count <= (STACK_SIZE + 1)) {
        try {
            output = s1.pop();
            std::cout << "value " << output << " removed from stack\n";
        }
        catch (int e) {
            std::cout << "stack underflow\n";
        }
        count++;
    }
    std::cout << "will now test stack's ability to handle peek when in underflow\n";
    try {
        output = s1.peek();
        std::cout << "value " << output << " on stack\n";
    }
    catch (int e) {
        std::cout << "stack underflow\n";
    }
    count = 0;
    std::cout << "\n\nwill now test stack's ability to handle random inputs\n";
    while (count <= 100) {
        //this randomly selects an option between 0-2
        option = rand() % 3;
        switch (option) {
            case 0: {
                //this tests push with an int input
                input = rand();
                std::cout << "\ntesting push, inputting: " << input << std::endl;
                success = s1.push(input);
                if (success) {
                    std::cout << "value " << input << " added to stack\n";
                }
                else {
                    std::cout << "stack overflow\n";
                }
                count++;
                break;
            }
            case 1: {
                std::cout << "\ntesting pop\n";
                try {
                    output = s1.pop();
                    std::cout << "value " << output << " removed from stack\n";
                }
                catch (int e) {
                    std::cout << "stack underflow\n";
                }
                count++;
                break;
            }
            case 2: {
                std::cout << "\ntesting peek\n";
                try {
                    output = s1.peek();
                    std::cout << "value " << output << " on stack\n";
                }
                catch (int e) {
                    std::cout << "stack underflow\n";
                }
                count++;
                break;
            }
            default:
                std::cout << "this message means there was an error with the randomly selected option\n";
        }
    }
    std::cout << "\n\nthe stack has finished testing";
    return 0;
}
