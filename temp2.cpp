#include <iostream>
#include <iomanip>
#include <ctime>

struct Appointment {
    int hour;
    int minute;
    bool booked;
    Appointment* next;
};

class AppointmentManager {
private:
    Appointment* head;

public:
    // Constructor
    AppointmentManager() : head(nullptr) {}

    // Destructor
    ~AppointmentManager() {
        // Release memory when the program ends
        while (head != nullptr) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to display free slots
    void displayFreeSlots() {
        std::cout << "Free Slots:\n";
        Appointment* current = head;
        while (current != nullptr) {
            if (!current->booked) {
                std::cout << std::setfill('0') << std::setw(2) << current->hour << ":"
                          << std::setfill('0') << std::setw(2) << current->minute << " - ";
                if (current->next != nullptr) {
                    std::cout << std::setfill('0') << std::setw(2) << current->next->hour << ":"
                              << std::setfill('0') << std::setw(2) << current->next->minute << std::endl;
                } else {
                    std::cout << "End of the day" << std::endl;
                }
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to book an appointment
    void bookAppointment(int startHour, int startMinute, int endHour, int endMinute) {
        Appointment* current = head;
        while (current != nullptr) {
            if (!current->booked && current->hour == startHour && current->minute == startMinute) {
                // Mark the appointment as booked
                current->booked = true;

                // Check if the end time is within bounds
                while (current != nullptr && (current->hour != endHour || current->minute != endMinute)) {
                    current = current->next;

                    // Mark all appointments within the booked slot
                    if (current != nullptr) {
                        current->booked = true;
                    }
                }

                std::cout << "Appointment booked successfully.\n";
                return;
            }
            current = current->next;
        }

        std::cout << "Invalid time for booking.\n";
    }

    // Function to cancel an appointment
    void cancelAppointment(int startHour, int startMinute, int endHour, int endMinute) {
        Appointment* current = head;
        while (current != nullptr) {
            if (current->hour == startHour && current->minute == startMinute && current->booked) {
                // Mark the appointment as canceled
                current->booked = false;

                // Check if the end time is within bounds
                while (current != nullptr && (current->hour != endHour || current->minute != endMinute)) {
                    current = current->next;

                    // Mark all appointments within the canceled slot as free
                    if (current != nullptr) {
                        current->booked = false;
                    }
                }

                std::cout << "Appointment canceled successfully.\n";
                return;
            }
            current = current->next;
        }

        std::cout << "Invalid time for cancellation.\n";
    }

    // Function to sort list based on time
    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            return; // No or only one element in the list, no need to sort
        }

        Appointment* sorted = nullptr;
        Appointment* current = head;

        while (current != nullptr) {
            Appointment* next = current->next;

            if (sorted == nullptr || sorted->hour > current->hour || (sorted->hour == current->hour && sorted->minute > current->minute)) {
                // Insert at the beginning
                current->next = sorted;
                sorted = current;
            } else {
                // Traverse the sorted list to find the correct position
                Appointment* temp = sorted;
                while (temp->next != nullptr && (temp->next->hour < current->hour || (temp->next->hour == current->hour && temp->next->minute < current->minute))) {
                    temp = temp->next;
                }
                // Insert at the correct position
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        // Update the head of the linked list
        head = sorted;
    }

    // Function to sort list based on time using pointer manipulation
    void sortListPointerManipulation() {
        if (head == nullptr || head->next == nullptr) {
            return; // No or only one element in the list, no need to sort
        }

        Appointment* sorted = nullptr;
        Appointment* current = head;

        while (current != nullptr) {
            Appointment* next = current->next;
            Appointment** ptr = &sorted;

            while (*ptr != nullptr && ((*ptr)->hour < current->hour || ((*ptr)->hour == current->hour && (*ptr)->minute < current->minute))) {
                ptr = &((*ptr)->next);
            }

            // Insert at the correct position
            current->next = *ptr;
            *ptr = current;

            current = next;
        }

        // Update the head of the linked list
        head = sorted;
    }

    // Function to add a new appointment slot
    void addAppointmentSlot(int hour, int minute) {
        Appointment* newAppointment = new Appointment{hour, minute, false, nullptr};

        if (head == nullptr) {
            head = newAppointment;
        } else {
            Appointment* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newAppointment;
        }
    }
};

// Function to print the menu
void printMenu() {
    std::cout << "1. Display Free Slots\n";
    std::cout << "2. Book Appointment\n";
    std::cout << "3. Cancel Appointment\n";
    std::cout << "4. Sort List based on Time\n";
    std::cout << "5. Sort List based on Time using Pointer Manipulation\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    AppointmentManager appointmentManager;

    // Add appointment slots for the day
    appointmentManager.addAppointmentSlot(9, 0);
    appointmentManager.addAppointmentSlot(10, 0);
    appointmentManager.addAppointmentSlot(11, 0);
    appointmentManager.addAppointmentSlot(13, 0);
    appointmentManager.addAppointmentSlot(14, 0);
    appointmentManager.addAppointmentSlot(15, 0);
    appointmentManager.addAppointmentSlot(16, 0);

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                appointmentManager.displayFreeSlots();
                break;
            case 2: {
                int startHour, startMinute, endHour, endMinute;
                std::cout << "Enter start time (hour minute): ";
                std::cin >> startHour >> startMinute;
                std::cout << "Enter end time (hour minute): ";
                std::cin >> endHour >> endMinute;
                appointmentManager.bookAppointment(startHour, startMinute, endHour, endMinute);
                break;
            }
            case 3: {
                int startHour, startMinute, endHour, endMinute;
                std::cout << "Enter start time (hour minute): ";
                std::cin >> startHour >> startMinute;
                std::cout << "Enter end time (hour minute): ";
                std::cin >> endHour >> endMinute;
                appointmentManager.cancelAppointment(startHour, startMinute, endHour, endMinute);
                break;
            }
            case 4:
                appointmentManager.sortList();
                std::cout << "List sorted based on time.\n";
                break;
            case 5:
                appointmentManager.sortListPointerManipulation();
                std::cout << "List sorted based on time using pointer manipulation.\n";
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
