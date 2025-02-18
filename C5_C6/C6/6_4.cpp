#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

typedef long long ll;

ll findSmallestBDN(int N) {
    queue<ll> q;
    unordered_set<ll> visited;
    q.push(1);
    while (!q.empty()) {
        ll num = q.front();
        q.pop();
        if (num % N == 0) return num;
        if (!visited.count(num * 10)) {
            q.push(num * 10);
            visited.insert(num * 10);
        }
        if (!visited.count(num * 10 + 1)) {
            q.push(num * 10 + 1);
            visited.insert(num * 10 + 1);
        }
    }
    return -1; 
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << findSmallestBDN(N) << endl;
    }
    return 0;
}
