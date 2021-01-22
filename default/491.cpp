# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        DFS(nums, 0, cur);
        return res;
    }

    void DFS(vector<int>& nums, int idx, vector<int>& cur) {
        int size = cur.size();
        if (size > 1 && cur[cur.size()-1] < cur[cur.size()-2])
            return ;
        if (size > 1) res.push_back(cur);
        if (idx == nums.size()) return ;

        bool visited[201] = {false};
        for (int i = idx; i < nums.size(); i++) {
            if (visited[nums[i]+100]) continue;
            visited[nums[i]+100] = true;
            cur.push_back(nums[i]);
            DFS(nums, i+1, cur);
            cur.pop_back();
        }
    }
};