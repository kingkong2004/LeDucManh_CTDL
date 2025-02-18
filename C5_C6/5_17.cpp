#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string S) {
    stack<int> st;
    int maxLength = 0, lastInvalid = -1;
    
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    maxLength = max(maxLength, i - lastInvalid);
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            } else {
                lastInvalid = i;
            }
        }
    }
    
    return maxLength;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << longestValidParentheses(S) << endl;
    }
    return 0;
}
