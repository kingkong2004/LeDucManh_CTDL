#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int minOperationsToOne(int N) {
    queue<int> q;
    unordered_map<int, int> steps;
    
    q.push(N);
    steps[N] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr == 1) return steps[curr];
        
        if (steps.find(curr - 1) == steps.end()) {
            steps[curr - 1] = steps[curr] + 1;
            q.push(curr - 1);
        }
        
        for (int i = 2; i * i <= curr; ++i) {
            if (curr % i == 0) {
                int next = max(i, curr / i);
                if (steps.find(next) == steps.end()) {
                    steps[next] = steps[curr] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << minOperationsToOne(N) << endl;
    }
    return 0;
}
