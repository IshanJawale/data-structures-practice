#include<iostream>
using namespace std;
class Matrix {
    int r{0}, c{0};
    int m[r][c];
    public:
    Matrix() {
        cout << "Enter the number of rows and columns: " << endl;
        cin >> r >> c;
    }
    

    void input() {
    int m[r][c];
    cout << "Enter the elements of the first matrix: " << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }
    }
    void display() {
    cout << "The first matrix is: " << endl;
    int m[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    }
    void add(Matrix &temp1, Matrix &temp2) {
    cout << "The addition of the matrix is: " << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << temp1.m[i][j] + temp2.m[i][j] << "\t";
        }

        cout << endl;
    }
    }
    void transpose() {
    cout << "The transpose addition of the matrix is: " << endl;
    int m[r][c];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << m[j][i] << "\t"
        }

        cout << endl;
    }
    }
};
int main() {
    int op;
    cout << "Enter:\n1: Enter and display matrix\n2: Matrix addition\n3: Transpose\nYour choice:";
    cin >> op;
    switch(op) {
        case 1: {
            Matrix obj;
            obj.input();
            obj.display();
            break;
        }
        case 2: {
            Matrix obj1, obj2;
            cout << "Enter the first matrix: " << endl;
            obj1.input();
            cout << "Enter the second matrix: " << endl;
            obj2.input();
            Matrix obj3;
            obj3.add(obj1, obj2);
            
        }
    }
    
    return 0;
}