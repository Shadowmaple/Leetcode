# include <iostream>
# include <vector>
using namespace std;

// 回溯
// 思考，组织代码花了很久，笔试时时间不够不一定能写出来
// 主要麻烦的是数值会溢出，不能用 stoi()
class Solution {
public:
    vector<int> res;
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 0; i < S.length()-2; i++) {
            if (S[0] == '0' && i) return res;
            long a = getNum(S, 0, i+1);
            if (a == -1) break;
            res.push_back(a);
            for (int j = i+1; j < S.length()-1; j++) {
                if (S[i+1] == '0' && j > i+1) break;
                long b = getNum(S, i+1, j-i);
                if (b == -1) continue;
                res.push_back(b);
                if (DFS(S, j+1, a+b)) return res;
                res.pop_back();
            }
            res.pop_back();
        }
        return vector<int>{};
    }

    bool DFS(string& s, int idx, long target) {
        if (idx == s.length()) return true;
        if (s[idx] == '0' && target) return false;
        int num = 1;
        int t = target / 10;
        while (t) {
            num++;
            t /= 10;
        }

        int cur = getNum(s, idx, num);
        if (cur == -1 || cur != target) return false;

        res.push_back(target);
        bool flag = DFS(s, idx+num, target+res[res.size()-2]);
        if (flag) return true;
        res.pop_back();
        return flag;
    }

    int getNum(string& s, int idx, int num) {
        if (num + idx > s.length()) return false;
        long cur = 0;

        while (num--) {
            cur = cur * 10 + (s[idx++] - '0');
            if (cur > INT32_MAX) return -1;
        }

        return cur;
    }
};

int main() {
    string x = "123456579";
    Solution s;
    s.splitIntoFibonacci(x);
    return 0;
}