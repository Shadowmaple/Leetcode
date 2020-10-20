# include <iostream>
# include <string>
# include <map>
# include <set>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp, need;
		int l = 0, r = 0;
		int xl = -1, xlen = INT32_MAX; // 记录结果
		int len = s.length();
		for (char c : t ) {
			need[c]++;
			mp[c]++;
		}

		for (; r < len; r++) {
			if (need[s[r]] == 0) continue;
			mp[s[r]]--;

			while (l <= r) {
				// 是否形成目标串
				bool finish = true;
				for (auto it=mp.begin(); it != mp.end(); it++) {
					if (it->second > 0) {
						finish = false;
						break;
					}
				}
				if (!finish) break;

				if (xlen > r - l + 1) {
					xl = l;
					xlen = r - l +1;
				}

				mp[s[l]]++;
				while (++l <= r && need[s[l]] == 0) ;
			}
		}

		return xl == -1 ? "" : s.substr(xl, xlen);
    }
};
