# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 插入首部
        if (intervals.size() == 0 || intervals[0][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        } else if (intervals[intervals.size()-1][1] < newInterval[0]) {
            // 插入尾部
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> res;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 中间插入，无合并
        if (intervals[i][0] > newInterval[1]) {
            res.push_back(newInterval);
        } else {
            // 有合并
            int l = min(newInterval[0], intervals[i][0]);
            int r = max(newInterval[1], intervals[i][1]);
            i++;
            while (i < intervals.size() && intervals[i][0] <= r) {
                r = max(intervals[i][1], r);
                i++;
            }
            res.push_back(vector<int>{l, r});
        }

        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};