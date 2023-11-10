#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "Child.h"
////////////////////////////////////////////////////////////////////////
//
//   Function Name: readDatafile
//   Description:    Reads data from a file and stores it in the array of Child objects.
//   Parameters:     clist - an array of Child objects (output)
//                   arraysize - size of the clist array (input)
//   Return Value:   Number of children read from the file (int)
//
////////////////////////////////////////////////////////////////////////
int readDatafile(Child clist[], int arraysize) {
    string filename;
    cout << "Enter the data file name: ";
    cin >> filename;

    ifstream inputFile(filename);
    int numC = 0;

    if (inputFile.is_open()) {
        while (numC < arraysize && inputFile >> clist[numC]) {
            numC++;
        }
        inputFile.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return numC;
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: outputList
//   Description:    Outputs the list of Child objects.
//   Parameters:     clist - an array of Child objects (input)
//                   numC - number of children in the array (input)
//   Return Value:   None
//
////////////////////////////////////////////////////////////////////////
void outputList(Child clist[], int numC) {
    for (int i = 0; i < numC; ++i) {
        cout << clist[i] << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: sortAscend
//   Description:    Sorts the array of Child objects in ascending order based on names.
//   Parameters:     clist - an array of Child objects (input/output)
//                   numC - number of children in the array (input)
//   Return Value:   None
//
////////////////////////////////////////////////////////////////////////
void sortAscend(Child clist[], int numC) {
    sort(clist, clist + numC, [](const Child& a, const Child& b) {
        return a.getName() < b.getName();
    });
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: sortDescend
//   Description:    Sorts the array of Child objects in descending order based on total savings.
//   Parameters:     clist - an array of Child objects (input/output)
//                   numC - number of children in the array (input)
//   Return Value:   None
//
////////////////////////////////////////////////////////////////////////
void sortDescend(Child clist[], int numC) {
    sort(clist, clist + numC, greater<Child>());
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: main
//   Description:    The entry point of the program. Reads data, performs operations, and displays results.   
//   Parameters:     None
//   Return Value:   Program exit status (int)
//
////////////////////////////////////////////////////////////////////////
int main() {
    const int arraysize = 10;
    Child clist[arraysize];
    int numC = readDatafile(clist, arraysize);

    cout << endl << "File Data:" << endl;
    cout << "----------" << endl;
    outputList(clist, numC);

    cout << endl << "Sorted Alphabetically:" << endl;
    cout << "----------------------" << endl;
    sortAscend(clist, numC);
    outputList(clist, numC);

    cout << endl << "Sorted by Total:" << endl;
    cout << "----------------" << endl;
    sortDescend(clist, numC);
    outputList(clist, numC);

    cout << "Pre-increment test:" << endl;
    cout << "-------------------" << endl;
    cout << clist[0] << endl;

    // Make a copy of clist[0] and increment the quarters of the copy
    Child copy = clist[0];
    ++copy;

    // Output the modified copy separately
    cout << copy;

    return 0;
}
