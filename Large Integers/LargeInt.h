#pragma once
#include <string>

class LargeInt
{

private:
	int _firstNumber[100];
	int _secondNumber[100];
	int _result[101];

public:
	LargeInt();
	~LargeInt();
	void setNumber(string number);
	string getNumber();
	void fillArray();
};

