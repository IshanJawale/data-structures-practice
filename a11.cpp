#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void selectionSort(float* arr, int size);
void bubbleSort(float* arr, int size);
void insertionSort(float* arr, int size);
void shellSort(float* arr, int size);
void quickSort(float* arr, int low, int high);
int partition(float* arr, int low, int high);
void radixSort(float* arr, int size);
int getMax(float* arr, int size);
void countSort(float* arr, int size, int exp);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numStudents;
    float* scores = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input scores from the user\n";
        cout << "2. Generate random scores\n";
        cout << "3. Selection Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Insertion Sort\n";
        cout << "6. Shell Sort\n";
        cout << "7. Quick Sort\n";
        cout << "8. Radix Sort\n";
        cout << "9. Display top five scores\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of students: ";
                cin >> numStudents;
                scores = new float[numStudents];
                cout << "Enter the percentage of marks for each student:\n";
                for (int i = 0; i < numStudents; ++i) {
                    cout << "Student " << i + 1 << ": ";
                    cin >> scores[i];
                }
                break;
            case 2:
                if (scores != nullptr) {
                    for (int i = 0; i < numStudents; ++i) {
                        scores[i] = static_cast<float>(rand() % 101);
                    }
                    cout << "Random scores generated.\n";
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 3:
                if (scores != nullptr) {
                    selectionSort(scores, numStudents);
                    displayScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 4:
                if (scores != nullptr) {
                    bubbleSort(scores, numStudents);
                    displayScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 5:
                if (scores != nullptr) {
                    insertionSort(scores, numStudents);
                    displayScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 6:
                if (scores != nullptr) {
                    shellSort(scores, numStudents);
                    displayScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 7:
                if (scores != nullptr) {
                    quickSort(scores, 0, numStudents - 1);
                    displayScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 8:
                if (scores != nullptr) {
                    radixSort(scores, numStudents);
                    displayScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 9:
                if (scores != nullptr) {
                    displayTopFiveScores(scores, numStudents);
                } else {
                    cout << "Please enter the number of students first.\n";
                }
                break;
            case 0:
                cout << "Exiting program.\n";
                if (scores != nullptr) {
                    delete[] scores;
                }
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}

void displayScores(float* arr, int size) {
    cout << "Sorted Scores:\n";
    for (int i = 0; i < size; ++i) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(float* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(float* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(float* arr, int size) {
    for (int i = 1; i < size; ++i) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void shellSort(float* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            float temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

void quickSort(float* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(float* arr, int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void countSort(float* arr, int size, int exp) {
    const int radix = 10;
    float output[size];

    int count[radix] = {0};

    for (int i = 0; i < size; ++i) {
        count[static_cast<int>(arr[i] / exp) % radix]++;
    }

    for (int i = 1; i < radix; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        output[count[static_cast<int>(arr[i] / exp) % radix] - 1] = arr[i];
        count[static_cast<int>(arr[i] / exp) % radix]--;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(float* arr, int size) {
    float max = arr[getMax(arr, size)];

    for (int exp = 1; static_cast<int>(max / exp) > 0; exp *= 10) {
        countSort(arr, size, exp);
    }
}

int getMax(float* arr, int size) {
    float max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return static_cast<int>(max);
}

void displayTopFiveScores(float* arr, int size) {
    int n = min(5, size);
    cout << "Top Five Scores:\n";
    for (int i = size - 1; i >= size - n; --i) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;
}
