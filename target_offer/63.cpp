# include <iostream>
# include <vector>
using namespace std;

// 双指针思想
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0, high = 0;
        int result = 0;
        while (high < prices.size()) {
            result = max(prices[high] - prices[low], result);
            if (prices[low] > prices[high]) {
                low = high;
            }
            high++;
        }
        return result;
    }
};

// 动态规划思想
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT16_MAX;
        int result = 0;
        for (int price : prices) {
            low = min(low, price);
            result = max(result, price-low);
        }
        return result;
    }
};
