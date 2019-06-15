#include "Analyze.h"



Analyze::Analyze()
{
}
Analyze::~Analyze()
{
}

//Verifications

vector<string> Analyze::regex_tokens(string expr, regex words_regex_) {
	vector<string>tokens;
	regex words_regex = words_regex_;
	auto words_begin = sregex_iterator(expr.begin(), expr.end(), words_regex);
	auto words_end = sregex_iterator();
	//Verifying if the expr has an uncompatible character
	for (sregex_iterator i = words_begin; i != words_end; ++i) {
		tokens.push_back((*i).str());
	}
	return tokens;
}
bool Analyze::hasBadChars(string expr) {
	regex words_regex("[^0-9()+\\-\\+\\\\\(\\)\\/\\[\\]\\*\\^\\%]");
	if (regex_tokens(expr, words_regex).size() >= 1)
		return 1;
	return 0;

}
bool Analyze::hasOperatorAtStart(string expr) {
	if (isdigit(expr[0]))
		return false;
	return true;
}
bool Analyze::hasOperatorAtEnd(string expr) {

	if (isdigit(expr[expr.length() - 1]) || expr[expr.length() - 1] == '(' || expr[expr.length() - 1] == ')')
		return false;
	return true;
}
bool Analyze::hasOpenedParentesis(string expr) {
	int leftPar = 0, rightPar = 0;

	for (int i = 0; i < expr.length(); i++)
	{
		if (!isdigit(expr[i]) && expr[i] == '(')
			leftPar++;
		else if (!isdigit(expr[i]) && expr[i] == ')')
			rightPar++;

	}

	if (leftPar != rightPar)
		return true;

	return false;
}
bool Analyze::hasOpenedBracket(string expr) {
	int leftBracket = 0, rightBracket = 0;

	for (int i = 0; i < expr.length(); i++)
	{
		if (!isdigit(expr[i]) && expr[i] == '[')
			leftBracket++;

		else if (!isdigit(expr[i]) && expr[i] == ']')
			rightBracket++;

	}

	if (leftBracket != rightBracket)
		return true;

	return false;
}
bool Analyze::hasOperator_AfterOperator(string expr) {
	for (int i = 0; i < expr.length(); i++)
	{
		if (!isdigit(expr[i]) && expr[i + 1] != '('&& expr[i + 1] != ')'&&expr[i + 1] != NULL) {
			if (isdigit(expr[i + 1])) {
				continue;
			}
			else {
				return true;
			}

		}
	}
	return false;
}
bool Analyze::isBadWritten(string expr) {
	bool bad = false;
	int i = 0;
	do {
		switch (i)
		{
		case 0:
			bad = hasOperatorAtStart(expr);
			break;
		case 1:
			bad = hasBadChars(expr);
			break;
		case 2:
			bad = hasOpenedBracket(expr);
			break;
		case 3:
			bad = hasOpenedParentesis(expr);
			break;
		case 4:
			bad = hasOperator_AfterOperator(expr);
			break;
		case 5:
			bad = hasOperatorAtEnd(expr);
			break;
		}
		i++;
	} while (bad == false && i <= 5);

	if (bad == true) {
		cout << "malisimo" << endl;
		return true;
	}
	return false;
}

bool Analyze::isInt(string str) {

	std::regex words_regex("[^0-9]");
	if (regex_tokens(str, words_regex).size() >= 1)
		return false;
	return true;

}
bool Analyze::isFloat(string str) {

	std::regex words_regex("([0-9]*[.])");
	//Verifying ig the expr has an uncompatible character
	if (regex_tokens(str, words_regex).size() >= 1)
		return true;
	return false;
}
bool Analyze::isOperator(string str) {

	std::regex words_regex("[^\\-\\+\\\\\/\\*\\^\\%]");
	if (regex_tokens(str, words_regex).size() >= 1)
		return false;
	return true;


}
//Core

//vector<string> Analyze::tokenize(string tokens) {
//
//	/* Separate every int or float or operator into a single string using regular expr and store it in token_vector vector */
//	vector<string> token_vector;
//	std::regex words_regex("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\/\\*\\[\\]\\^\\%]");
//	auto words_begin = std::sregex_iterator(tokens.begin(), tokens.end(), words_regex);
//	auto words_end = std::sregex_iterator();
//
//	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
//		token_vector.push_back((*i).str());
//	}
//
//
//	return token_vector;
//}
int Analyze::precedence(string op) {
	if (op == "+" || op == "-") return 1;
	if (op == "*" || op == "/" || op == "%") return 2;
	if (op == "^") return 3;
	return 0;
}

