#include <iostream>
#include <iomanip>
using namespace std;

#include "Child.h"

////////////////////////////////////////////////////////////////////////
//
//   Function Name: Child (constructor)
//   Description:    Initializes a Child object with the given parameters.
//   Parameters:     na - name of the child (input)
//                   q - number of quarters (input)
//                   d - number of dimes (input)
//                   n - number of nickels (input)
//                   p - number of pennies (input)
//   Return Value:   None
//
////////////////////////////////////////////////////////////////////////
Child::Child(string na, int q, int d, int n, int p) {
    name = na;
    quarters = q;
    dimes = d;
    nickels = n;
    pennies = p;
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: operator>> (stream input)
//   Description:    Overloaded input stream operator to read data into a Child object.
//   Parameters:     input - input stream object (input)
//                   s - Child object to store the read data (output)
//   Return Value:   input stream object (istream&)
//
////////////////////////////////////////////////////////////////////////
istream &operator>>(istream &input, Child &s) {
    string name;
    int quarters, dimes, nickels, pennies;
    input >> name >> quarters >> dimes >> nickels >> pennies;
    s.setName(name);
    s.setQuarters(quarters);
    s.setDimes(dimes);
    s.setNickels(nickels);
    s.setPennies(pennies);
    return input;
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: getTotal
//   Description:    Computes the total cash value of the child's holdings.
//   Parameters:     None
//   Return Value:   Total cash value (float)
//
////////////////////////////////////////////////////////////////////////
float Child::getTotal() const {
    return static_cast<float>(quarters * 25 + dimes * 10 + nickels * 5 + pennies) / 100.0;
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: getAward
//   Description:    Determines the child's stars award based on total savings.
//   Parameters:     None
//   Return Value:   Stars award representation (string)
//
////////////////////////////////////////////////////////////////////////
string Child::getAward() const {
    float total = getTotal();
    if (total >= 10.0) {
        return "***";
    } else if (total >= 7.5) {
        return "**";
    } else if (total >= 5.0) {
        return "*";
    } else {
        return "";
    }
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: operator> (greater than)
//   Description:    Overloaded comparison operator for Child objects.
//                   Compares based on the total cash value.
//   Parameters:     rhs - Child object to compare with (input)
//   Return Value:   Boolean indicating if the current object is greater (bool)
//
////////////////////////////////////////////////////////////////////////
bool Child::operator>(const Child &rhs) const {
    return getTotal() > rhs.getTotal();
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: operator< (less than)
//   Description:    Overloaded comparison operator for Child objects.
//                   Compares based on the child names (alphabetical order).
//   Parameters:     rhs - Child object to compare with (input)
//   Return Value:   Boolean indicating if the current object is smaller (bool)
//
////////////////////////////////////////////////////////////////////////
bool Child::operator<(const Child &rhs) const {
    return name < rhs.name;
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: operator++ (pre-increment)
//   Description:    Pre-increment operator to increment the number of quarters.
//   Parameters:     None
//   Return Value:   Reference to the updated Child object (Child&)
//
////////////////////////////////////////////////////////////////////////
Child &Child::operator++() {
    ++quarters;
    return *this;
}

////////////////////////////////////////////////////////////////////////
//
//   Function Name: operator<< (stream output)
//   Description:    Overloaded output stream operator to display Child object information.
//   Parameters:     output - output stream object (output)
//                   s - Child object to display (input)
//   Return Value:   output stream object (ostream&)
//
////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& output, const Child& s) {
    int nameWidth = 10;  // Width for the name column
    int numWidth = 3;    // Width for the number columns
    int totalWidth = 5;  // Width for the total column, excluding decimal places
    int decimalWidth = 2; // Width for decimal places

    output << setw(nameWidth) << left << s.getName()
           << setw(numWidth) << right << s.getQuarters()
           << setw(numWidth) << s.getDimes()
           << setw(numWidth) << s.getNickels()
           << setw(numWidth) << s.getPennies()
           << setw(totalWidth) << fixed << setprecision(decimalWidth) << s.getTotal()
           << setw(6) << s.getAward();

    return output;
}
