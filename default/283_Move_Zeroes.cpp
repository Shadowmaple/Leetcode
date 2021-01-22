# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = 0;
        for (auto it=nums.begin(); it != nums.end()-1; ) {
            if (*it) {
                it++;
                continue;
            };
            // 删除会自动将将迭代器指向下一个元素
            nums.erase(it);
            n++;
        }
        nums.insert(nums.end(), n, 0);
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        // 双指针，满指针j指向0值
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (!nums[i]) continue;
            swap(nums[i], nums[j++]);
        }
    }
};