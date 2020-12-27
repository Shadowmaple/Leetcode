# include <iostream>
# include <queue>
using namespace std;

struct Apple {
    int num;
    int remainTime;
    Apple(int n, int t): num(n), remainTime(t) {}
};

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<Apple*, vector<Apple*>> q;
    }
};