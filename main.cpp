#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class node {
public:
    int id;
    int startTime, endTime;
    string name;
    bool isBooked;
    node *next;

    node() {
        next = NULL;
    }

    node(int id, string name, int startTime, int endTime, bool isBooked) {
        this->id = id;
        this->name = name;
        this->startTime = startTime;
        this->endTime = endTime;
    }
};

class LinkedList {
    node *head;
public:
    LinkedList() {
        head = NULL;
    }

    void insert(int id, int startTime, int endTime, bool isBooked = false, string name = "NULL") {
        node *newNode = new node(id, name, startTime, endTime, isBooked);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        auto temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int id) {
        int index = findPatientByID(id);
        if (index == -1) {
            cout << "Patient Not Found!" << endl;
            return;
        }
        auto temp = head;
        auto del = new node();
        if (index == 0) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = del->next;
        delete del;
    }

    int updateNode(int id, string name, bool add = true) {
        int index = findPatientByID(id);
        if (index == -1) {
            cout << "Slot Not Found!" << endl;
            return -1;
        }
        auto temp = head;
        if (index == 0) {
            if (add) {
                head->name = name;
                head->isBooked = true;
            } else {
                head->name = "NULL";
                head->isBooked = false;
            }
            return 1;
        }
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        if (add) {
            temp->name = name;
            temp->isBooked = true;
        } else {
            temp->name = "NULL";
            temp->isBooked = false;
        }
        return 1;
    }

    int findPatientByID(int id) {
        int index = 0;
        auto temp = head;
        while (temp != NULL) {
            if (temp->id == id) return index;
            index++;
            temp = temp->next;
        }
        return -1;
    }

    void displayNode(int id) {
        int index = findPatientByID(id);
        if (index == -1) {
            cout << "Patient Not Found!" << endl;
            return;
        }
        auto *temp = head;
        cout << left << setw(4) << "Id" << setw(15) << "Name" << setw(12) << "Start Time" << setw(12) << "End Time"
             << setw(16) << "Available" << endl;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        cout << left << setw(4) << temp->id;
        cout << left << setw(15) << temp->name;
        cout << left << setw(12) << temp->startTime;
        cout << left << setw(12) << temp->endTime;
        cout << left << setw(12) << (!temp->isBooked ? "Yes" : "No") << endl;
        cout << endl;
    }

    void displayList() {
        auto *temp = head;
        cout << left << setw(4) << "Id" << setw(15) << "Name" << setw(12) << "Start Time" << setw(12) << "End Time"
             << setw(20) << "Available" << endl;
        while (temp != NULL) {
            cout << left << setw(4) << temp->id;
            cout << left << setw(15) << temp->name;
            cout << left << setw(12) << temp->startTime;
            cout << left << setw(12) << temp->endTime;
            cout << left << setw(12) << (!temp->isBooked ? "Yes" : "No");
            cout << endl;
            temp = temp->next;
        }
    }

    void displaySlots(bool isBooked = false) {
        auto *temp = head;
        cout << (isBooked ? "Booked Slots" : "Free Slots") << endl;
        cout << left << setw(12) << "Slot No.";
        if (isBooked)cout << left << setw(12) << "Name";
        cout << left << setw(12) << "Start Time";
        cout << left << setw(11) << "End Time";
        cout << left << setw(16) << "Available" << endl;
        while (temp != NULL) {
            if (temp->isBooked == isBooked) {
                cout << left << setw(12) << temp->id;
                if (isBooked)cout << left << setw(12) << temp->name;
                cout << left << setw(12) << temp->startTime;
                cout << left << setw(12) << temp->endTime;
                cout << left << setw(12) << (!temp->isBooked ? "Yes" : "No");
                cout << endl;
            }
            temp = temp->next;
        }
        cout << endl;
    }

    bool isBooked(int id) {
        int index = findPatientByID(id);
        if (index == -1) return false;
        if (index == 0) {
            return head->isBooked;
        }
        auto temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->isBooked;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

class Appointment {
    LinkedList list;
    int startTime = 0, endTime = 0, slotDur = 0, slotID = 1;

public:
    Appointment() {}

    void setSlots() {
        string sTime, eTime;
        cout << "Slot Creation: " << endl;
        cout << "Enter the Opening time of the hospital 24Hour Format Eg. For 09:30, 18:00): ";
        cin >> sTime;
        cout << "Enter the Closing time of the hospital 24Hour Format Eg. For 09:30, 18:00): ";
        cin >> eTime;
        startTime = formatTime(sTime);
        endTime = formatTime(eTime);
        while (1) {
            cout << "Enter duration of each slot in Hours:";
            cin >> slotDur;
            slotDur *= 100;
            if (endTime - startTime < slotDur || slotDur <= 0) {
                cout << "Invalid Timt Duration" << endl;
                continue;
            } else {
                break;
            }
        }
        slotID = 1;
        for (int i = startTime; i + slotDur <= endTime; i += slotDur) {
            list.insert(slotID++, i, i + slotDur, false);
        }
    }

    void bookAppointment() {
        cout << endl << "BOOK APPOINTMENT" << endl;
        list.displaySlots();
        int sId;

        cout << "Select the Slot Id: ";
        cin >> sId;
        if (sId > 0 && !list.isBooked(sId)) {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            if (list.updateNode(sId, name) == -1) {
                return;
            }
            cout << "BOOKED SUCCESSFULLY" << endl;
            list.displayNode(sId);
        } else {
            cout << "Invalid Slot!" << endl;
            cout<<endl;
            return;
        }

    }

    void cancelAppointment() {
        cout << endl << "CANCEL APPOINTMENT" << endl;
        list.displaySlots(true);
        int sId;

        cout << "Select the Slot Id: ";
        cin >> sId;
        if (list.isBooked(sId)) {
            if (list.updateNode(sId, "", false) == -1) {
                return;
            }
            cout << "SLOT CANCELLED SUCCESSFULLY" << endl;
        } else {
            cout << "Invalid Slot!" << endl;
            cout<<endl;
            return;
        }

    }

    int formatTime(string time) {
        int intTime = 0;
        stringstream ss(time);
        getline(ss, time, ':');
        intTime = stoi(time) * 100;
        getline(ss, time, '\0');
        intTime += stoi(time);
        ss.clear();
        return intTime;
    }

    void displaySlots(bool isBooked = false) {
        list.displaySlots(isBooked);
    }

};

int main() {
    Appointment a;
    cout << "Appointment Management: " << endl;
    a.setSlots();
    int op;
    cout << endl;
    while (op != 9) {
        cout << "1. Book Appointment" << endl;
        cout << "2. Cancel Appointment" << endl;
        cout << "3. View Free Slots" << endl;
        cout << "4. View Booked Slots" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter Option: ";
        cin >> op;
        switch (op) {
            case 1: {
                a.bookAppointment();
            }
                break;
            case 2: {
                a.cancelAppointment();
            }
                break;
            case 3: {
                a.displaySlots();
            }
                break;
            case 4: {
                a.displaySlots(true);
            }
                break;
            case 9: {
                cout << "Invalid Option" << endl;
            }
        }
    }
    return 0;
}
