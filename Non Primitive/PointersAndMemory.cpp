#include <iostream> // For input and output operations
#include <memory> // For smart pointers
using namespace std;

int main () {

    // Simple pointer //
    // Not a dynamically allocated
    // It is a stack-allocated variable. This means that it is automatically managed by the system when it goes out of scope
    double GPA = 3.19;
    double *Ptr = &GPA; // Declare a pointer to a double and assign the address of GPA
    cout << "Address: " << Ptr << endl; // Output the memory address of GPA
    cout << "Value: " << *Ptr << endl;  // Output the value pointed to by Ptr
    cout << "------------------------------------\n";

    const int size = 6;
    int Numbers[size] = {2, 3, 5, 7, 11, 13}; // Create an array of integers
    int *Start = Numbers; // Declare a pointer to an integer and assign the address of the first element in Numbers
    cout << "The elements are: ";
    for (int i=0;i<size;++i) {
        cout << *(Numbers+i) << ' '; // Output the elements of the array using pointer arithmetic
    }
    cout << endl;
    cout << "------------------------------------\n";


    // Pointer of pointer //
    // Dynamically allocated an integer
    // This variable is allocated on the heap and requires manual deallocation using 'delete' to prevent memory leaks
    int *First = new int;
    *First = 2023;
    int **Second = &First;
    cout << "Value in First: " << *First << endl;
    cout << "Value in Second: " << **Second << endl;

    // Deallocate dynamically allocated memory when it is no longer needed
    delete First;
    // delete Second; // Do not delete the Second because it is automatically managed (it is a stack-allocated)
    cout << "------------------------------------\n";


    // Smart pointer //

    // A shared_ptr to an integer
    shared_ptr<int>Age = make_shared<int>(21);
    cout << "Value: " << *Age << endl;
    cout << "Address: " << Age.get() << endl;

    // Note: Age goes out of scope, and the memory is automatically deallocated
    cout << "------------------------------------\n";

    return 0;
}