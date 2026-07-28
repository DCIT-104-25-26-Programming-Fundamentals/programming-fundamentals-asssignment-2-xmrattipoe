// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// Topic: Conditional Logic (if / elif / else) and Functions
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//

#include <iostream>
using namespace std;

char getGrade(int score) {
    // Validate the score is within range
    if (score < 0 || score > 100) {
        return '\0';
    }

    // Determine the letter grade
    if (score >= 80) {
        return 'A';
    } else if (score >= 70) {
        return 'B';
    } else if (score >= 60) {
        return 'C';
    } else if (score >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int score;
    cout << "Enter student score (0-100): ";
    cin >> score;

    char grade = getGrade(score);

    if (grade == '\0') {
        cout << "Error: Score must be between 0 and 100." << endl;
    } else {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}