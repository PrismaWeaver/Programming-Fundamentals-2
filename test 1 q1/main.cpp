/*********************
Name: Twee Shackelford
Test 1
Purpose: create Hash table with array of heads
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here

    Hashtable hashtable;

    // show it is empty by calling getCount and printTable

    cout << "There are " << hashtable.count() << " entries" << endl;
    hashtable.displayTable();
    cout << endl;

    // try and put ALL the data into the table and show what happens

    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.addEntry(ids[i], strs[i])) {
            cout << "success. inserted: " << ids[i] << endl;
            cout << "There are " << hashtable.count() << " entries in the table." << endl;
        }
        else {
            cout << ids[i] << " failed." << endl;
        }
    }

    cout << endl;
    hashtable.displayTable(); //showing all valid data has been entered
    cout << endl;

    string temp;
    cout << "Searching for Test Data one at a time..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        temp = hashtable.getEntry(ids[i]);
        if (temp != "") {
            cout << "success: " << ids[i] << ": " << temp << endl;
        }
        else {
            cout << "failed: " << ids[i] << " is not in the table." << endl;
        }
    }

    cout << endl;

    cout << "Deleting Test Data..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.removeEntry(ids[i])) {
            cout << "success. entry deleted." << endl;
            cout << "There are " << hashtable.count() << " entries in the table." << endl;
        }
        else {
            cout << "failed." << endl;
        }
    }

    cout << endl;
    hashtable.displayTable(); //showing all data has been removed
    cout << endl;

    // continue using and testing your table, add and remove data,
    // make more test data if you need to.
    
    cout << "Beginning random tests" << endl;
    int choice, randTest;
    int counter = 0;
    while (counter < 101) {
        choice = rand() % 3;
        randTest = rand() % testdatasize;
        switch (choice) {
        case 0:
            cout << "Testing addEntry() with id: " << ids[randTest] << endl;
            if (hashtable.addEntry(ids[randTest], strs[randTest])) cout << "Success, count: " << hashtable.count() << endl;
            else cout << "Failed" << endl;
            hashtable.displayTable();
            break;
        case 1:
            cout << "Testing getEntry() with id: " << ids[randTest] << endl;
            if (hashtable.getEntry(ids[randTest]) != "") cout << "Success, data: " << hashtable.getEntry(ids[randTest]) << " count: " << hashtable.count() << endl;
            else cout << "Failed" << endl;
            break;
        case 2:
            cout << "Testing removeEntry() with id: " << ids[randTest] << endl;
            if (hashtable.removeEntry(ids[randTest])) cout << "Success, count: " << hashtable.count() << endl;
            else cout << "Failed" << endl;
            hashtable.displayTable();
            break;
        }
        cout << endl;
        counter++;
    }
    cout << endl;
    cout << "Testing complete" << endl;
    cout << endl;    
    
    return 0;
}
