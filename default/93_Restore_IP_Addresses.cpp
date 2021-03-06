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

// 递归回溯
class Solution2 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if (s == "" || s.size() > 12) return v;

        backTrace(v, s, "", 0, 1);
        return v;
    }

    void backTrace(vector<string>& v, string s, string adr, int idx, int len) {
        if (idx == 4 && s == "") {
            adr = adr.substr(0, adr.length()-1);
            v.push_back(adr);
            return ;
        } else if (idx == 4)
            return ;

        while (len <= 3 && len <= s.length()) {
            string sub = s.substr(0, len);
            if (len == 3 && sub > "255" || len > 1 && sub[0] == '0') {
                len++;
                continue;
            }
            backTrace(v, s.substr(len), adr+sub+'.', idx+1, 1);
            len++;
        }
    }
};

int main() {
    Solution2 s;
    vector<string> v = s.restoreIpAddresses("25525510135");
    for (string x : v)
        cout << x << endl;

    return 0;
}