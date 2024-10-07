#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
int linearSearch(const int arr[], int size, int target);
int binarySearch(const int arr[], int size, int target);
int jumpSearch(const int arr[], int size, int target);
void displayRollNumbers(const int arr[], int size);
void generateRandomRollNumbers(int arr[], int size);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numStudents;
    int* rollNumbers = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input roll numbers from the user\n";
        cout << "2. Generate random roll numbers\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Jump Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of students: ";
                cin >> numStudents;
                rollNumbers = new int[numStudents];
                cout << "Enter the roll numbers of students:\n";
                for (int i = 0; i < numStudents; ++i) {
                    cout << "Student " << i + 1 << ": ";
                    cin >> rollNumbers[i];
                }
                break;
            case 2:
                if (rollNumbers != nullptr) {
                    generateRandomRollNumbers(rollNumbers, numStudents);
                    cout << "Random roll numbers generated.\n";
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 3:
                if (rollNumbers != nullptr) {
                    int target;
                    cout << "Enter the roll number to search: ";
                    cin >> target;
                    int result = linearSearch(rollNumbers, numStudents, target);
                    if (result != -1) {
                        cout << "Roll number " << target << " found at index " << result << ".\n";
                    } else {
                        cout << "Roll number " << target << " not found.\n";
                    }
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 4:
                if (rollNumbers != nullptr) {
                    // Binary search requires the array to be sorted
                    sort(rollNumbers, rollNumbers + numStudents);
                    int target;
                    cout << "Enter the roll number to search: ";
                    cin >> target;
                    int result = binarySearch(rollNumbers, numStudents, target);
                    if (result != -1) {
                        cout << "Roll number " << target << " found at index " << result << ".\n";
                    } else {
                        cout << "Roll number " << target << " not found.\n";
                    }
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 5:
                if (rollNumbers != nullptr) {
                    // Jump search requires the array to be sorted
                    sort(rollNumbers, rollNumbers + numStudents);
                    int target;
                    cout << "Enter the roll number to search: ";
                    cin >> target;
                    int result = jumpSearch(rollNumbers, numStudents, target);
                    if (result != -1) {
                        cout << "Roll number " << target << " found at index " << result << ".\n";
                    } else {
                        cout << "Roll number " << target << " not found.\n";
                    }
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 0:
                cout << "Exiting program.\n";
                if (rollNumbers != nullptr) {
                    delete[] rollNumbers;
                }
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}

void displayRollNumbers(const int arr[], int size) {
    cout << "Roll Numbers:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateRandomRollNumbers(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000 + 1; // Random roll number between 1 and 1000
    }
}

int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int jumpSearch(const int arr[], int size, int target) {
    int jump = static_cast<int>(sqrt(size));
    int left = 0;
    int right = 0;

    while (right < size && arr[right] < target) {
        left = right;
        right += jump;
    }

    for (int i = left; i < min(right, size); ++i) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }

    return -1; // Target not found
}
