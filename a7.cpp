/*
String operations: A palindrome is a string of characters that's identical when read in forward and backward direction. Typically, punctuation, capitalization, and spaces are ignored. For example, “1.Poor Dan is in a droop!!” is a palindrome, as can be seen by examining the characters “poordanisinadroop” and observing that they are identical when read forward and backward directions. One way to check for a palindrome is to reverse the characters in the string and compare them with the original-in a palindrome, the sequence will be identical. Write C++ program with functions using Standard Template Library (STL) stack:
1. To print original string followed by reversed string using stack
2. To check whether given string is palindrome or not
*/

#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main() {
    string str;
    string str_;
    string str_rev;
    cout << "Enter a string: ";
    getline(cin, str);
    for(int i = 0; i < str.length(); i++) {
        if(isalpha(str[i])) {
            if(isupper(str[i])) {
                str_ += tolower(str[i]);
            }
            else {
                str_+=str[i];
            }
        }
    }
    stack<char> stack;
    for(int i = 0; i < str_.length(); i++) {
        stack.push(str_[i]);
    }
    while(!stack.empty()) {
        str_rev += stack.top();
        stack.pop();
    }
    cout << str_ << endl;
    cout << str_rev << endl;
    if(str_==str_rev) {
        cout << "The String entered is a palindrome!" << endl;
    }
    else{
        cout << "The String entered is not a palindrome..." << endl;
    }
    
}

/*
OUTPUT:
Enter a string: Poor Dan is in a droop!! 
poordanisinadroop
poordanisinadroop
The String entered is a palindrome!
*/