# include <iostream>
# include <set>
using namespace std;

// 太草了，我还用 DFS 回溯去做，结果显然超时了
// 菜是原罪
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() <= k) return false;
        set<string> hash;
        for (int i = 0; i <= s.length()-k; i++) {
            hash.insert(s.substr(i, k));
        }
        return hash.size() == (1 << k);
    }
};