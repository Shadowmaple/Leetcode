# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        if (!words.size()) return vector<string>{};
        int hash[26] = {1,0,0,1,2,1,1,1,2,1,1,1,0,0,2,2,2,2,1,2,2,0,2,0,2,0};
        vector<string> res;
        for (auto word : words) {
            int line = word[0]<'a'? hash[word[0]+32-'a']:hash[word[0]-'a'];
            bool flag = true;
            for (auto c : word) {
                int num = c < 'a' ? hash[c+32-'a']:hash[c-'a'];
                if (num != line) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        return res;
    }
};