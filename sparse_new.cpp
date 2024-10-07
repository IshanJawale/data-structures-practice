#include <iostream>
using namespace std;

const int MAX = 100;

class Sparse {
private:
    int mat[MAX][3];
    int row, col, terms;

public:
    Sparse(int r, int c) {
        row = r;
        col = c;
        terms = 0;
    }

    void toSparse() {
        cout << "Enter the elements of the matrix:" << endl;
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

    void displaySparseMatrix() {
        //cout << "Sparse Matrix:" << endl;
        for (int i = 0; i < terms; i++) {
            cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
        }
    }

    void simpleTranspose() {
        int sparseT[MAX][3];
        int freq[MAX] = {0};
        int rowStartPos[MAX] = {0};

        for (int i = 0; i < terms; i++) {
            freq[mat[i][1]]++;
        }

        rowStartPos[0] = 0;
        for (int j = 1; j < col; j++) {
            rowStartPos[j] = rowStartPos[j - 1] + freq[j - 1];
        }

        for (int i = 0; i < terms; i++) {
            int j = mat[i][1];
            int k = rowStartPos[j];
            sparseT[k][0] = mat[i][1];
            sparseT[k][1] = mat[i][0];
            sparseT[k][2] = mat[i][2];
            rowStartPos[j]++;
        }

        terms = rowStartPos[col - 1] + freq[col - 1];
        for (int i = 0; i < terms; i++) {
            mat[i][0] = sparseT[i][0];
            mat[i][1] = sparseT[i][1];
            mat[i][2] = sparseT[i][2];
        }
    }

    void fastTranspose() {
        int sparseT[MAX][3];
        int freq[MAX] = {0};
        int rowStartPos[MAX] = {0};

        for (int i = 0; i < terms; i++) {
            freq[mat[i][1]]++;
        }

        rowStartPos[0] = 0;
        for (int j = 1; j < col; j++) {
            rowStartPos[j] = rowStartPos[j - 1] + freq[j - 1];
        }

        for (int i = 0; i < terms; i++) {
            int j = mat[i][1];
            int k = rowStartPos[j];
            sparseT[k][0] = mat[i][1];
            sparseT[k][1] = mat[i][0];
            sparseT[k][2] = mat[i][2];
            rowStartPos[j]++;
        }

        terms = rowStartPos[col - 1] + freq[col - 1];
        for (int i = 0; i < terms; i++) {
            mat[i][0] = sparseT[i][0];
            mat[i][1] = sparseT[i][1];
            mat[i][2] = sparseT[i][2];
        }
    }

    static Sparse addSparseMatrices(Sparse A, Sparse B) {
        Sparse C(A.row, A.col);
        int i = 0, j = 0, k = 0;

        while (i < A.terms && j < B.terms) {
            if (A.mat[i][0] == B.mat[j][0]) {
                if (A.mat[i][1] == B.mat[j][1]) {
                    C.mat[k][0] = A.mat[i][0];
                    C.mat[k][1] = A.mat[i][1];
                    C.mat[k][2] = A.mat[i][2] + B.mat[j][2];
                    i++;
                    j++;
                    k++;
                } else if (A.mat[i][1] < B.mat[j][1]) {
                    C.mat[k][0] = A.mat[i][0];
                    C.mat[k][1] = A.mat[i][1];
                    C.mat[k][2] = A.mat[i][2];
                    i++;
                    k++;
                } else {
                    C.mat[k][0] = B.mat[j][0];
                    C.mat[k][1] = B.mat[j][1];
                    C.mat[k][2] = B.mat[j][2];
                    j++;
                    k++;
                }
            } else if (A.mat[i][0] < B.mat[j][0]) {
                C.mat[k][0] = A.mat[i][0];
                C.mat[k][1] = A.mat[i][1];
                C.mat[k][2] = A.mat[i][2];
                i++;
                k++;
            } else {
                C.mat[k][0] = B.mat[j][0];
                C.mat[k][1] = B.mat[j][1];
                C.mat[k][2] = B.mat[j][2];
                j++;
                k++;
            }
        }

        while (i < A.terms) {
            C.mat[k][0] = A.mat[i][0];
            C.mat[k][1] = A.mat[i][1];
            C.mat[k][2] = A.mat[i][2];
            i++;
            k++;
        }

        while (j < B.terms) {
            C.mat[k][0] = B.mat[j][0];
            C.mat[k][1] = B.mat[j][1];
            C.mat[k][2] = B.mat[j][2];
            j++;
            k++;
        }

        C.terms = k;
        return C;
    }
};

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns for the Matrix: ";
    cin >> rows >> cols;
    Sparse A(rows, cols);
    A.toSparse();

    Sparse B(rows, cols);
    B.toSparse();

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display Sparse Matrices\n";
        cout << "2. Add Matrices\n";
        cout << "3. Simple Transpose Matrices\n";
        cout << "4. Fast Transpose Matrices\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nSparse Matrix A:\n";
                A.displaySparseMatrix();
                cout << "\nSparse Matrix B:\n";
                B.displaySparseMatrix();
                break;
            }
            case 2: {
                Sparse C = Sparse::addSparseMatrices(A, B);
                cout << "\nSparse Matrix A + B:\n";
                C.displaySparseMatrix();
                break;
            }
            case 3: {
                A.simpleTranspose();
                cout << "\nSimple Transpose of Matrix A:\n";
                A.displaySparseMatrix();
                break;
            }
            case 4: {
                A.fastTranspose();
                cout << "\nFast Transpose of Matrix A:\n";
                A.displaySparseMatrix();
                break;
            }
            case 5: {
                cout << "Exiting the program.\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
