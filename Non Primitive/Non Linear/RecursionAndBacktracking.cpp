#include <iostream>
#include <utility> // for pair
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

// Print some numbers in ascending order
// Takes a default parameter counter = 1
void Print(int counter = 1) {
    // Base
    if (counter>10) return;

    cout << counter << ' ';
    Print(counter+1);
}

// Print some numbers in descending order
void Print_Reversed(int counter = 1) {
    // Base
    if (counter>10) return;

    Print_Reversed(counter+1);
    cout << counter << ' ';
}

// Calculate the summation from 1 to a specific number
int Summation(int number, int counter = 1, int sum = 0) {
    // Base
    if (counter>number) {
        return sum;
    }
    sum += counter;
    return Summation(number, counter+1, sum);
}

// Calculate the factorial of a number
int Factorial(int number) {
    // Base-case
    if (number<=1) return 1;

    return number * Factorial(number-1);
}

// Calculate the number of ways to reach the 'End' value starting from 'Start' step by 1 and step by 2
int From_Until(int Start, int End) {
    // Base-cases
    if (Start==End) return 1;
    if (Start>End) return 0;

    int One = From_Until(Start+1, End);
    int Two = From_Until(Start+2, End);
    return One + Two;
}

// Calculate the minimum number of steps to reach the end point
bool visited[5][5] = {};
int Find_Path(int X1, int Y1, int X2, int Y2, string Grid[5]) {
    // X,Y means i,j indicies
    // Base-Cases
    // Ensure staying within the grid, not revisiting a point, and avoiding '#'
    if (X1>4 or X1<0 or Y1>4 or Y1<0 or Grid[X1][Y1]=='#' or visited[X1][Y1]) {
        return 1e3; // A large value used for minimization on answer
    }
    if (X1==X2 and Y1==Y2) {
        return 0;
    }

    visited[X1][Y1] = true;
    // To keep track of which cells in the grid have already been visited during this path-finding process
    int up = Find_Path(X1-1, Y1, X2, Y2, Grid) + 1;
    int down = Find_Path(X1+1, Y1, X2, Y2, Grid) + 1;
    int right = Find_Path(X1, Y1+1, X2, Y2, Grid) + 1;
    int left = Find_Path(X1, Y1-1, X2, Y2, Grid) + 1;
    visited[X1][Y1] = false;
    // Allowing it to be visited again from a different path or direction

    return min({up, down, right, left});
}

int main() {

    cout << "Numbers from 1 to 10 are: ";
    Print();
    cout << endl;

    cout << "In reverse order: ";
    Print_Reversed();
    cout << endl;

    cout << "-----------------------------------------\n";

    int Sum = Summation(10);
    cout  << "The Summation is: " << Sum << endl;

    int Result =  Factorial(4);
    cout << "Factorial of 4 is: " << Result << endl;

    int Calc = From_Until(2, 6);
    cout << "Number of ways to go from 2 to 6 is: " << Calc << endl;

    cout << "-----------------------------------------\n";

    // Backtracking
    // Explore all possible solutions and find the shortest path or optimal solution
    // Open roads denoted by '.'
    string Grid[5] = {
        ".#...",
        ".#.##",
        ".#...",
        ".##..",
        "....."
    };
    pair<int,int>Starting_Point = {0, 0};
    pair<int,int>Ending_Point = {0, 4};

    int Min_Path = Find_Path(Starting_Point.first, Starting_Point.second, Ending_Point.first, Ending_Point.second, Grid);
    cout << "The minimum number of steps is: " << Min_Path << endl;
    cout << "-----------------------------------------\n";

    return 0;
}