string Analyze::calculate(string a_, string b_, string op) {
	if (isInt(a_) && isInt(b_)) {
		int a = stoi(a_);
		int b = stoi(b_);
		if (op == "+")return to_string(a + b);
		if (op == "-")return to_string(a - b);
		if (op == "%")return to_string(a % b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);
		if (op == "^")return to_string(a ^ b);
	}
	else if (isFloat(a_) && isInt(b_)) {

		int a = stof(a_);
		int b = stoi(b_);
		if (op == "+")return to_string(a + b);
		if (op == "-")return to_string(a - b);
		if (op == "%")return to_string(a % b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);
		if (op == "^")return to_string(a ^ b);
	}
	else if (isInt(a_) && isFloat(b_)) {

		int a = stoi(a_);
		int b = stof(b_);
		if (op == "+")return to_string(a + b);
		if (op == "-")return to_string(a - b);
		if (op == "%")return to_string(a % b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);
		if (op == "^")return to_string(a ^ b);
	}
	else {
		int a = stof(a_);
		int b = stof(b_);
		if (op == "+")return to_string(a + b);
		if (op == "-")return to_string(a - b);
		if (op == "%")return to_string(a % b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);
		if (op == "^")return to_string(a ^ b);

	}


	return 0;
}


int Analyze::infix2postfix(string expr) {
	//Verify expression
	if (isBadWritten(expr) == true) return 0;

	//Print to postfix
	//print2postfix(expr);

	stack<string>numbers;
	stack<string>operators;
	//Obtain tokens from string
	regex words_regex("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\/\\*\\[\\]\\^\\%]");
	vector<string> token_vector = regex_tokens(expr,words_regex);
	

	for (auto i:token_vector)
	{
		//If token is "("
		if (i == "(" || i == "[") {
			operators.push(i);

		}
		//if it's a number
		else if (isInt(i) || isFloat(i)) {
			numbers.push(i);
		}
		//If token is ")"
		else if (i == ")" || i == "]") {
			while (!operators.empty()) {
				if (operators.top() == "(" || operators.top() == "[") break;
				string num2 = numbers.top();
				numbers.pop();
				string num1 = numbers.top();
				numbers.pop();
				string op = operators.top();
				operators.pop();
				numbers.push(calculate(num1, num2, op));

			}
			//Pop the ")"
			operators.pop();

		}
		//if it's an operator
		else {
			while (!operators.empty() && precedence(operators.top()) >= precedence(i)) {
				string num2 = numbers.top();
				numbers.pop();
				string num1 = numbers.top();
				numbers.pop();
				string op = operators.top();
				operators.pop();
				numbers.push(calculate(num1, num2, op));
			}
			operators.push(i);
			//			cout << operators.top() << endl;;
		}


	}

	// Entire expression has been parsed at this 
	// point, apply remaining ops to remaining 
	// values. 
	while (!operators.empty()) {
		string num2 = numbers.top();
		numbers.pop();
		string num1 = numbers.top();
		numbers.pop();
		string op = operators.top();
		operators.pop();
		numbers.push(calculate(num1, num2, op));
	}

	// Top of 'values' contains result, return it. 
	return stoi(numbers.top());


}
//void Analyze::print2postfix(string expr) {
//	vector<string>numbers;
//	vector<string>operators;
//	vector<string> token_vector = tokenize(expr);
//	for (int i = 0; i < token_vector.size(); i++)
//	{
//		if (isOperator(i)) operators.push_back(i);
//		else if (isInt(i) || isFloat(i)) numbers.push_back(i);
//	}
//	cout << "Infijo: " + expr << endl;
//	cout << "Postfijo: ";
//
//}
//







/*
Regex Tutorial

1) If i want to check if the expr has digits (0-9):
[[:digit:]]

2) If i want ot check if the expr has digits that consists of 2 or more digits (like 20 or 500)
[[:digit:]]+

3)
[[:digit:]]+(\\+|-)?

void Analyze::test(string tokens) {
	vector<string> token_vector;
	std::regex words_regex("[[:digit:]]?[[:digit:]]+|[\\+\\-]");
	auto words_begin = std::sregex_iterator(tokens.begin(), tokens.end(), words_regex);
	auto words_end = std::sregex_iterator();


	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		cout << (*i).str() << endl;
		token_vector.push_back((*i).str());
	}

		if (regex_match(tokens, words_regex))
			cout << "is good";
		else
			cout << "is bad";
}

*/