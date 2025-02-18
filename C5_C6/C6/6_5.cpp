#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int minOperations(int S, int T) {
    queue<pair<int, int>> q;
    unordered_map<int, bool> visited;
    q.push({S, 0});
    visited[S] = true;

    while (!q.empty()) {
        int curr = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if (curr == T) return steps;
        
        if (curr * 2 <= 10000 && !visited[curr * 2]) {
            q.push({curr * 2, steps + 1});
            visited[curr * 2] = true;
        }
        if (curr - 1 > 0 && !visited[curr - 1]) {
            q.push({curr - 1, steps + 1});
            visited[curr - 1] = true;
        }
    }
    return -1;
}

int main() {
    int T, S, T_target;
    cin >> T;
    while (T--) {
        cin >> S >> T_target;
        cout << minOperations(S, T_target) << endl;
    }
    return 0;
}