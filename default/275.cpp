# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int b = 0;
        for (int i = len-1; i >= 0; i--) {
            if (b >= citations[i]) return b;
            b++;
        }
        return b;
    }
};
