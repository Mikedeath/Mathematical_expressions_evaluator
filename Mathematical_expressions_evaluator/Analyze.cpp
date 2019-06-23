#include "Analyze.h"



Analyze::Analyze()
{
}
Analyze::~Analyze()
{
}

//Verifications

vector<string> Analyze::regex_tokens(string expr, regex words_regex_) { //Feature Regex and regex iterator (C++11)
	vector<string>tokens;
	regex words_regex = words_regex_;
	auto words_begin = sregex_iterator(expr.begin(), expr.end(), words_regex);
	auto words_end = sregex_iterator();
	
	for (sregex_iterator i = words_begin; i != words_end; ++i) {
		tokens.push_back((*i).str());
	}
	return tokens;
}
//feature
vector<any> reg2(string expr, regex words_regex_) {//Feature <Any> (C++17)
	vector<any>tokens;
	regex words_regex = words_regex_;
	auto words_begin = sregex_iterator(expr.begin(), expr.end(), words_regex);
	auto words_end = sregex_iterator();

	for (sregex_iterator i = words_begin; i != words_end; ++i) {
		tokens.push_back((*i).str());
	}
	return tokens;
}

bool Analyze::hasBadChars(string expr) {
	regex words_regex("[^0-9?(0-9*.)?0-9+\\-\\+\\\\\(\\)\\/\\[\\]\\*\\^\\%]");
	const int x = 1;
	decltype(auto) x1 = x; // feature decltype auto (C++14)
	if (regex_tokens(expr, words_regex).size() >= x1)
		return 1;
	return 0;

}
bool Analyze::hasOperatorAtStart(string expr) {
	if (isdigit(expr[0]) || expr[0] == '(' || expr[0] == ')' || expr[0] == '[' || expr[0] == ']')
		return false;
	return true;
}
bool Analyze::hasOperatorAtEnd(string expr) {

	if (isdigit(expr[expr.length() - 1]) || expr[expr.length() - 1] == '(' || expr[expr.length() - 1] == ')' || expr[expr.length() - 1] == '[' || expr[expr.length() - 1] == ']')
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
		//Si no es  un digito y el siguente no es parenteiss
		if (!isdigit(expr[i]) && expr[i + 1] != '(' && expr[i + 1] != ')' && expr[i + 1] != '[' && expr[i + 1] != ']' && expr[i + 1] != NULL) {
			//si no es un digito y es un parentesis y el siguiente no es un parentesis
			if (expr[i] == '(' &&
				expr[i + 1] != '('
				&& expr[i + 1] != ')'
				&& expr[i + 1] != '['
				&& expr[i + 1] != ']'
				|| expr[i] == '('
				&& expr[i + 1] != '('
				&& expr[i + 1] != ')'
				&& expr[i + 1] != '['
				&& expr[i + 1] != ']'
				|| expr[i] == ')'
				&& expr[i + 1] != '('
				&& expr[i + 1] != ')'
				&& expr[i + 1] != '['
				&& expr[i + 1] != ']'
				|| expr[i] == '['
				&& expr[i + 1] != '('
				&& expr[i + 1] != ')'
				&& expr[i + 1] != '['
				&& expr[i + 1] != ']'
				|| expr[i] == ']'
				&& expr[i + 1] != '('
				&& expr[i + 1] != ')'
				&& expr[i + 1] != '['
				&& expr[i + 1] != ']'
				) {
				//  el tercero no es un digito
				/*if (isdigit(expr[i + 2])) {
					continue;
				}
				else {

				}*/
				continue;
			}
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
			if (bad == true)
				cout << "Error: La expression tiene un operador al inicio" << endl;
			break;
		case 1:
			bad = hasBadChars(expr);
			if (bad == true)
				cout << "Error: La expression tiene caracteres invalidos" << endl;
			break;
		case 2:
			bad = hasOpenedBracket(expr);
			if (bad == true)
				cout << "Error: La expression tiene algun bracket abierto" << endl;
			break;
		case 3:
			bad = hasOpenedParentesis(expr);
			if (bad == true)
				cout << "Error: La expression tiene algun parentesisis abierto " << endl;
			break;
		case 4:
			bad = hasOperator_AfterOperator(expr);
			if (bad == true)
				cout << "Error: La expression tiene operadores seguidos uno del otro" << endl;
			break;
		case 5:
			bad = hasOperatorAtEnd(expr);
			if (bad == true)
				cout << "Error: La expression tiene un operador al final" << endl;
			break;
		}
		i++;
	} while (bad == false && i <= 5);

	if (bad == true) {

		return true;
	}
	return false;
}

