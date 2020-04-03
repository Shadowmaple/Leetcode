# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = 1, sum = 9999;
        while (sum > threshold) {
            sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                int x = nums[i] % n;
                sum += (x) ? nums[i]/10+1 : nums[i]/10;
            }
            n++;
        }
        return n;
    }
};

int main() {
    return 0;
}