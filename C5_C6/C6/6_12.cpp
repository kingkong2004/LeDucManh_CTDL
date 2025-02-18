#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> generateLocPhat(int N) {
    vector<string> result;
    queue<string> q;
    q.push("6");
    q.push("8");
    
    while (!q.empty()) {
        string num = q.front();
        q.pop();
        if (num.length() > N) break;
        result.push_back(num);
        q.push(num + "6");
        q.push(num + "8");
    }
    sort(result.rbegin(), result.rend());
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> locPhatNumbers = generateLocPhat(N);
        for (const string &num : locPhatNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
