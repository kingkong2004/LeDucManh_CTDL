#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Position {
    int x, y, steps;
};

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int minKnightMoves(string start, string end) {
    if (start == end) return 0;
    
    int sx = start[0] - 'a', sy = start[1] - '1';
    int ex = end[0] - 'a', ey = end[1] - '1';
    
    queue<Position> q;
    q.push({sx, sy, 0});
    bool visited[8][8] = {};
    visited[sx][sy] = true;
    
    while (!q.empty()) {
        Position cur = q.front(); q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny]) {
                if (nx == ex && ny == ey) return cur.steps + 1;
                q.push({nx, ny, cur.steps + 1});
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string start, end;
        cin >> start >> end;
        cout << minKnightMoves(start, end) << endl;
    }
    return 0;
}