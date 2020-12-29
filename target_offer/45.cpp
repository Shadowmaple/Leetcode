# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

// 比较优先级
// 对于 3, 30 从首位挨个比较大小，3的位数不够回到首位比较
struct cmp {
    // 返回true时，a的优先级低于b的优先级（a排在b的后面）
    bool operator() (string a, string b ){
        if (a == b) return true;
        int l = 0, r = 0;
        int maxLen = a.length() + b.length();
        while (maxLen--) {
            if (a[l] != b[r])
                return a[l] > b[r];
            l++;
            r++;
            if (l == a.length()) l = 0;
            if (r == b.length()) r = 0;
        }
        return true;
    }
};

// 优先队列，基数排序的思想
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if (!nums.size()) return "";

        priority_queue<string, vector<string>, cmp> q;
        for (int num : nums) {
            q.push(to_string(num));
        }

        string s;
        while (!q.empty()) {
            s.append(q.top());
            q.pop();
        }

        return s;
    }
};

// 直接排序不就完了？-_-
// 好蠢……
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if (!nums.size()) return "";

        vector<string> v;
        for (int num : nums) {
            v.push_back(to_string(num));
        }

        sort(v.begin(), v.end(), [] (string s1, string s2) {
            return s1 + s2 > s2 + s1;
        });

        string s;
        for (auto x : v) {
            s += x;
        }

        return s;
    }
};