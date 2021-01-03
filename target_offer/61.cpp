# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <set>
using namespace std;

// 优先队列，实质是排序
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        priority_queue<int> q;
        int count = 0;
        for (int num : nums) {
            if (!num) {
                count++;
                continue;
            }
            q.push(num);
        }
        int pre = -1;
        while (!q.empty()) {
            int cur = q.top();
            q.pop();
            if (pre == -1 || cur == pre-1) {
                pre = cur;
                continue;
            }
            int len = cur - pre - 1;
            if (!len || len > count) return false;
            count -= len;
            pre = cur;
        }
        return true;
    }
};

// 索性直接来个排序吧
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int pre;
        for (int num : nums) {
            if (!num) {
                count++;
                continue;
            }
            if (pre == -1 || num == pre+1) {
                pre = num;
                continue;
            } else if (num == pre) return false;
            int len = num - pre - 1;
            if (len > count) return false;
            count -= len;
            pre = num;
        }
        return true;
    }
};

// *神方法* orz
// core: max - min < 5
// set 用于判定重复
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int maxNum = 0, minNum = 13;
        set<int> visited;
        for (int num : nums) {
            if (!num) continue;
            maxNum = max(num, maxNum);
            minNum = min(num, minNum);
            if (visited.count(num)) return false;
            visited.insert(num);
        }
        return maxNum - minNum < 5;
    }
};