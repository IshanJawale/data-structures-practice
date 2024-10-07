#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;
void insert(int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void display()
{
    struct Node *ptr = head;
    if (ptr == nullptr)
    {
        cout << "The list is empty..." << endl;
    }

    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void revDisplay() {
    struct Node *ptr = head;
    if (ptr == nullptr) {
        cout << "The list is empty..." << endl;
    }
    int count = 0;
    struct Node* temp;
    temp->next = ptr;
    while (ptr != nullptr) {
        ptr = ptr->next;
        count++;
    }
    cout << endl;
    while(ptr->next!=temp) {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}

int main()
{
    int ob;
    
    int a[100];
    int i = 0;
    do {
        cout << "Enter:\n1. Insert\n2. Display\n3. Reverse Display\n4. Exit" << endl;
        cin >> ob;
        switch (ob)
        {
        case 1: {
            cout << "Enter the element: ";
            cin >> a[i];
            insert(a[i]);
            i++;
            break;
        }
        case 2: {
            cout << "Display the doubly linked list...\n";
            display();
            break;
        }
        case 3: {
            cout << "Reverse Display..." << endl;
            revDisplay();
            break;
        }
        case 4: {
            cout << "Exiting the program...";
            break;
        }
        }
    } while (ob!=3);
    
    return 0;
}