# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if (!n) {
            v.push_back("");
            return v;
        }

        vector<char> sk;
        char ch[] = {'(', ')'};
        int left = n, right = n;
        char cur = '(';
        while (1) {
            if (!left && !right) {
                // 获取匹配串
                string s;
                for (int i = 0; i < sk.size(); i++)
                    s += sk.at(i);
                if (s[s.length()-1] != '(' && isValid(s))
                    v.push_back(s);
                s.clear();

                // 回溯
                do {
                    cur = sk.at(sk.size()-1);
                    sk.pop_back();
                    if (cur == '(') left++;
                    else right++;
                } while (cur == ')' && !sk.empty() || !right);

                if (sk.empty()) break;
                cur = ')';
                right--;
                sk.push_back(cur);
                continue;
            }
            if (left) {
                cur = '(';
                left--;
            } else {
                cur = ')';
                right--;
            }
            sk.push_back(cur);
        }
        return v;
    }

    bool isValid(string s) {
        int num = 0;
        for (char c : s) {
            if (c == '(') num++;
            else num--;
            if (num < 0) return false;
        }
        return true;
    }
};

// 递归回溯，值得体会
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        backTrace(v, "", n, n);
        return v;
    }

    void backTrace(vector<string> &v, string s, int left, int right) {
        if (!left && !right) {
            v.push_back(s);
            return ;
        }

        if (left)
            backTrace(v, s+'(', left-1, right);
        if (right > left)
            backTrace(v, s+')', left, right-1);
    }
};

int main() {
    Solution s;
    vector<string> v = s.generateParenthesis(3);
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;
}