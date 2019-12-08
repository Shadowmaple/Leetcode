# include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, mult = 1;
        while (n) {
            int x = n % 10;
            sum += x;
            mult *= x;
            n /= 10;
        }
        return mult - sum;
    }
};

int main() {
    return 0;
}