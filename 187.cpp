# include <iostream>
# include <map>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10) return vector<string>{};
        vector<string> res;
        map<string, int> mp;
        int l = 0;
        while (l < s.length()-9) {
            mp[s.substr(l, 10)]++;
            l++;
        }
        for (auto lt : mp) {
            if (lt.second > 1) res.push_back(lt.first);
        }

        return res;
    }
};