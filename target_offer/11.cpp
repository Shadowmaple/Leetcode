# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size()-1;
        if (numbers[l] < numbers[r]) return numbers[l];
        while (l < r) {
            // 防止溢出
            int mid = l + (r - l) / 2;
            if (numbers[r] > numbers[mid])
                r = mid;
            else if (numbers[r] < numbers[mid])
                l = mid + 1;
            else r--;
        }
        return numbers[l];
    }
};