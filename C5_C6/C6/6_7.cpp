#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

bool isOneCharDiff(const string &a, const string &b) {
    if (a.length() != b.length()) return false;
    int diffCount = 0;
    for (size_t i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            diffCount++;
            if (diffCount > 1) return false;
        }
    }
    return diffCount == 1;
}

int shortestTransformationPath(int n, string s, string t, unordered_set<string> &words) {
    if (s == t) return 1;
    queue<pair<string, int>> q;
    q.push({s, 1});
    words.erase(s);
    
    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();
        
        for (auto it = words.begin(); it != words.end(); ) {
            if (isOneCharDiff(current, *it)) {
                if (*it == t) return steps + 1;
                q.push({*it, steps + 1});
                it = words.erase(it);
            } else {
                ++it;
            }
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        unordered_set<string> words;
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            words.insert(word);
        }
        cout << shortestTransformationPath(n, s, t, words) << endl;
    }
    return 0;
}
