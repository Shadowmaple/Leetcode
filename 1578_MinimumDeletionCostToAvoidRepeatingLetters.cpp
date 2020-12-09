# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int count = 0;
        int left = 0, right = 1;
        while (right < s.length()) {
            if (s[right] != s[left]) {
                left++;
                right++;
                continue;
            }
            while (right < s.length() && s[right] == s[left]) right++;

            int maxValueIdx = left;
            for (int i = left+1; i < right; i++) {
                if (cost[maxValueIdx] > cost[i]) {
                    count += cost[i];
                } else {
                    count += cost[maxValueIdx];
                    maxValueIdx = i;
                }
            }
            left = right - 1;
        }
        return count;
    }
};