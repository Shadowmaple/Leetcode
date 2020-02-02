# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        if (arr.size() <= 1) return 0;
        vector<int> v(100000, 0);
        for (int num : arr) {
            v[num - 1]++;
        }
        sort(v.begin(), v.end());
        int k = 0, sum = arr.size();
        int num = sum;
        for (int i = v.size()-1; i >= 0; i--) {
            if (!v[i]) continue;
            k++;
            num -= v[i];
            if (num <= sum / 2) break;
        }
        return k;
    }
};