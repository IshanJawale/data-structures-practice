#include<iostream>
using namespace std;

class Node {
    public:
    Node *link;
    int data;
};

void insertData(Node* temp, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->link = temp;
    temp = newNode;
    cout << "Node Added" << endl;
    
}

void displayList(Node* temp) {
    Node* current = temp;
    if (current == nullptr) {
        cout <<"Linked List is empty..." << endl;
        return;
    }
    while(current != nullptr){
        cout << "The data is: " << current->data << endl;
    }
}

int main() {
    Node* node = nullptr;
    int ent;
    cout << "Enter the number of entries: ";
    cin >> ent;
    int data[ent];
    for (int i = 0; i < ent; i++) {
        cout << "Enter the data: ";
        cin >> data[i];
        insertData(node, data[i]);
    }
    
    cout << "The linked list is: " << endl;
    displayList(node);
    
    return 0;
}