#include <string>
#include <iostream>
#include "LargeInt.h"

LargeInt::LargeInt()
{
	fillArray();
	_result[101] = 0;
	_number = "0";
	_secondValue = "";
	_isNegative = false;
}


LargeInt::~LargeInt()
{
}

void LargeInt::setNumber(string number) {
	_number = number;
	for (int index = 0; index < number.length(); index++) {
		_firstNumber[index] = ((int)number[index]) - '0';
		
		//cout << "number" << ((int)number[index] - '0') << endl;
		//cout << "_number" << _firstNumber[index] << endl;

	}
	negativeNumber();
}

void LargeInt::negativeNumber() {
	if (_number.find('-') != NULL) {
		_isNegative = true;
	}
}

void LargeInt::setSecondNumber(string number) {
	_secondValue = number;
	for (int index = 0; index < number.length(); index++) {
		_secondNumber[index] = ((int)number[index]) - '0';
	}
}


void LargeInt::fillArray() {
	for (int index = 0; index < 100; index++) {
		_firstNumber[index] = 0;
		_secondNumber[index] = 0;
		_result[index] = 0;
	}
}

string LargeInt::getNumber() {
	string result = "";
	for (int index = 0; index < 100; index++) {
		char digit = ((char)_firstNumber[index] + '0');
		result.push_back(digit);
	}
	return result;
}

string LargeInt::getResult() {
	string result = "";
	for (int index = 0; index < 100; index++) {
		char digit = _result[index];
		result.push_back(digit);
	}
	return result;
}

LargeInt LargeInt::add(LargeInt& rValue) {
	LargeInt result;
	setSecondNumber(rValue.getNumber());
	
	//cout << "rValue" << rValue.getNumber() << endl;
	//cout << "second number" << _secondValue << endl;

	bool isDigitCarried = false;

	for (int index = 99; index >= 0; index--) {
		int digit = _firstNumber[index] + _secondNumber[index];

		//cout << digit << endl;

		if (isDigitCarried) {
			digit += 1;
		}
		if (digit >= 10) {
			_result[index + 1] = digit % 10;
			isDigitCarried = true;
		}
		else if (digit >= 0 && digit < 10) {
			_result[index + 1] = digit;
			isDigitCarried = false;
		}


		//cout << "Result" << _result[index] << endl;
		//cout << "loop number" << index << endl;

	}
	if (isDigitCarried) {
		_result[0] = 1;
	}

	result.setNumber(getResult());
	return result;
}

LargeInt LargeInt::subtract(LargeInt& rValue) {
	LargeInt result;
	setSecondNumber(rValue.getNumber());
	bool isBorrowedDigit = false;

	for (int index = 99; index >= 0; index--) {
		int digit = _firstNumber[index] - _secondNumber[index];
		if (isBorrowedDigit) {
			if (_firstNumber[index] == 0) {
				_firstNumber[index] = 9;
				_firstNumber[index - 1] -= 1;
			} else {
				_firstNumber[index] -= 1;
			}
		}
		if (digit < 0) {
			isBorrowedDigit = true;
			digit += 10;
		}
		else {
			isBorrowedDigit = false;
		}
	}
	result.setNumber(getResult());
	return result;
}

//LargeInt operator+(const LargeInt& rValue) {
//
//}
