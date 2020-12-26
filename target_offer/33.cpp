# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() <= 1) return true;
        return binaryVerify(postorder, 0, postorder.size()-1);
    }

    bool binaryVerify(vector<int>& postorder, int begin, int end) {
        if (begin >= end) return true;

        int rootVal = postorder[end];
        int mid = begin;
        while (mid < end && postorder[mid] < rootVal) mid++;

        for (int i = mid; i < end; i++) {
            if (postorder[i] < rootVal) return false;
        }

        return binaryVerify(postorder, begin, mid-1) && binaryVerify(postorder, mid, end-1);
    }
};