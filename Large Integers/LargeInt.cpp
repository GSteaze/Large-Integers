#include <string>
#include "LargeInt.h"

using namespace std;

LargeInt::LargeInt()
{
	fillArray();
	_result[101] = 0;
}


LargeInt::~LargeInt()
{
}

void LargeInt::setNumber(string number) {
	for (int index = 0; index < number.length(); index++) {
		_firstNumber[index] = ((int)number[index]) - '0';
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
		
}


