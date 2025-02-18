#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, steps;
};

int minMoves(vector<string> &grid, int N, int a, int b, int c, int d) {
    vector<vector<int>> visited(N, vector<int>(N, 0));
    queue<Point> q;
    q.push({a, b, 0});
    visited[a][b] = 1;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        Point p = q.front(); q.pop();
        if (p.x == c && p.y == d) return p.steps;
        
        for (int i = 0; i < 4; i++) {
            int nx = p.x, ny = p.y;
            while (nx + dx[i] >= 0 && nx + dx[i] < N && ny + dy[i] >= 0 && ny + dy[i] < N && grid[nx + dx[i]][ny + dy[i]] == '.') {
                nx += dx[i];
                ny += dy[i];
                if (visited[nx][ny]) continue;
                visited[nx][ny] = 1;
                q.push({nx, ny, p.steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> grid(N);
        for (int i = 0; i < N; i++) cin >> grid[i];
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << minMoves(grid, N, a, b, c, d) << endl;
    }
    return 0;
}
