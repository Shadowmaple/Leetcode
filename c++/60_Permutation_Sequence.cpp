# include <iostream>
# include <string>
using namespace std;

// 回溯法，效率依旧感人，击败了6%
// 可用数学方法算出第k个处于什么排列下
class Solution {
public:
    string result;
    bool *used;
    string getPermutation(int n, int k) {
        string s, cmb;
        used = new bool[n+1]{};
        backTracing(k, n, cmb);
        return result;
    }

    void backTracing(int& k, int& n, string& cmb) {
        if (cmb.size() == n) {
            k--;
            if (!k) result = cmb;
            return ;
        }

        for (int i = 1; i <= n; i++) {
            if (!k) return ;
            if (used[i]) continue;
            used[i] = true;
            cmb += i + '0';
            backTracing(k, n, cmb);
            cmb.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(4, 6) << endl;
    return 0;
}