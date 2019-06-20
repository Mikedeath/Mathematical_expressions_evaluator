#include "Analyze.h"

int main() {

	Analyze A;
	string infijo;

	do{
	cout << "Ingrese la expresion infija" << endl;
	cin >> infijo; 
	A.infix2postfix(infijo);
	cout << endl;

	system("pause");
	system("CLS");
	} while (true);

	return 0;


}