bool Analyze::isInt(string str) {

	std::regex words_regex("[^0-9]");
	if (reg2(str, words_regex).size() >= 1)
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

auto product = [](int x, int y)constexpr// Feature constexpr (C++17)
{
	return (x * y);
};

auto sum = [](auto a, auto b) {//Feature Return type deduction and lambda generic expression (C++14)  Feature Auto (C++11)
	return a + b;
};

auto calc = [](auto a, auto b, auto op) {

	if (op == "+")return to_string(sum(a, b));
	if (op == "-")return to_string(a - b);
	if (op == "%")return to_string(a % b);
	if (op == "*")return to_string(product(a, b));
	if (op == "/")return to_string(a / b);
	if (op == "^")return to_string((int)pow(static_cast<int>(a), static_cast<int>(b)));
};


string Analyze::calculate(string a_, string b_, string op) {
	

	if (isInt(a_) && isInt(b_)) {//Both are int
		
		int a = stoi(a_);
		int b = stoi(b_);
	
		return calc(a, b, op);
	}
	else if (isFloat(a_) && isInt(b_)) {// A is float and B is int
		float a = stof(a_);
		int b = stoi(b_);

		if (op == "^")return to_string(pow(static_cast<float>(a), b));
		if (op == "+")return to_string(sum(a, b));
		if (op == "-")return to_string(a - b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);
		
		if (op == "%") {
			int a = stoi(a_);
			return to_string(a % b);
		}

	}
	else if (isInt(a_) && isFloat(b_)) {// A is int and B is Float
		int a = stoi(a_);
		float b = stof(b_);

		if (op == "^")return to_string(pow(static_cast<int>(a), static_cast<float>(b)));
		if (op == "+")return to_string(apply(sum,make_tuple(a, b))); //feature Apply (C++17), make_tuple(C++11)
		if (op == "-")return to_string(a - b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);

		if (op == "%") {
			int b = stoi(b_);
			return to_string(a % b);
		}

	}
	else {//Both are float
		float a = stof(a_);
		float b = stof(b_);
	
		if (op == "^")return to_string(pow(static_cast<float>(a), static_cast<float>(b)));
		if (op == "+")return to_string(sum(a, b));
		if (op == "-")return to_string(a - b);
		if (op == "*")return to_string(a * b);
		if (op == "/")return to_string(a / b);

		if (op == "%") {
			int a = stoi(a_);
			int b = stoi(b_);
			return to_string(a % b);
		}
		
	}

	return "0";
}
void asserts() {
	static_assert (2+3 == 5, "Assertion failed");
}

string Analyze::test_infix2postfix(string expr) {

	stack<string>numbers;
	stack<string>operators;
	//Obtain tokens from string
	regex words_regex("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\/\\*\\[\\]\\^\\%]");
	vector<string> token_vector = regex_tokens(expr, words_regex);

	string ln = "";

	for (auto i : token_vector)
	{
		//If token is "("
		if (i == "(" || i == "[") {
			operators.push(i);
		}
		//if it's a number
		else if (isInt(i) || isFloat(i)) {
			numbers.push(i);
			ln += i + ',';
		}
		//If token is ")"
		else if (i == ")" || i == "]") {
			while (!operators.empty()) {
				//si el top del stack de operadores es el parentesis o bracket, significa que ya no hay nada mas que evaluar dentro de ello
				if (operators.top() == "(" || operators.top() == "[") break;
				string num2 = numbers.top();
				numbers.pop();
				string num1 = numbers.top();
				numbers.pop();
				string op = operators.top();
				operators.pop();
				ln += op + ',';

				numbers.push(calculate(num1, num2, op));
			}
			//Pop el ")"
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
				ln += op + ',';
				numbers.push(calculate(num1, num2, op));
			}
			operators.push(i);

		}


	}
	//Lo que queda
	while (!operators.empty()) {
		string num2 = numbers.top();
		numbers.pop();
		string num1 = numbers.top();
		numbers.pop();
		string op = operators.top();
		operators.pop();
		ln += op + ',';
		numbers.push(calculate(num1, num2, op));
	}

	// Top of 'values' contains result, return it.
	//Print to infix
	cout << "Postfijo: ";
	cout << ln.erase(ln.size() - 0b1) << endl;
	cout << "Respuesta: ";
	cout << numbers.top();

	return numbers.top();

}

