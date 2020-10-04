# include <iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int len = nums.size() / 2;
        for (int num : nums) {
            mp[num]++;

            if (mp[num] > len) return num;
        }
        return 0;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int maj, count = 0;
        for (int num : nums) {
            if (maj == num) {
                count++;
                continue;
            }
            count--;
            if (count <= 0) {
                maj = num;
                count = 1;
            }
        }
        return maj;
    }
};