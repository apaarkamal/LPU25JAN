#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
	        || ch == '^');
}

int precendence(char ch) {
	if (ch == '^') return 3;
	if (ch == '*' || ch == '/') return 2;
	if (ch == '+' || ch == '-') return 1;
	return -1;
}


string convertInfixToPostfix(string infix) {
	string postfix = "";
	// operator stack
	stack<char> St;
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') {
			St.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!St.empty() && St.top() != '(') {
				postfix += St.top();
				St.pop();
			}
			St.pop();
		}
		else if (isOperator(infix[i])) {
			while (!St.empty()
			        && precendence(St.top()) >= precendence(infix[i])) {
				postfix += St.top();
				St.pop();
			}
			St.push(infix[i]);
		}
		else {
			// operand
			postfix += infix[i];
		}
	}
	// operators left
	while (!St.empty()) {
		postfix += St.top();
		St.pop();
	}
	return postfix;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;


	cout << convertInfixToPostfix(s);

}