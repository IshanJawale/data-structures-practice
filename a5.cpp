/*
Polynomial operations: Write a menu driven C++ program with class for single variable polynomial and write functions to perform following polynomial operations using arrays:
1. Read polynomial
2. Display polynomial
3. Add two polynomials

Name: Ishan Jawale
Roll no: 28
Div: A
Class: S.Y.Btech
Branch: Computer Engineering
Course: Data Structures Lab
*/

#include<iostream>
#include<cmath>
using namespace std;
struct Poly{
    int coeff = 0, exp = 0;
};

int nt= 0;

void readPoly(int n, struct Poly p[]) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the coefficient no. " << i+1 << ": ";
        cin >> p[i].coeff;
        cout << "Enter the exponent for coeeficient no. " << i+1 << ": ";
        cin >> p[i].exp;
    }
}

void displayPoly(int n, struct Poly p[]) {
    for (int i = 0; i < n; i++) {
        if(p[i].exp == 0) {
            cout << p[i].coeff << endl;
            continue;
        }
        else if(p[i].coeff == 0) {
            continue;
        }
        else if(i == n-1) {
            cout << p[i].coeff << "x^" << p[i].exp << endl;
            continue;
        }
        cout << p[i].coeff << "x^" << p[i].exp << "+";
    }
}

double evalPoly(int n, struct Poly p[]) {
    double x;
    cout << "Enter the value of x: ";
    cin >> x;
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += p[i].coeff*(pow(x, p[i].exp));
    }
    return result;
}

void addPoly(int n1, int n2, struct Poly p1[], struct Poly p2[], struct Poly add[], int lim) {
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(p1[i].exp == p2[j].exp) {
            add[k].coeff = p1[i].coeff + p2[j].coeff;
            add[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
            nt++;
        } 
        
        else {
            if (p1[i].exp > p2[j].exp) {
            add[k].exp = p1[i].exp;
            add[k].coeff = p1[i].coeff;
            i++;
            k++;
            nt++;
            }
            
            else {
            add[k].exp = p2[j].exp;
            add[k].coeff = p2[j].coeff;
            j++;
            k++;
            nt++;
            }
        }
    }
    while (i < n1) {
        add[k].coeff = p1[i].coeff;
        add[k].exp = p1[i].exp;
        i++;
        k++;
        nt++;
    }
    while (j < n2) {
        add[k].coeff = p2[j].coeff;
        add[k].exp = p2[j].exp;
        j++;
        k++;
        nt++;
    }
}

int main() {
    int n;
    struct Poly p[n];
    int ch;
    do{
    cout << "Enter:\n1: Read Polynomial\n2: Display Polynomial\n3: Evaluate Polynomial\n4: Add Polynomial\n5: Exit\nYour Choice: ";
    cin >> ch;
        switch(ch) {
            case 1: {
                cout << "Enter the total number of terms: ";
                cin >> n;
                readPoly(n, p);
                break;
            }
            case 2: {
                displayPoly(n, p);
                break;
            }
            case 3: {
                cout << "Evalutation of the polynomial: " << endl;
                cout << "The evaluated value = " << evalPoly(n, p) << endl;
                break;
            }
            case 4: {
                int n1;
                cout << "Enter the total number of terms of first polynomial: ";
                cin >> n1;
                struct Poly p1[n1];
                readPoly(n1, p1);
                int n2;
                cout << "Enter the total number of terms of second polynomial: ";
                cin >> n2;
                struct Poly p2[n2];
                readPoly(n2, p2);
                int lim = (n1 >= n2) ? n1 : n2;
                struct Poly add[100];
                
                addPoly(n1, n2, p1, p2, add, lim);
                displayPoly(nt, add);
                break;
            }
            case 5: { 
                cout << "Exiting the program..." << endl;
                break;
            }
            default:
                break;
        }
    } while(ch!=5);
    
    return 0;
}
