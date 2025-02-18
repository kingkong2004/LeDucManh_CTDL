#include <iostream>
#include <queue>
#include <string>

using namespace std;

long long countBDN(long long n) {
    queue<long long> q;
    q.push(1);
    long long count = 0;
    while (!q.empty()) {
        long long num = q.front();
        q.pop();
        if (num >= n) break;
        count++;
        q.push(num * 10);
        q.push(num * 10 + 1);
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << countBDN(n) << endl;
    }
    return 0;
}