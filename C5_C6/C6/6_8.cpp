#include <iostream>

using namespace std;

bool isValid(int num) {
    bool digits[6] = {false};
    while (num > 0) {
        int d = num % 10;
        if (d > 5 || digits[d]) return false;
        digits[d] = true;
        num /= 10;
    }
    return true;
}

int countValidNumbers(int L, int R) {
    int count = 0;
    for (int i = L; i <= R; i++) {
        if (isValid(i)) count++;
    }
    return count;
}

int main() {
    int T, L, R;
    cin >> T;
    while (T--) {
        cin >> L >> R;
        cout << countValidNumbers(L, R) << endl;
    }
    return 0;
}
