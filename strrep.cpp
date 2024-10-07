#include<iostream> 
#include<string.h> 
using namespace std;
void replaceSubstring(char st[],char new_str[])//Function to replace substring.
{
    int stLen,subLen,newLen;
    int i=0,j,k;
    int flag=0,start,end;
    stLen=strlen(st);
    newLen=strlen(new_str);
    cout << "Enter the starting index: ";
    cin >> start;
    cout << "Enter the length of the substring to be replaced: ";
    cin >> subLen;

    for(j=start;j<=subLen;j++)
    {
        for(k=start;k<stLen;k++)
            st[k]=st[k+1];
        stLen--;
        i--;
    }
    for(j=start;j<start+newLen;j++)//Replacing suv string with the input string           
        {                
        for(k=stLen;k>=j;k--)
            st[k+1]=st[k];
        st[j]=new_str[j-start];
        stLen++;
        i++;
    }
}
//Main function.
int main() 
{
    char st[100],sub[100],new_str[100];
    cout << "Enter the etring: ";
    cin >> st;
    cout << "Enter the replacing string: ";
    cin >> new_str;
    
    replaceSubstring(st,new_str); 
    cout<<"The string after replacing substring: "<<st<<endl;
    return 0;
}