# include <iostream>
using namespace std;

bool canWin(int *num, int remain) {
    if (!remain) return true;
    if (remain == 14) {
        // 取雀头
        for (int n = 0; n < 9; n++) {
            if (num[n] < 2) continue;
            num[n] -= 2;
            bool win = canWin(num, remain-2);
            num[n] += 2;
            if (win) return true;
        }
        return false;
    }
    // 取刻子
    int n = 0;
    while (n < 9 && num[n] < 3) n++;
    if (n < 9) {
        num[n] -= 3;
        bool win = canWin(num, remain-3);
        num[n] += 3;
        if (win) return true;
    }
    // 取顺子
    n = 2;
    while (n < 9) {
        if (num[n] >= 1 && num[n-1] >= 1 && num[n-2] >= 1) {
            num[n]--;
            num[n-1]--;
            num[n-2]--;
            bool win = canWin(num, remain-3);
            num[n]++;
            num[n-1]++;
            num[n-2]++;
            if (win) return true;
            break;
        }
        n++;
    }
    return false;
}

int main() {
    int num[9] = {0};
    int val;
    for (int i = 0; i < 13; i++) {
        cin >> val;
        num[val-1]++;
    }

    bool flag = false;
    for (int i = 0; i < 9; i++) {
        if (num[i] >= 4) continue;
        num[i]++;
        bool win = canWin(num, 14);
        num[i]--;
        if (win) {
            if (flag) cout << " ";
            cout << i+1;
            flag = true;
        }
    }
    if (!flag) cout << 0 << endl;

    return 0;
}