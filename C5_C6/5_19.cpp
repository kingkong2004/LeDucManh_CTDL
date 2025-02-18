#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> stockSpan(vector<int>& prices, int n) {
    vector<int> span(n, 1);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
    
    return span;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        vector<int> result = stockSpan(prices, n);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
