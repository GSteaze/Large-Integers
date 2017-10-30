#pragma once
#include <string>

using namespace std;

class LargeInt
{

private:
	int _firstNumber[100];
	int _secondNumber[100];
	int _result[101];
	string _number;
	string _secondValue;
	bool _isNegative;

public:
	LargeInt();
	~LargeInt();
	void setNumber(string number);
	void negativeNumber();
	void setSecondNumber(string number);
	string getNumber();
	string getResult();
	void fillArray();

	LargeInt add(LargeInt& rValue);
	LargeInt operator+(const LargeInt& rValue);
	LargeInt subtract(LargeInt& rValue);
};

