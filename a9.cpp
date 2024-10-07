#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Function to print the original string followed by the reversed string using a stack
void printOriginalAndReversed(const string& input) {
    stack<char> charStack;

    // Push each character onto the stack
    for (char c : input) {
        charStack.push(c);
    }

    // Print the original string
    cout << "Original String: " << input << endl;

    // Print the reversed string
    cout << "Reversed String: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl;
}

// Function to check whether a given string is a palindrome or not
bool isPalindrome(const string& input) {
    stack<char> charStack;

    // Push each character onto the stack
    for (char c : input) {
        if (isalpha(c)) {  // Ignore non-alphabetic characters
            charStack.push(tolower(c));
        }
    }

    // Compare the characters from the stack with the original string
    for (char c : input) {
        if (isalpha(c)) {
            if (tolower(c) != charStack.top()) {
                return false; // Not a palindrome
            }
            charStack.pop();
        }
    }

    return true; // Palindrome
}

int main() {
    string input;

    // Get input from the user
    cout << "Enter a string: ";
    getline(cin, input);

    // Task 1: Print original and reversed string
    printOriginalAndReversed(input);

    // Task 2: Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The given string is a palindrome.\n";
    } else {
        cout << "The given string is not a palindrome.\n";
    }

    return 0;
}
