# include <iostream>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
		int l = 1, r = n;
		int mid;
		while (l <= r) {
			// 预防溢出
			mid = (r - l) / 2 + l;
			int x = guess(mid);
			if (!x)	return mid;
			if (x == -1) r = mid - 1;
			else l = mid + 1;
		}
		return 0;
    }
};
