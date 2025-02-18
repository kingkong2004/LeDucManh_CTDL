#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(const string& s) {
    stack<int> countStack;
    stack<string> resultStack;
    string result;
    int i = 0;
    
    while (i < s.length()) {
        if (isdigit(s[i])) {
            int count = 0;
            while (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            countStack.push(count);
        } else if (s[i] == '[') {
            resultStack.push(result);
            result = "";
            i++;
        } else if (s[i] == ']') {
            string temp = resultStack.top(); resultStack.pop();
            int count = countStack.top(); countStack.pop();
            for (int j = 0; j < count; j++) {
                temp += result;
            }
            result = temp;
            i++;
        } else {
            result += s[i];
            i++;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << decodeString(s) << endl;
    }
    return 0;
}
