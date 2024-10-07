#include<iostream>
//#include<cstdlib>
//#include<ctime>
using namespace std;

// Node structure for appointment
struct Node {
    string name;
    int start;
    int end;
    bool booked;
    Node* next;
    Node* prev;

    Node() : name("NULL"), start(0), end(0), next(nullptr), booked(false) {}
    Node(string n, int s, int e, bool book) {
        this->name = n;
        this->start = s;
        this->end = e;
        this->booked = book;
    }
};

Node* head = NULL;

bool isNotBooked() {
    Node* current = head;
    if(current->name == "") {
        return true;
    }
    else
        return false;
}

// Function to display free slots
void displayFreeSlots() {
    Node* current = head;
    cout << "Free Slots:\n";
    current->start = 900, current->end = 1000;
    while (current!=NULL && current->end!=1900) {
        if (!current->booked) {
            cout << "Start Time: " << current->start; // << ", End Time: " << current->end << endl;
        }
        if(current->next!=NULL){
            cout << ", End Time: " << current->next->end << endl;
        }
        current->start += 100;
        current->end +=100;
        current = current->next;
    }
    current->next = NULL;
    head = current;
    cout << endl;
}

// Function to book an appointment
void bookAppointment(int newStart, int newEnd, string newData) {
    Node *current = head;
    while(current->next!=NULL){
        if(current->start == newStart) { 
            current->name = newData;
            current->booked = true;
            current->prev = NULL;
            current->next = head;
        }
    }
    if (head != NULL)
        head->prev = current;
    current->next=head;
}

// Function to cancel an appointment
void cancelAppointment(string name, int startTime, int endTime) {
    Node* current = head;
    while (current != nullptr) {
        if (current->start == startTime && current->end == endTime && current->name == name && current->booked == true) {
            current->name = "";
            current->booked = false;
            cout << "Appointment canceled successfully.\n";
            return;
        }
        current = current->next;
    }
    cout << "Invalid appointment details or appointment not found.\n";
}

// Function to sort the list based on time
void sortList() {
    if (head == nullptr || head->next == nullptr) {
        cout << "List is already sorted or empty.\n";
        return;
    }

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        Node* innerCurrent = current->next;
        while (innerCurrent != nullptr) {
            if (current->start > innerCurrent->start) {
                // Swap nodes
                temp = new Node(current->name, current->start, current->end, current->booked);
                current->name = innerCurrent->name;
                current->start = innerCurrent->start;
                current->end = innerCurrent->end;
                innerCurrent->name = temp->name;
                innerCurrent->start = temp->start;
                innerCurrent->end = temp->end;
            }
            innerCurrent = innerCurrent->next;
        }
        current = current->next;
    }

    cout << "List sorted successfully based on time.\n";
}

// Function to display the linked list
void displayList() {
    Node* current = head;
    cout << "Appointments:\n";
    while (current!=NULL && current->end!=1900) {
        if(current->booked) {
            cout << "Name: " << current->name << ", Start Time: " << current->start << ", End Time: " << current->end << endl;
            current = current->next;
        }
    }
    cout << endl;
}

int main() {
    // Initialize time slots
    for (int i = 9; i < 19; ++i) {
        head = new Node("", i * 100, (i + 1) * 100, false);
        head->next = head;
    }

    //srand(time(0));  // Seed for random appointment booking

    int choice;
    do {
        cout << "Menu:\n1. Display Free Slots\n2. Book Appointment\n3. Cancel Appointment\n4. Sort List\n5. Display Appointments\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFreeSlots();
                break;

            case 2:
                {
                    string name;
                    int startTime, endTime;
                    cout << "Enter your name: ";
                    cin >> name;
                    cout << "Enter start time (in 24-hour format): ";
                    cin >> startTime;
                    cout << "Enter end time (in 24-hour format): ";
                    cin >> endTime;
                    bookAppointment(startTime, endTime, name);
                }
                break;

            case 3:
                {
                    string name;
                    int startTime, endTime;
                    cout << "Enter your name: ";
                    cin >> name;
                    cout << "Enter start time (in 24-hour format): ";
                    cin >> startTime;
                    cout << "Enter end time (in 24-hour format): ";
                    cin >> endTime;
                    cancelAppointment(name, startTime, endTime);
                }
                break;

            case 4:
                sortList();
                break;

            case 5:
                displayList();
                break;

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
