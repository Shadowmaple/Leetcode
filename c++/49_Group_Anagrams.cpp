# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            hashMap[s].push_back(strs[i]);
        }
        for (auto iter=hashMap.begin(); iter!=hashMap.end(); iter++)
            result.push_back(iter->second);

        return result;
    }
};

int main() {
    Solution s;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> g = s.groupAnagrams(strs);
    for (auto iter=g.begin(); iter!=g.end(); iter++) {
        for (auto i=iter->begin(); i!=iter->end(); i++)
            cout << *i << " ";
        cout << endl;
    }
    return 0;
}