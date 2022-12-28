/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    // declare the empty struct Data that'll be passed by reference for pop() and peek()
    Data *ptr, myData;
    ptr = &myData;

    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    cout << "\nTesting isempty() on empty stack" << endl;
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    cout << "\nTesting peek() on empty stack" << endl;
    if (stack.peek(ptr)) {
        cout << (*ptr).id << ": " << (*ptr).information << " on stack" << endl;
    }
    else {
        cout << "Stack is empty" << endl;
    }

    cout << "\nTesting pop() on empty stack" << endl;
    if (stack.peek(ptr)) {
        cout << (*ptr).id << ": " << (*ptr).information << " popped"<< endl;
    }
    else {
        cout << "Stack is empty" << endl;
    }

    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack.
     */

    cout << "\nPushing all cases" << endl;
    for (int i = 0; i < number_test_cases; i++) {
        if (stack.push(ids[i], data[i])) {
            cout << ids[i] << ": " << data[i] << " added to stack" << endl;
        }
        else {
            cout << "Either information invalid or Stack is full" << endl;
        }
    }

    cout << "\nPopping all cases" << endl;
    for (int i = 0; i < number_test_cases; i++) {
        if (stack.pop(ptr)) {
            cout << (*ptr).id << ": " << (*ptr).information << " on stack" << endl;
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    cout << "\nBeginning random tests" << endl;
    int choice;
    int counter = 0, num = 0;
    while (counter < 101) {
        choice = rand() % 4;
        switch (choice) {
            case 0: 
                cout << "Testing push()" << endl;
                if (stack.push(ids[num], data[num])) {
                    cout << ids[num] << ": " << data[num] << " added to stack" << endl;
                }
                else {
                    cout << "Either information invalid or Stack is full" << endl;
                }
                //this exits random testing if the id/data has been exhausted to avoid repeats
                if (num == number_test_cases -1) counter = 100;
                num++;
                break;
            case 1:
                cout << "Testing pop()" << endl;
                if (stack.pop(ptr)) {
                    cout << (*ptr).id << ": " << (*ptr).information << " on stack" << endl;
                }
                else {
                    cout << "Stack is empty" << endl;
                }
                break;
            case 2:
                cout << "Testing peek()" << endl;
                if (stack.peek(ptr)) {
                    cout << (*ptr).id << ": " << (*ptr).information << " on stack" << endl;
                }
                else {
                    cout << "Stack is empty" << endl;
                }
                break;
            case 3:
                cout << "Testing isEmpty()" << endl;
                if (stack.isEmpty()) {
                    cout << "Stack is empty" << endl;
                }
                else {
                    cout << "Stack is not empty" << endl;
                }
                break;
        }
        counter++;
    }
    cout << "\nTesting complete" << endl;
    return 0;
}