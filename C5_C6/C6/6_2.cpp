#include <iostream>
#include <queue>
#include <string>

using namespace std;

string findSmallestMultiple(int N) {
    queue<string> q;
    q.push("9");
    while (!q.empty()) {
        string num = q.front();
        q.pop();
        if (stoll(num) % N == 0) {
            return num;
        }
        q.push(num + "0");
        q.push(num + "9");
    }
    return "";
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << findSmallestMultiple(N) << endl;
    }
    return 0;
}