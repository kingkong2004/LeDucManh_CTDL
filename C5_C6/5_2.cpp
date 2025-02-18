#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minReversals(string s) {
    int open = 0, close = 0;
    for (char ch : s) {
        if (ch == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << minReversals(s) << endl;
    }
    return 0;
}
