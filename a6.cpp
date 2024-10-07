/*
Linked list operations: Create a linked list of names and birthdays of  students. Write a menu driven C++ program to perform following operations:
1. Insert name and birthday of new student
2. Delete a student entry
3. Display a happy birthday message for whom today (based on system date) is birthday
4. Display list of students with their birthdays

Name: Ishan Jawale
Roll no: 28
Div: A
Class: S.Y.Btech
Branch: Computer Engineering
Course: Data Structures Lab
*/


#include <iostream>
#include <ctime>

using namespace std;

// Structure to store student information
struct Student {
    string name;
    string birthday;
    Student* next;
};

// Function to display a happy birthday message for students with today's birthday
void displayBirthdayWishes(Student* head) {
    time_t now = time(0);
    struct tm* today = localtime(&now);
    int currentDay = today->tm_mday;
    int currentMonth = today->tm_mon + 1;

    Student* current = head;
    while (current != nullptr) {
        int studentDay = stoi(current->birthday.substr(0, 2));
        int studentMonth = stoi(current->birthday.substr(3, 2));

        if (currentDay == studentDay && currentMonth == studentMonth) {
            cout << "Happy Birthday, " << current->name << "!" << endl;
        }

        current = current->next;
    }
}

// Function to insert a new student into the linked list
void insertStudent(Student*& head, string name, string birthday) {
    Student* newStudent = new Student;
    newStudent->name = name;
    newStudent->birthday = birthday;
    newStudent->next = head;
    head = newStudent;
    cout << "Student added successfully." << endl;
}
// Function to display the list of students with their birthdays
void displayStudentList(Student* head) {
    Student* current = head;
    if (current == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "List of students and their birthdays:" << endl;
    while (current != nullptr) {
        cout << current->name << ": " << current->birthday << endl;
        current = current->next;
    }
}


// Function to delete a student entry
void deleteStudent(Student*& head, string name) {
    Student* current = head;
    Student* prev = nullptr;

    while (current != nullptr) {
        if (current->name == name) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Student deleted successfully." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Student not found." << endl;
}

int main() {
    Student* head = nullptr;
    int choice;
    string name, birthday;
    do {
	try {
        cout << "\nMenu:\n";
        cout << "1. Insert new student\n";
        cout << "2. Delete a student entry\n";
        cout << "3. Display birthday wishes for today\n";
        cout << "4. Display list of students with birthdays\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
		if(!cin) {
			throw runtime_error("Invalid Input");
		}
        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student birthday (DD/MM): ";
                cin >> birthday;
                insertStudent(head, name, birthday);
                break;
            case 2:
                cout << "Enter student name to delete: ";
                cin >> name;
                deleteStudent(head, name);
                break;
            case 3:
                displayBirthdayWishes(head);
                break;
            case 4:
                displayStudentList(head);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
	} catch(const runtime_error& e) {
		cout << "Exception caught\n" << e.what() << endl;
		cin.clear();
		cin.ignore();
	}
    } while (choice != 5);
    // Free allocated memory
    Student* current = head;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}