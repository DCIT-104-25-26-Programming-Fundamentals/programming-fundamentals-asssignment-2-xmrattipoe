// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
//

#include <iostream>
using namespace std;

void printFirstNTerms() {
    int n;
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i != n - 1) {
            cout << " ";
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacciNumber(long long number) {
    if (number < 0) {
        return false;
    }

    long long a = 0, b = 1;
    while (a <= number) {
        if (a == number) {
            return true;
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    return false;
}

void checkNumber() {
    long long number;
    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacciNumber(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    printFirstNTerms();
    cout << endl;
    checkNumber();
    return 0;
}