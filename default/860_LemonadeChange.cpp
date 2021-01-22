# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[2] = {0};
        for (int bill : bills) {
            switch (bill) {
            case 5:
                change[0]++;
                break;
            case 10:
                if (!change[0]) return false;
                change[0]--;
                change[1]++;
                break;
            case 20:
                if (change[1] && change[0]) {
                    change[1]--;
                    change[0]--;
                } else if (change[0] > 3) {
                    change[0] -= 3;
                } else {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};