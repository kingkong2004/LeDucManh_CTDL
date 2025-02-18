#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string prefixToPostfix(string expression) {
    stack<string> s;
    int length = expression.size();
    
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(expression[i])) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string newExpr = op1 + op2 + expression[i];
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
        cout << prefixToPostfix(expression) << endl;
    }
    return 0;
}
