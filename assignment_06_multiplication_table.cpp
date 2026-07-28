// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line between each table.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If invalid, print an error and stop.
//

#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << setw(2) << i << " = " << (number * i) << endl;
    }
}

void printTablesUpToN(int n) {
    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return 0;
    }

    printTable(number);

    cout << endl;

    int n;
    cout << "Enter N for tables 1 to N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    printTablesUpToN(n);

    return 0;
}
