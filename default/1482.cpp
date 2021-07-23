# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int len = bloomDay.size();
        if (len < m * k) return -1;
        vector<int> temps(bloomDay);
        sort(temps.begin(), temps.end());
        int l = temps[0], r = temps[len-1];
        while (l <= r) {
            int mid = l + (r-l)/2;
            int day = temps[mid];
            if (tryDay(bloomDay, m, k, day)) r = mid - 1;
            else l = mid + 1;
        }
        return temps[l];
    }

    bool tryDay(vector<int>& bloomDay, int m, int k, int day) {
        int cur = 0;
        for (int d : bloomDay) {
            if (d > day) {
                cur = 0;
                continue;
            }
            cur++;
            if (cur == k) {
                m--;
                if (m == 0) return true;
                cur = 0;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    auto bloomDay = vector<int>{1,10,3,10,2};
    cout << s.minDays(bloomDay, 3, 1) << endl;
    return 0;
}