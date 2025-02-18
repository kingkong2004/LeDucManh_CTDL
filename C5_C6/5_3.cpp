#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeBrackets(string p) {
    stack<bool> signs;
    signs.push(true); // True đại diện cho dấu dương (+)
    string result;
    
    for (size_t i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            // Kiểm tra dấu ngay trước ngoặc
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
        string P;
        getline(cin, P);
        cout << removeBrackets(P) << endl;
    }
    
    return 0;
}
