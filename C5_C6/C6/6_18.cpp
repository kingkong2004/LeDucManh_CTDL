#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Board {
    string state;
    int moves;
};

string rotateLeft(string s) {
    return {s[3], s[0], s[2], s[4], s[1], s[5]};
}

string rotateRight(string s) {
    return {s[0], s[4], s[1], s[3], s[5], s[2]};
}

int minMoves(string start, string goal) {
    if (start == goal) return 0;
    
    queue<Board> q;
    unordered_map<string, bool> visited;
    
    q.push({start, 0});
    visited[start] = true;
    
    while (!q.empty()) {
        Board current = q.front(); q.pop();
        
        string leftRot = rotateLeft(current.state);
        string rightRot = rotateRight(current.state);
        
        if (leftRot == goal || rightRot == goal) return current.moves + 1;
        
        if (!visited[leftRot]) {
            q.push({leftRot, current.moves + 1});
            visited[leftRot] = true;
        }
        if (!visited[rightRot]) {
            q.push({rightRot, current.moves + 1});
            visited[rightRot] = true;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string start = "", goal = "", temp;
        for (int i = 0; i < 6; i++) {
            cin >> temp;
            start += temp;
        }
        for (int i = 0; i < 6; i++) {
            cin >> temp;
            goal += temp;
        }
        cout << minMoves(start, goal) << endl;
    }
    return 0;
}