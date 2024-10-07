#include<iostream>
using namespace std;

class Poly {
    int poly[100] = {0};
    public:
        void inputPoly(int n);
        void displayPoly(int n);
};

void Poly :: inputPoly(int n) {
    
    int exp;
    for(int i=0; i < n; i++) {
        cout << "Enter the exponent for coefficient no. " << i+1 << ":";
        cin >> exp;
        cout << "Enter the coefficient no. " << i+1 << ":";
        cin >> poly[exp]; 
    }
}

void Poly :: displayPoly(int n) {
    cout << "The entered polynomial is: " << endl;
    int count = 0;
    for (int i = 99; i >=0; i--) {
        if (i == 0 && poly[i]!=0) {
            cout << poly[i];
            count++;
        }
        else if(count == n-1 && poly[i]!=0) {
            cout << poly[i] << "x^" << i;
        }
        else if(poly[i]!=0) {
            cout << poly[i] << "x^" << i << "+";
            count++;
        }
    }
        cout << endl;
}

int main() {
    Poly p;
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    p.inputPoly(n);
    p.displayPoly(n);
    return 0;
}
