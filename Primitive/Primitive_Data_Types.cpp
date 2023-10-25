#include <iostream>  // Include the input/output stream library for console output
#define endl '\n'
using namespace std;

int main() {

    // Represents integer values
    int MyInteger = 42;

    // Represents single-precision floating-point numbers
    float MyFloat = 3.14;

    // Represents double-precision floating-point numbers
    double MyDouble = 3.14159265359;

    // Represents a single character
    char MyChar = 'A';

    // Represents boolean values
    bool IsTrue = true;
    bool IsFalse = false;

    // Represents a short integer
    short MyShort = 32767;

    // Represents a long integer
    long MyLong = 1234567890;

    //  Represents a long long integer
    long long MyLongLong = 123456789012345;

    // Represents unsigned integers
    unsigned int MyUnsignedInt = 42;
    // "unsigned" means this variable can only store non-negative values, i.e., zero and positive integers

    // Represents unsigned characters
    unsigned char MyUnsignedChar = 'A';
    // "unsigned" implies this variable can only store characters with non-negative ASCII values

    // Output the values of these variables using cout (console output)
    cout << "MyInteger: " << MyInteger << endl;
    cout << "MyFloat: " << MyFloat << endl;
    cout << "MyDouble: " << MyDouble << endl;
    cout << "MyChar: " << MyChar << endl;
    cout << boolalpha; // Enables printing boolean values as true or false not 1 or 0
    cout << "IsTrue: " << IsTrue << endl;
    cout << "IsFalse: " << IsFalse << endl;
    cout << "MyShort: " << MyShort << endl;
    cout << "MyLong: " << MyLong << endl;
    cout << "MyLongLong: " << MyLongLong << endl;
    cout << "MyUnsignedInt: " << MyUnsignedInt << endl;
    cout << "MyUnsignedChar: " << MyUnsignedChar << endl;

    return 0; // Indicate successful execution of the program
}