#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nearestGreaterFrequency(vector<int>& A, int n) {
    unordered_map<int, int> freq;
    vector<int> ans(n, -1);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        freq[A[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && freq[A[st.top()]] < freq[A[i]]) {
            ans[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        vector<int> result = nearestGreaterFrequency(A, n);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
