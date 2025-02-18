#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> generateLuckyNumbers(int N) {
    queue<string> q;
    vector<string> result;
    
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
    
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> luckyNumbers = generateLuckyNumbers(N);
        
        cout << luckyNumbers.size() << endl;
        for (const string &num : luckyNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
