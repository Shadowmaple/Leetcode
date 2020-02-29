# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bool> hash(150, false);
        string s;
        return DFS(arr, 0, hash, s);
    }

    int DFS(vector<string>& arr, int idx, vector<bool> hash, string s) {
        if (idx >= arr.size())
            return s.length();

        int max = s.length();
        for (int i = idx; i < arr.size(); i++) {
            bool flag = false;
            vector<bool> curHash(hash);
            for (char c : arr[i]) {
                if (curHash[c-'0']) {
                    flag = true;
                    break;
                }
                curHash[c-'0'] = true;
            }
            if (flag) continue;

            string curStr = s + arr[i];
            int len = DFS(arr, i+1, curHash, curStr);
            if (len > max) max = len;
        }
        return max;
    }
};