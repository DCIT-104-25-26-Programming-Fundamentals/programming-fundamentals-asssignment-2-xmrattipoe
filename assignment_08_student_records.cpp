#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    double total = 0;
    for (double s : scores) {
        total += s;
    }
    return total / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cin.ignore();
    cout << "Student name: ";
    getline(cin, s.name);
    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << string(50, '-') << endl;
    cout << left << setw(15) << "Name" << setw(12) << "ID" << setw(20) << "Scores" << "Average" << endl;
    cout << string(50, '-') << endl;

    for (const Student& s : students) {
        string scoresStr = "";
        for (int i = 0; i < s.scores.size(); i++) {
            scoresStr += to_string((int)s.scores[i]);
            if (i < s.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        cout << left << setw(15) << s.name << setw(12) << s.id << setw(20) << scoresStr << calculateAverage(s.scores) << endl;
    }
    cout << string(50, '-') << endl;
}

void calculateStudentAverage(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << calculateAverage(s.scores) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

void showMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;

    while (true) {
        showMenu();
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            calculateStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Invalid choice. Please enter 1-4." << endl;
        }
    }

    return 0;
}