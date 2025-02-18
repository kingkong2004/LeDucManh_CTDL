#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int x, y, steps;
};

int minStepsToDestination(vector<vector<int>> &A, int M, int N) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Cell> q;
    q.push({0, 0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        Cell current = q.front(); q.pop();
        int x = current.x, y = current.y, steps = current.steps;
        if (x == M - 1 && y == N - 1) return steps;
        
        int jump = A[x][y];
        if (y + jump < N && !visited[x][y + jump]) {
            q.push({x, y + jump, steps + 1});
            visited[x][y + jump] = true;
        }
        if (x + jump < M && !visited[x + jump][y]) {
            q.push({x + jump, y, steps + 1});
            visited[x + jump][y] = true;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<vector<int>> A(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        cout << minStepsToDestination(A, M, N) << endl;
    }
    return 0;
}