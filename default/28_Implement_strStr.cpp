# include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        int index = haystack.find(needle);
        return index;
    }
};
