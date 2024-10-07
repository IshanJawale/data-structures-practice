#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
};
class Llist
{
private:
    Node *Head, *Tail;
    void Recursive_Traverse(Node *tmp)
    {
        if (tmp == NULL)
            return;
        cout << tmp->data << "\t";
        Recursive_Traverse(tmp->link);
    }

public:
    Llist()
    {
        Head = NULL;
    }
    void Create();
    void Display();
    Node *GetNode();
    void Append(Node *NewNode);
    void Insert_at_Pos(Node *NewNode, int position);
    void R_Traverse()
    {
        Recursive_Traverse(Head);
        cout << endl;
    }
    void DeleteNode(int del_position);
    ~Llist()
    {
        Node *Temp;
        while (Head != NULL)
        {
            Temp = Head;
            Head = Head->link;
            delete Temp;
        }
    }
};

void Llist ::Create()
{
    char ans;
    Node *NewNode;
    while (1)
    {
        cout << "Any more nodes to be added (Y/N)";
        cin >> ans;
        if (ans == 'n')
            break;
        NewNode = GetNode();
        Append(NewNode);
    }
}
void Llist ::Append(Node *NewNode)
{
    if (Head == NULL)
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        Tail->link = NewNode;
        Tail = NewNode;
    }
}
Node *Llist ::GetNode()
{
    Node *Newnode;
    Newnode = new Node;
    cin >> Newnode->data;
    Newnode->link = NULL;
    return (Newnode);
}
void Llist ::Display()
{
    Node *temp = Head;
if(temp == NULL)
    cout << "Empty List";
else
{
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->link;
        }
}
cout << endl;
}
int main()
{
    Llist L1;
    L1.Create();
    L1.Display();
    return 0;
}