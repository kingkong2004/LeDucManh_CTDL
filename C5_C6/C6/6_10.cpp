#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int x, y, days;
};

int minDaysToGrow(vector<vector<int>> &grid, int R, int C) {
    queue<Cell> q;
    int totalSeeds = 0, grownSeeds = 0, days = 0;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 2) q.push({i, j, 0});
            if (grid[i][j] > 0) totalSeeds++;
        }
    }
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        Cell cell = q.front(); q.pop();
        grownSeeds++;
        days = max(days, cell.days);
        
        for (int i = 0; i < 4; i++) {
            int nx = cell.x + dx[i];
            int ny = cell.y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                q.push({nx, ny, cell.days + 1});
            }
        }
    }
    
    return (grownSeeds == totalSeeds) ? days : -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }
        cout << minDaysToGrow(grid, R, C) << endl;
    }
    return 0;
}
