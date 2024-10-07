/*
Set operations: Write a menu driven C++ program to store sets for students' names participating in different events in Equinox such as Coding contest, Project competition, Paper Presentation, MasterMind etc.
1. Find out participants who have participated in Coding and Project both
2. Find out participants who have participated in Coding or Project competition or both or Mastermind
3. Find out participants who have participated in Coding but not in Master mind 
Find out participants who have participated in all events

Name: Ishan Jawale
Roll no: 28
Div: A
Class: S.Y.Btech
Branch: Computer Engineering
Course: Data Structures Lab
*/


#include<iostream>
using namespace std;

class students {
	public:
		string name;
		int roll;
		double marks;
		char att;
		char c, p, r, m;
		void Input() {
			cout << "Enter the name of the student: ";
			cin >> name;
			cout << "Enter the roll no of the student: ";
			cin >> roll;
			cout << "Enter the marks obtained: ";
			cin >> marks;
			cout << "Enter the events participated in: \nEnter:\nY: Yes\nN: No\n";
			cout << "Coding Contest: ";
			cin >> c;
			cout << "Project Competetion: ";
			cin >> p;
			cout << "Paper Presentation: ";
			cin >> r;
			cout << "MasterMind: ";
			cin >> m;
		}
		void Display() {
			cout << "The name of the student is: " << name << endl
				 << "The roll no ot the student is: " << roll << endl
				 << "The marks obtained by the student is: " << marks << endl;
		}
};

int main() {
	int n;
	cout << "Enter the number of students: ";
	cin >> n;
	students arr[n];
	cout << "Input details: " << endl;
	for (int i = 0; i < n; i++) {
		arr[i].Input();
	}
	int ch;
	do {
	cout << "Enter:\n1: Display only names\n2: Display students with marks more than 40.\n3: Display students with marks less than 40.\n" << "4. Participated in both Coding and project\n5. Participated in Coding or Project Competetion or both or Matermind\n6. Count no of students with marks entered\n7. Participated in Coding but not in Master Mind\n8. Participated in all events\n9. Exit\nYour Choices: \n";
	cin >> ch;
	double mks;
	
	switch(ch) {
		case 1: {
			cout << "Displaying all the names: " << endl << endl;
			for (int i = 0; i < n; i++) {
				cout << i+1 << ". " << arr[i].name << endl;
			}
			break;
		}
		case 2: {
			cout << "Displaying all the students with marks more than 40." << endl << endl;
			for (int i = 0; i < n; i++) {
				if (arr[i].marks >= 40) {
					arr[i].Display();
					cout << endl;
				}
			}
			break;
		}
		case 3: {
			cout << "Displaying all the students with marks less than 40." << endl << endl;
			for (int i = 0; i < n; i++) {
				if (arr[i].marks < 40) {
					arr[i].Display();
					cout << endl;
				}
			}
			break;
		}
		case 4: {
			cout << "Displaying Students who participated in both Coding and Project Competetion: \n";
			for (int i = 0; i < n; i++) {
				if((arr[i].c=='Y' || arr[i].c == 'y') && (arr[i].p == 'Y' || arr[i].p == 'y')) {
					arr[i].Display();
				}
			}
			break;
		}
		case 5: {
			cout << "Displaying Students who participated in Coding or Project or both or MasterMind" << endl;
			for (int i = 0; i < n; i++) {
				if(arr[i].c=='Y' || arr[i].c == 'y' || arr[i].p == 'Y' || arr[i].p == 'y' || arr[i].m == 'Y' || arr[i].m == 'y') {
					arr[i].Display();
				}
			}
			break;
		}
		case 6: {
			int count = 0;
			cout << "Enter the marks: ";
			cin >> mks;
			for (int i = 0; i < n; i++) {
				if(arr[i].marks == mks) {
					count++;
				}
			}
			cout << count << " students have " << mks << " marks." << endl;
			break;
		}
		case 7: {
			cout << "Displaying Students who participated in Coding but not in MasterMind" << endl;
			for (int i = 0; i < n; i++) {
				if((arr[i].c=='Y' || arr[i].c == 'y') && (arr[i].m == 'N' || arr[i].m == 'n')) {
					arr[i].Display();
				}
			}
			break;
		}
		case 8: {
			cout << "Displaying Students who participated in  all events" << endl;
			for (int i = 0; i < n; i++) {
				if((arr[i].c=='Y' || arr[i].c == 'y') && (arr[i].p == 'Y' || arr[i].p == 'y') && (arr[i].m == 'Y' || arr[i].m == 'y') && (arr[i].r == 'Y' || arr[i].r == 'y')) {
					arr[i].Display();
				}
			}
			break;
		}
		case 9: {
			cout << endl << "Thank You!" << endl;
			break;
		}
		default: 
			cout << "Invalid Input..." << endl;
	}
	} while (ch!=9);
	return 0;
}
