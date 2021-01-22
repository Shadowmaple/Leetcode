# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool hash[128] = {false};
        int count = 0;
        for (char c : allowed) hash[c] = true;
        for (auto word : words) {
            bool flag = true;
            for (char c : word) {
                if (!hash[c]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
        return count;
    }
};