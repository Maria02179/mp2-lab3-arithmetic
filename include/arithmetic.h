// объявление функций и классов для вычисления арифметических выражений
#ifndef __TARITHMETIC_H__
#define __TARITHMETIC_H__
#include <string>
#include <vector>
#include <iostream>
#include "stack.h"

using namespace std;

const string Symbols = "0123456789.()+-/* ";

struct Lexem
{

private:
	char operation;
	double value;
	bool type;
public:
	Lexem() = default;
	Lexem(const double &_value)
	{
		value = _value;
		type = true;
	}
	Lexem(const char &_operation)
	{
		operation = _operation;
		type = false;
	}
	void printLexem()
	{
		if (type)
			std::cout << value << " ";
		else
			std::cout << operation << " ";
	}
	double getValue() { return value; }
	char getOperation() { return operation; }
	bool getType() { return type; }
	int priority();
};

class Arithmetic
{
public:
	vector<Lexem> smbls;


	Arithmetic() = default;
	void divide(string &expression);
	void ToPostfix();
	double calculate();
	void print();
};

bool checkBrackets(const string &s);
bool checkSymbols(const string &s);
bool isCorrect(const string &s);
#endif
