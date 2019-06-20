#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <regex>
#include <stack>
#include <iostream>
#include <any>
//#include <cmath>

using namespace std;
class Analyze
{
public:
	Analyze();
	~Analyze();
	
	bool hasBadChars(string);
	bool hasOperatorAtStart(string);
	bool hasOperatorAtEnd(string);
	bool isBadWritten(string);
	bool hasOpenedBracket(string);
	bool hasOpenedParentesis(string);
	bool hasOperator_AfterOperator(string);//5++8, 9--8, 7/*8

	bool isInt(string);
	bool isOperator(string );
	bool isFloat(string);

	int precedence(string);
	string calculate(string,string,string);
	vector<string>tokenize(string);
	int infix2postfix(string);
	

	vector<string>regex_tokens(string , regex );
};

