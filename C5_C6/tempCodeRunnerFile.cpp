#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool hasRedundantParentheses(const string& expression) {
    stack<char> s;
    
    for (char ch : expression) {
        if (ch == ')') {
            bool flag = true;
            while (!s.empty() && s.top() != '(') {
                char top = s.top(); s.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    flag = false;
                }
            }
            
            if (!s.empty()) s.pop(); // Pop the '('
            
            if (flag) {
                return true;
            }
        } else {
            s.push(ch);
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string exp;
        getline(cin, exp);
        cout << (hasRedundantParentheses(exp) ? "Yes" : "No") << endl;
    }
    
    return 0;
}
