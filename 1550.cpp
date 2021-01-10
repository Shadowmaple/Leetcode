# include <iostream>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int l = 2;
        while (l < arr.size()) {
            if ((arr[l]&1) && (arr[l-1]&1) && (arr[l-2]&1))
                return true;
            l++;
        }
        return false;
    }
};