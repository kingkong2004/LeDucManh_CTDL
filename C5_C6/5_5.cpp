#include <iostream>
#include <stack>
#include <string>
using namespace std;

string normalize(string p) {
    stack<bool> signs;
    signs.push(true);
    string result;
    
    for (size_t i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            if (i > 0 && p[i - 1] == '-') {
                signs.push(!signs.top());
            } else {
                signs.push(signs.top());
            }
        } else if (p[i] == ')') {
            signs.pop();
        } else if (p[i] == '+' || p[i] == '-') {
            if (signs.top()) {
                result += p[i];
            } else {
                result += (p[i] == '+' ? '-' : '+');
            }
        } else {
            result += p[i];
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string P1, P2;
        getline(cin, P1);
        getline(cin, P2);
        
        cout << (normalize(P1) == normalize(P2) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
