#include<iostream>
#include<cstring>
using namespace std;
int main() {
    string str, x, w, str1, str2;
    int position, length;
    cout << "Enter the string: ";
    cin >> str;
    int n = str.length();
    cout << "Enter the position: ";
    cin >> position;
    int duplicate;
    duplicate = position;
    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter a new string: ";
    cin >> x;
    string str_del = "";
    for(int i = 0; i < n; i++) {
        if(str[i] == str[position] && position < length) {
            position++;
            continue;
        }
        else if(str[i] != str[position] && position < length) {
            str_del +=str[i];
            position++;
            
        }
    }
    cout << endl;
    cout << str_del << endl;
    return 0;
}