# include <iostream>
# include <vector>
# include <string>
# include <sstream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        DFS(v, 0, 0, num, 0);
        return v;
    }

    void DFS(vector<string>& v, int hour, int min, int num, int idx) {
        if (hour >= 12 || min >= 60)
            return ;
        if (!num) {
            string s;
            stringstream ss;
            if (min > 9)
                ss << hour << ':' << min;
            else
                ss << hour << ':' << '0' << min;
            ss >> s;
            v.push_back(s);
            return ;
        }

        for (int i = idx; i < 10; i++) {
            if (i < 4) DFS(v, hour+(1<<i), min, num-1, i+1);
            else       DFS(v, hour, min+(1<<(i-4)), num-1, i+1);
        }
    }
};