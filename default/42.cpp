# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size == 0) return 0;

        int left[size], right[size];
        left[0] = height[0];
        right[size-1] = height[size-1];
        for (int i = 1, j = size-2; i < size-1; i++, j--) {
            left[i] = max(left[i-1], height[i]);
            right[j] = max(right[j+1], height[j]);
        }
        int sum = 0;
        for (int i = 1; i < size-1; i++) {
            sum += max(0, min(left[i], right[i])-height[i]);
        }
        return sum;
    }
};
