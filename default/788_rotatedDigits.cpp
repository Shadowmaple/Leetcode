# include <iostream>
# include <map>
# include <math.h>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int m[] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        int count = 0;
        for (int i = 0; i <= N; i++) {
            int k = i, num = 0, e = 0;
            bool flag = true;
            while (k) {
                int x = k % 10;
                k /= 10;
                if (m[x] == -1) {
                    flag = false;
                    break;
                }
                num += m[x] * pow(10, e);
                e++;
            }
            if (num != i && flag) count++;
        }
        return count;
    }
};