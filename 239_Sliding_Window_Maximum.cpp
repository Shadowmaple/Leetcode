# include <iostream>
# include <vector>
# include <queue>
using namespace std;

// 单调栈/单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> v;
        deque<int> window;
        for (int r = 0; r < len; r++) {
            while (!window.empty() && nums[r] >= nums[window.back()])
                window.pop_back();

            window.push_back(r);

            if (r - window.front() + 1 > k)
                window.pop_front();

            if (r >= k-1)
                v.push_back(nums[window.front()]);
        }
        return v;
    }
};