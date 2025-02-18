#include <iostream>
#include <queue>
#include <string>

using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");
    while (n--) {
        string s1 = q.front();
        q.pop();
        cout << s1 << " ";
        q.push(s1 + "0");
        q.push(s1 + "1");
    }
    cout << endl;
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        generateBinaryNumbers(n);
    }
    return 0;
}