#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluatePrefix(string expression) {
    stack<int> s;
    int length = expression.size();
    
    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            s.push(expression[i] - '0');
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            
            switch (expression[i]) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
            }
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
        cout << evaluatePrefix(expression) << endl;
    }
    return 0;
}
