# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur, pre;
        cur.push_back(1);

        for (int i=1; i <= rowIndex; i++) {
            pre = cur;
            cur.clear();
            for (int j=0; j <= i; j++) {
                int l = (j == 0)? 0 : pre[j-1];
                int r = (j == i)? 0 : pre[j];
                cur.push_back(l + r);
            }
        }
        return cur;
    }
};
