# include<iostream>
# include<vector>
# include<numeric>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int dp[len+1][sum/2+1];
        for (int i = 0; i <= len; i++) dp[i][0] = 0;
        for (int j = 0; j <= sum/2; j++) dp[0][j] = 0;

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= sum/2; j++) {
                if (j >= stones[i-1])
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]]+stones[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return sum - 2*dp[len][sum/2];
    }
};

// 一维DP
class Solution2 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int dp[sum/2+1];
        for (int i = 0; i <= sum/2; i++) dp[i] = 0;

        for (int i = 1; i <= len; i++) {
            // j从高递减！！
            for (int j = sum/2; j >= 1; j--) {
                if (j >= stones[i-1])
                    dp[j] = max(dp[j], dp[j-stones[i-1]]+stones[i-1]);
            }
        }
        return sum - 2*dp[sum/2];
    }
};

int main() {
    auto stones = vector<int>{2,7,4,1,8,1};
    Solution s;
    cout << s.lastStoneWeightII(stones) << endl;
    return 0;
}