# include <iostream>
# include <vector>
# include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            q.push_back(i);

            if (i - q.front() >= k) q.pop_front();

            if (i >= k-1) result.push_back(nums[q.front()]);
        }
        return result;
    }
};