void Analyze::infix2postfix(string expr) {
	//Verify if expression meets the requirements
	if (auto verify=isBadWritten(expr)) return; //Feature if scoped variable (C++17)

	//Stacks that will hold the numbers and operators from expression
	stack<string>numbers;
	stack<string>operators;

	//Send the number pattern to be detected and fill a vector with the tokens found
	regex words_regex("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\/\\*\\[\\]\\^\\%]");
	vector<string> token_vector = regex_tokens(expr, words_regex);

	//String that will hold the postfix expression
	string ln = "";

	for (auto i : token_vector) // Feature ranged based loops (C++11)
	{
		//If token is "("
		if (i == "(" || i == "[") {
			operators.push(i);
		}
		//if it's a number
		else if (isInt(i) || isFloat(i)) {
			numbers.push(i);
			ln += i + ','; //Fill string 
		}
		//If token is ")"
		else if (i == ")" || i == "]") {
			while (!operators.empty()) { //loop until it reaches the open parenthesis
				if (operators.top() == "(" || operators.top() == "[") break;
				//Get 2 numbers out and an operator to evaluate
				string num2 = numbers.top();
				numbers.pop();
				string num1 = numbers.top();
				numbers.pop();
				string op = operators.top();
				operators.pop();
				ln += op + ',';
				//Push the evaluated expression to the stack of numbers
				numbers.push(calculate(num1, num2, op));
			}
			//Since we have reached an open parenthesis, and we dont need it anymore, lets pop it from the operators stack
			operators.pop();
		}
		//if it's an operator
		else {//If the precedence of the new operator is greater or equal to the first operator from the stack
			while (!operators.empty() && precedence(operators.top()) >= precedence(i)) {
				//Get 2 numbers out and an operator to evaluate
				string num2 = numbers.top();
				numbers.pop();
				string num1 = numbers.top();
				numbers.pop();
				string op = operators.top();
				operators.pop();
				ln += op + ',';
				numbers.push(calculate(num1, num2, op));
			}
			//Just push the new operator if its precedence is lower than the top
			operators.push(i);

		}


	}//For loop end
	
	//At this point the expression is completely parsed, just keep popping, evaluating and pushing until the operator stack is empty
	while (!operators.empty()) {
		string num2 = numbers.top();
		numbers.pop();
		string num1 = numbers.top();
		numbers.pop();
		string op = operators.top();
		operators.pop();
		ln += op + ',';
		numbers.push(calculate(num1, num2, op));
	}
	//The numbers stack contains the result in top

	//Print answer 
	cout << "Postfijo: ";
	//Erase the ',' ath the end of the string
	cout << ln.erase(ln.size() - 0b1) << endl;//Feature binary literals (C++14)
	cout << "Respuesta: ";
	cout << numbers.top();

}



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