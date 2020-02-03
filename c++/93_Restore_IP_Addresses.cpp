# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if (s == "" || s.size() > 12) return v;

        int idx = 0, i = 0, slen = s.length(), len = 1;
        vector<int> sk;
        bool backTrace = false;
        while (1) {
            if (idx == 4 && i == slen) {
                string adr, sub;
                for (int i = 0; i < sk.size(); i += 2) {
                    sub = s.substr(sk[i], sk[i+1]);
                    adr += (i != sk.size()-2) ? sub + '.' : sub;
                }
                v.push_back(adr);
                backTrace = true;
            }
            // 回溯
            while (backTrace || i > slen || idx == 4 && i < slen || len > 3) {
                backTrace = false;
                len = sk[sk.size()-1] + 1;
                i = sk[sk.size()-2];
                sk.pop_back();
                sk.pop_back();
                idx--;
                if (!idx) break;
            }
            if (!idx && len > 3) break;
            if (s[i] == '0' && len > 1 || len == 3 && s.substr(i, len) > "255") {
                if (sk.empty()) break;
                backTrace = true;
                continue;
            }
            sk.push_back(i);
            sk.push_back(len);
            idx++;
            i += len;
            len = 1;
        }
        return v;
    }
};

int main() {
    Solution s;
    vector<string> v = s.restoreIpAddresses("010010");
    for (string x : v)
        cout << x << endl;

    return 0;
}