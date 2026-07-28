#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double modulusOp(double a, double b) {
    return fmod(a, b);
}

double exponent(double a, double b) {
    return pow(a, b);
}

void showMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    cout << fixed << setprecision(2);

    while (true) {
        showMenu();
        int choice;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Error: Invalid choice. Please enter 1-7." << endl;
            continue;
        }

        double num1, num2;
        cout << "Enter first number : ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        if ((choice == 4 || choice == 5) && num2 == 0) {
            cout << "Error: Cannot divide by zero." << endl;
            continue;
        }

        double result;
        string symbol;

        switch (choice) {
            case 1: result = add(num1, num2); symbol = "+"; break;
            case 2: result = subtract(num1, num2); symbol = "-"; break;
            case 3: result = multiply(num1, num2); symbol = "*"; break;
            case 4: result = divide(num1, num2); symbol = "/"; break;
            case 5: result = modulusOp(num1, num2); symbol = "%"; break;
            case 6: result = exponent(num1, num2); symbol = "^"; break;
        }

        cout << "Result: " << num1 << " " << symbol << " " << num2 << " = " << result << endl;
    }

    return 0;
}