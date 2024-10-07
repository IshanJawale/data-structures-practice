/*
String Operations: Write a menu driven C++ program with a class for String. Write functions
1. To determine the frequency of occurrence of a particular character in the string.
2. Extract a new string from original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of same size that of x
5. To check whether given string is palindrome or not

Name: Ishan Jawale
Roll no: 28
Div: A
Class: S.Y.Btech
Branch: Computer Engineering
Course: Data Structures Lab
*/

#include<iostream>
#include<cstring>
using namespace std;
class String {
    string a_string;
    public:
        void frequency(string &str, int &n) {
            char character;
            cout << "Enter the character: ";
            cin >> character;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if(str[i] == character)
                    count++;
            }
            cout << "The number of times the character is present = " << count << endl;
        }
        void extract(string &str, int &n) {
            int new_length, position;
            string new_str;
            cout << "Enter the length of the new string: ";
            cin >> new_length;
            cout << "Enter the position from where new string begins: ";
            cin >> position;
            if (new_length <= n && position < n) {
                for (int i = 0; i < new_length; i++) {
                    new_str[i] = str[position];
                    cout << new_str[i];
                    position++;
                }
            }
            cout << endl;
            
        }
        void del(string &str, int &n) {
            char c;
            cout << "Enter a character: ";
            cin >> c;
            string str_new = "";
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] != c) {
                    str_new += str[i];
                }

            }
            cout << str_new << endl;
            
        } 
        
        void replace(string &str, int &n) {
            string w, x;
            int position, length;
            cout  << "Enter the string: ";
            cin >> x;
            cout << "Enter the length of the string to be replaced: ";
            cin >> length;
            cout << "Enter the position from where new string begins: ";
            cin >> position;
            int duplicate = position;

            for (int i = 0; i < length; i++) {
                w[i] = str[position];
                position++;
                str[i] = '\0';
            }
            string str1;
            for (int i = 0; i < duplicate; i++) {
                str1[i] = str[i];
            }
            int length2 = x.length();
            int temp_len = w.length();
            int new_index = duplicate + temp_len;
            string str2;
            for (int i = 0; str[new_index] != '\0'; i++) {
                str2[i] == str[new_index];
                str[new_index] = '\0';
                new_index++;
            }
            /*for(int i = 0; i < length2; i++) {
                str[duplicate] = x[i];
                duplicate++;
            }*/
            cout << str1 << endl << str2 << endl;
            cout << str1 + x + str2 << endl;
            
        }
        void palindrome(string &str, int &n) {
            string f, b;
            int count = 0;
            int flag = 0;
            for (int i = 0; i < n; i++) {
                b[i] = str[n-1];
                n--;
            }
            for (int i = 0; i < n; i++) {
                if(str[i] != b[i])
                    flag = 1;
                    break;
            }
            if (flag == 1) {
                cout << "It is not a palindrome..." << endl;
            }
            else
                cout << "It is a palindrome..." << endl;
        }
};

int main() {
    String obj;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int n = str.length();
    int ch;
    do{
        cout << "Enter:\n1: count no. of entered characters\n2: Extract a new string from original string by accepting starting position and length\n3: delete a character\n4: replace string\n5: paindrome\n6: Exit\nYour choice: ";
        cin >> ch;
        switch(ch) {
            case 1: {
                obj.frequency(str, n);
                break;
            }
            case 2: {
                obj.extract(str, n);
                break;
            }
            case 3: {
                obj.del(str, n);
                break;
            }
            case 4: {
                obj.replace(str, n);
                break;
            }
            case 5: {
                obj.palindrome(str, n);
                break;
            }
            case 6: {
                cout << "Exitingthe program..." << endl;
                break;
            }
            default:
                cout << "Invalid Input..." << endl;

        }
    } while(ch!=6);
    return 0;
}