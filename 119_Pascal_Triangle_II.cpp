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
                if (j == 0 || j == i) cur.push_back(1);
                else cur.push_back(pre[j-1]+pre[j]);
            }
        }
        return cur;
    }
};
