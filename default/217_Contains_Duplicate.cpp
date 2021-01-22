# include <iostream>
# include <vector>
# include <map>
# include <set>
# include <algorithm>
using namespace std;

// map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> visited;

        for (int n : nums) {
            if (!visited[n]) return true;
            visited[n] = true;
        }
        return false;
    }
};

// 集合，比较数量
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

// 排序，相邻是否相同
class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i-1]) return true;
        return false;
    }
};