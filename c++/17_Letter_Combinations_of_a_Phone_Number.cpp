# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits == "") return v;

        vector<int> sk;
        string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int idx = 0;
        int limit[8] = {3, 3, 3, 3, 3, 4, 3, 4};
        while (1) {
            if (sk.size() == digits.length()) {
                // 获得匹配的串
                string s;
                for (int i = 0; i < digits.length(); i++) {
                    int n = digits[i] - '0' - 2;
                    s += letters[n][sk[i]];
                }
                v.push_back(s);
                s.clear();

                // 回溯
                int i;
                do {
                    idx = sk.at(sk.size()-1) + 1;
                    sk.pop_back();
                    i = digits[sk.size()] - '0' -2;
                } while (idx >= limit[i] && !sk.empty());

                if (sk.empty() && idx >= limit[i]) break;
            }
            sk.push_back(idx);
            idx = 0;
        }

        return v;
    }
};

int main() {
    Solution s;
    vector<string> v = s.letterCombinations("23");
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;
}