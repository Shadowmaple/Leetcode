# include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp[255] = {0};
        bool con[255] = {false};
        int i = s.length()-1, j = t.length()-1;
        while (i >= 0 && j >= 0) {
            int x = s[i], y = t[j];
            if (!mp[x]) {
                if (con[y]) return false;
                mp[x] = y;
                con[y] = true;
            } else if (mp[x] != y)
                return false;
            i--;
            j--;
        }
        return true;
    }
};