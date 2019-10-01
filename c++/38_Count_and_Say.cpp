# include <iostream>
# include <string>
# include <cstring>
using namespace std;

// C++方法，应用string类，更简洁
class Solution {
public:
    string countAndSay(int n) {
        string num = "1";
        while (n-- > 1) {
            int count = 1;
            string replace = "";
            for (int i = 0; i < num.length(); i++) {
                if (num[i] == num[i+1]) {
                    count++;
                    continue;
                }
                replace += count + '0';
                replace += num[i];
                count = 1;
            }
            num = replace;
        }
        return num;
    }
};

// C语言方法，0ms，空间复杂度更小
class Solution2 {
public:
    string countAndSay(int n) {
        char num[5000] = "1", replace[5000];
        while (n-- > 1) {
            int count = 1, index = 0;
            char n = num[0];
            for (int i=1; i < strlen(num); i++) {
                if (num[i] == n) {
                    count++;
                    continue;
                }
                give(replace, &index, count);
                replace[index++] = n;

                n = num[i];
                count = 1;
            }
            give(replace, &index, count);
            replace[index++] = n;
            replace[index] = '\0';
            // cout<<replace<<endl;
            strcpy(num, replace);
        }
        return num;
    }

    void give(char *a, int *index, int num) {
        if (num < 10) {
            a[(*index)++] = num + '0';
            return ;
        }
        char x[100];
        int i = 98;
        x[99] = '\0';
        while (num) {
            x[i--] = num % 10;
            num /= 10;
        }
        strcpy(a + *index, x + i + 1);
        *index += 98 - i;
    }
};

int main() {
    Solution num;
    cout << num.countAndSay(20) << endl;
}
