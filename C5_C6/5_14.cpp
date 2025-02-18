#include <iostream>
#include <stack>
#include <string>

using namespace std;

string findSmallestNumber(string S) {
    string result = "";
    stack<int> st;
    int num = 1;
    
    for (char c : S) {
        st.push(num++);
        if (c == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    st.push(num);
    while (!st.empty()) {
        result += to_string(st.top());
        st.pop();
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string S;
        getline(cin, S);
        cout << findSmallestNumber(S) << endl;
    }
    return 0;
}
