#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result;
    
    for (char ch : exp) {
        if (isalnum(ch)) {
            result += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string exp;
        getline(cin, exp);
        cout << infixToPostfix(exp) << endl;
    }
    
    return 0;
}
