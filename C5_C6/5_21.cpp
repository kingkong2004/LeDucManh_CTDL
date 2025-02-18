#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int maxValidSubstringSum(const string& P) {
    stack<int> st;
    int maxSum = 0;
    vector<int> dp(P.length(), 0);

    for (int i = 0; i < P.length(); i++) {
        if (P[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int openIndex = st.top();
                st.pop();
                dp[i] = (openIndex > 0 ? dp[openIndex - 1] : 0) + (i - openIndex + 1);
                maxSum += dp[i];
            }
        }
    }
    
    return maxSum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string P;
        cin >> P;
        cout << maxValidSubstringSum(P) << endl;
    }
    return 0;
}
