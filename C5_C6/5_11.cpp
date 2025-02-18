#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;
    int length = expression.size();
    
    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            s.push(expression[i] - '0');
        } else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            
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
        cout << evaluatePostfix(expression) << endl;
    }
    return 0;
}
