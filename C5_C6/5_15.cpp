#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterRightSmaller(vector<int>& A, int n) {
    vector<int> result(n, -1);
    stack<int> greaterStack;
    
    for (int i = 0; i < n; i++) {
        while (!greaterStack.empty() && A[greaterStack.top()] < A[i]) {
            greaterStack.pop();
        }
        
        if (!greaterStack.empty()) {
            for (int j = greaterStack.top() + 1; j < n; j++) {
                if (A[j] < A[greaterStack.top()]) {
                    result[greaterStack.top()] = A[j];
                    break;
                }
            }
        }
        
        greaterStack.push(i);
    }
    
    return result;
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
        
        vector<int> result = nextGreaterRightSmaller(A, n);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
