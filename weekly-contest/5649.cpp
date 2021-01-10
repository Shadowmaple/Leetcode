# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res{first};
        int idx = 0;
        for (auto e : encoded) {
            res.push_back(res[idx++] ^ e);
        }
        return res;
    }
};