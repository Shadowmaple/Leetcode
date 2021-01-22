# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if (!K) return A;

        int flag = 0, sum = 0;
        int i = A.size()-1;
        while (i >= 0 || K || flag) {
            if (i >= 0) {
                sum = A[i] + K % 10 + flag;
                A[i] = sum % 10;
                i--;
            } else {
                sum = K % 10 + flag;
                A.insert(A.begin(), sum % 10);
            }
            K /= 10;
            flag = sum / 10;
        }

        return A;
    }
};