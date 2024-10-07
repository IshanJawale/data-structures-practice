#include<iostream>
using namespace std;
int main() {
    int n; 
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n], add[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum{0};
    for (int i = 0; i < n; i++) {
        add[i] = sum + arr[i];
        sum = add[i];
    }
    for (int i = 0; i < n; i++) {
        cout << add[i] << "\t";
    }
    cout << endl;
    return 0;

}