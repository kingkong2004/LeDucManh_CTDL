#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string postfixToPrefix(string expression) {
    stack<string> s;
    int length = expression.size();
    
    for (int i = 0; i < length; i++) {
        if (isOperator(expression[i])) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string newExpr = expression[i] + op1 + op2;
            s.push(newExpr);
        } else {
            s.push(string(1, expression[i]));
        }
    }
    
    return s.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string expression;
        getline(cin, expression);
        cout << postfixToPrefix(expression) << endl;
    }
    return 0;
}
