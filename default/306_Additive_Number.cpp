# include <iostream>
# include <vector>
# include <string>
using namespace std;

// 需要再次练习、思索
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        vector<long double> cmb; //要足够大，汗～
        return backTracking(num, cmb);
    }

    bool backTracking(string num, vector<long double>& cmb) {
        int len = cmb.size();
        if (len >= 3 && cmb[len-3] + cmb[len-2] != cmb[len-1])
            return false;
        if (!num.length() && len >= 3) return true;

        for (int i = 0; i < num.length(); i++) {
            string s = num.substr(0, i+1);
            if (s[0] == '0' && i) continue; //排除首位为0
            cmb.push_back(stold(s));
            if (backTracking(num.substr(i+1), cmb)) return true;
            cmb.pop_back();
        }
        return false;
    }
};