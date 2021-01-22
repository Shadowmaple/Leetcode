# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size()-1, left = 0;
        // 要考虑负数，所以不能用下面这个
        // while (numbers[right] >= target) right--;
        vector<int> v;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) break;
            else if (sum < target) left++;
            else right--;
        }
        v.push_back(left+1);
        v.push_back(right+1);
        return v;
    }
};