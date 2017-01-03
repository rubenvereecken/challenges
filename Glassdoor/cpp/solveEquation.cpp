/*!
 * \file 
 * \brief  solveEquation.cpp
 *
 * \date   Sep 16, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"
#include <stdlib.h>

using namespace std;

map<char, int> precedence ({{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}});

bool isNum(char num) {
	return num == '0' || num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || num == '6'
			|| num == '7' || num == '8' || num == '9' || num == 'x';
};

bool isOp(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
};

int strtol (string a) {
	return std::strtol(a.c_str(), nullptr, 10);
}

bool lowerPrec(char opA, char opB) {
	return precedence[opA] <= precedence[opB];
}

string inToPost(string infix) {
	string post;
	stack<char> S;

	string::iterator s = infix.begin();

	while (s != infix.end()) {
//		cout << post << endl;
		string numSoFar;

		while (isNum(*s)) {
			numSoFar += *s;
			s++;
		}

		if (!numSoFar.empty()) {
			post += " " + numSoFar;
		}
		else if (*s == '(') {
			S.push(*s);
			s++;
		}
		else if (isOp(*s)) {
			if (S.empty()) {
				S.push(*s);
				s++;
			}
			else {
//				if (!S.empty())
//					cout << "S.top: " << S.top() << endl;
				while (!S.empty() && S.top() != '('  && lowerPrec(*s, S.top())) {
					post += S.top();
					S.pop();
				}
				S.push(*s);
				s++;
			}
		}
		else if (*s == '(') {
			S.push(*s);
			s++;
		}
		else if (*s == ')') {
			while (!S.empty()) {
				char top = S.top();
				S.pop();
				if (top == '(')
					break;
				post += top;
			}
			s++;
		}
		else s++;
	}

	while (!S.empty()) {
		post += S.top();
		S.pop();
	}
	return post;
}

int eval(int operand1, int operand2, char op) {
	switch (op) {
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	}
}

int evaluatePost(string post, int replaceX) {
	stack<int> S;

	string::iterator s = post.begin();

	while (s != post.end()) {
		string numSoFar;

		while (isNum(*s)) {
			numSoFar += *s;
			s++;
		}

		if (!numSoFar.empty()) {
			S.push(strtol(numSoFar));
		}
		else if (*s == 'x') {
			S.push(replaceX);
			s++;
		}
		else if (isOp(*s)) {
			int operand2 = S.top();
			S.pop();
			int operand1 = S.top();
			S.pop();
			S.push(eval(operand1, operand2, *s));
			s++;
		}
		else s++;
	}

	return S.top();
}

int findX(string equation) {
	int equationIndex = equation.find("=");
	string left(equation.begin(), equation.begin() + equationIndex);
	string right(equation.begin() + equationIndex + 1, equation.end());

//	cout << "left infix: " << left << endl;
//	cout << "right infix: " << right << endl;

	string leftPost = inToPost(left);
//	cout << "left postfix: " << leftPost << endl;
	string rightPost = inToPost(right);
//	cout << "right postfix: " << rightPost << endl;
	string total = leftPost + " " + rightPost + "-";
//	cout << total << endl;
	int f0 = evaluatePost(total, 0);
	int f1 = evaluatePost(total, 1);
//	cout << "f0 = " << f0 << endl;
//	cout << "f1 = " << f1 << endl;
	if (f0 == f1) {
//		cout << "noooope " << endl;
		return -1;
	}
	else
		return f0 / (f0 - f1);
}
