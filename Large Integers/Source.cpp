#include <iostream>
#include <string>
#include "LargeInt.h"

using namespace std;

const int kEndOfLine = 1024;

string stringInput(){
	string userInput = "";
	cout << "Enter a number : ";
	cin >> userInput;
	bool validInput = !userInput.empty() && !cin.fail();
	while (!validInput) {
		cout << "Invalid input. Please try again : ";
		cin.clear();
		cin.ignore(kEndOfLine, '\n');
		cin >> userInput;
		validInput = !userInput.empty() && !cin.fail();
	}
	return userInput;
}

bool isRunAgain() {
	bool isAgain = false;
	cout << "Would you like to rerun the program? Enter 'Y' for yes or 'N' for no : ";
	char userResponse;
	cin >> userResponse;
	bool validResponse = userResponse == 'Y' || userResponse == 'N';
	while (!validResponse) {
		cin.clear();
		cin.ignore(kEndOfLine, '\n');
		cout << "Please try again : ";
		cin >> userResponse;
		validResponse = userResponse == 'Y' || userResponse == 'N';
	}
	if (userResponse == 'Y') {
		isAgain = true;
	}
	else if (userResponse == 'N') {
		cout << "Program closing.";
		isAgain = false;
	}
	else {
		cout << "Invalid Selection. Program Terminating.";
		isAgain = false;
	}
	return isAgain;
}

void TestCode() {
	/*string testNumber = stringInput();
	cout << testNumber << endl;*/
	LargeInt v1, v2, v3;
	v1.setNumber("12");
	cout << "v1" << v1.getNumber() << endl;
	v2.setNumber("19");
	cout << "v2" << v2.getNumber() << endl;
	cout << "Sum starting." << endl << endl;
	v3 = v1.add(v2);
	cout << "v3" << v3.getNumber() << endl;

	system("pause");
}

int main() {
	//TestCode();

	bool isAgain = false;

	do {
		LargeInt v1, v2, v3;

		string firstNumber = stringInput();
		string secondNumber = stringInput();

		v1.setNumber(firstNumber);
		v2.setNumber(secondNumber);
		v3 = v1.add(v2);

		cout << "First Number : " << v1.getNumber() << endl;
		cout << "Second Number : " << v2.getNumber() << endl;
		cout << "Sum : " << v3.getNumber() << endl << endl;

		isAgain = isRunAgain();
	} while (isAgain);

	return 0;
}
