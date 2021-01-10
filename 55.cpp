# include <iostream>
# include <vector>
using namespace std;

// 用DFS回溯超时了
// 我是S*
// 贪心算法
// 其它思路还有DP、BFS（当然也超时）
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (jump < i) return false;
            jump = max(jump, i + nums[i]);
        }
        return true;
    }
};