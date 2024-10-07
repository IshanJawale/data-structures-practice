/*
Sparse Matrix: Write a menu driven C++ program with class for Sparse Matrix. Write functions to perform Sparse Matrix operations as listed below: 
1. Read sparse matrix
2. Display sparse matrix
3. Add two sparse matrices
4. Find transpose using Simple transpose algorithm
5. Find transpose using Fast transpose algorithm
Compare complexity of simple and fast transpose using counter.

Name: Ishan Jawale
Roll no: 28
Div: A
Class: S.Y.Btech
Branch: Computer Engineering
Course: Data Structures Lab
*/


#include <iostream>
using namespace std;

class Sparse {
private:
    int mat[100][3];
    int row, col, terms ;

public:
    Sparse(int r, int c) {
        row = r;
        col = c;
        terms = 0;
    }

    void toSparse() {
        cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int val;
                cin >> val;
                if (val != 0) {
                    mat[terms][0] = i;
                    mat[terms][1] = j;
                    mat[terms][2] = val;
                    terms++;
                }
            }
        }
    }

    void displaySparse() {
        for (int i = 0; i < terms; i++) {
            for (int j = 0; j < 3; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void addSparse(Sparse &m) {
        int i = 0, j = 0, k = 0;
        Sparse result(row, col);
        while (i < terms && j < m.terms) {
            if (mat[i][0] < m.mat[j][0] || (mat[i][0] == m.mat[j][0] && mat[i][1] < m.mat[j][1])) {
                result.mat[k][0] = mat[i][0];
                result.mat[k][1] = mat[i][1];
                result.mat[k][2] = mat[i][2];
                k++;
                i++;
            } else if (mat[i][0] > m.mat[j][0] || (mat[i][0] == m.mat[j][0] && mat[i][1] > m.mat[j][1])) {
                result.mat[k][0] = m.mat[j][0];
                result.mat[k][1] = m.mat[j][1];
                result.mat[k][2] = m.mat[j][2];
                k++;
                j++;
            } else {
                if (mat[i][2] + m.mat[j][2] != 0) {
                    result.mat[k][0] = mat[i][0];
                    result.mat[k][1] = mat[i][1];
                    result.mat[k][2] = mat[i][2] + m.mat[j][2];
                    k++;
                }
                i++;
                j++;
            }
        }
        while (i < terms) {
            result.mat[k][0] = mat[i][0];
            result.mat[k][1] = mat[i][1];
            result.mat[k][2] = mat[i][2];
            k++;
            i++;
        }
        while (j < m.terms) {
            result.mat[k][0] = m.mat[j][0];
            result.mat[k][1] = m.mat[j][1];
            result.mat[k][2] = m.mat[j][2];
            k++;
            j++;
        }
        result.terms = k;
        result.displaySparse();
    }

    void simpleTranspose() {
        Sparse result(col, row);
        result.terms = terms;
        if (terms > 0) {
            int index = 0;
            for (int c = 0; c < col; c++) {
                for (int i = 0; i < terms; i++) {
                    if (mat[i][1] == c) {
                        result.mat[index][0] = mat[i][1];
                        result.mat[index][1] = mat[i][0];
                        result.mat[index][2] = mat[i][2];
                        index++;
                    }
                }
            }
        }
        result.displaySparse();
    }

    void fastTranspose() {
        Sparse result(col, row);
        result.terms = terms;
        if (terms > 0) {
            int rowSize[col], rowStart[col];
            for (int i = 0; i < col; i++) {
                rowSize[i] = 0;
            }
            for (int i = 0; i < terms; i++) {
                rowSize[mat[i][1]]++;
            }
            rowStart[0] = 0;
            for (int i = 1; i < col; i++) {
                rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            }
            for (int i = 0; i < terms; i++) {
                int j = rowStart[mat[i][1]];
                result.mat[j][0] = mat[i][1];
                result.mat[j][1] = mat[i][0];
                result.mat[j][2] = mat[i][2];
                rowStart[mat[i][1]]++;
            }
        }
        result.displaySparse();
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    Sparse matrix1(rows, cols), matrix2(rows, cols);
    matrix1.toSparse();
    matrix2.toSparse();

    int ch;
    do {
        cout << "\nSparse Matrix Operations:" << endl;
        cout << "1. Display sparse matrix" << endl;
        cout << "2. Add two sparse matrices" << endl;
        cout << "3. Find transpose using Simple transpose algorithm" << endl;
        cout << "4. Find transpose using Fast transpose algorithm" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "The first Matrix is: " << endl;
            matrix1.displaySparse();
            cout << "The second Matrix is: " << endl;
            matrix2.displaySparse();
            break;
        case 2:
            matrix1.addSparse(matrix2);
            break;
        case 3:
            matrix1.simpleTranspose();
            break;
        case 4:
            matrix1.fastTranspose();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while(ch!=5);

    return 0;
}

