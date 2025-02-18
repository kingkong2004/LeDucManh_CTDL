#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

set<string> results;
vector<pair<int, int>> brackets;
string expr;

void generate(int index, vector<bool>& removed) {
    if (index == brackets.size()) {
        string temp;
        for (int i = 0; i < expr.size(); i++) {
            if (!removed[i]) temp += expr[i];
        }
        results.insert(temp);
        return;
    }
    
    // Không xóa dấu ngoặc này
    generate(index + 1, removed);
    
    // Xóa cặp dấu ngoặc này
    removed[brackets[index].first] = true;
    removed[brackets[index].second] = true;
    generate(index + 1, removed);
    removed[brackets[index].first] = false;
    removed[brackets[index].second] = false;
}

int main() {
    cin >> expr;
    stack<int> s;
    
    // Xác định các cặp dấu ngoặc
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '(') {
            s.push(i);
        } else if (expr[i] == ')') {
            if (!s.empty()) {
                brackets.push_back({s.top(), i});
                s.pop();
            }
        }
    }
    
    vector<bool> removed(expr.size(), false);
    generate(0, removed);
    
    // In kết quả theo thứ tự từ điển
    for (const string& res : results) {
        if (res != expr) cout << res << endl;
    }
    
    return 0;
}
