#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long largestRectangle(vector<int>& heights, int n) {
    stack<int> st;
    long long maxArea = 0;
    
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, (long long)height * width);
        }
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> heights(N);
        for (int i = 0; i < N; i++) {
            cin >> heights[i];
        }
        cout << largestRectangle(heights, N) << endl;
    }
    return 0;
}
