# include <iostream>
# include <vector>
# include <map>
using namespace std;

// dp 会有溢出错误，输出后发现很多值是用不到的，比如dp[10],dp[20]...
// 所以可以直接自顶向下递归+记忆化
// 可能就cpp会有溢出问题，看评论其他语言不会有溢出问题，这道题就难在递推公式，自己在草稿纸上写着找规律推出来的
class Solution1 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target+1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            dp[i] = 0;
            for (int num : nums) {
                if (num > i) continue;
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};

// 递归+记忆化
class Solution {
public:
    map<int, int> tables;
    int combinationSum4(vector<int>& nums, int target) {
        tables[0] = 1;
        int res = 0;
        for (int num : nums) {
            if (num > target) continue;
            int temp = target - num;
            if (tables.find(temp) == tables.end())
                tables[temp] = combinationSum4(nums, temp);

            res += tables[temp];
        }
        tables[target] = res;
        return res;
    }
};

int main() {
    auto nums = vector<int>{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    Solution s;
    cout << s.combinationSum4(nums, 999) << endl;
    return 0;
}