# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, max = 0;
        while (l < r) {
            int h = height[l] <= height[r] ? height[l] : height[r];
            int cur = (r - l) * h;
            max = max >= cur ? max : cur;
            if (height[l] < height[r]) l++;
            else r--;
        }
        return max;
    }
};