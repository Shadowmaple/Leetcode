# include <iostream>
# include <vector>
# include <math.h>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> v;
        for (int i = 1; i < pow(10, n); i++) {
            v.push_back(i);
        }
        return v;
    }
};