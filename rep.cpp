#include <iostream>
using namespace std;
int main()
{
    string str;
    string replacement;
    string newStr = "";
    int index;
    int length;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Enter the string to replace: ";
    cin >> replacement;
    cout << "Enter the index: ";
    cin >> index;
    cout << "Enter the length: ";
    cin >> length;

    for (int i = 0; i < str.length(); i++)
    {
        if (i >= index && i < index + length)
        {
            newStr += replacement[i - index];
        }
        else
        {
            newStr += str[i];
        }
    }

    cout << newStr << endl;
    return 0;
}