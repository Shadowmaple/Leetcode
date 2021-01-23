# include <iostream>
using namespace std;

int main() {
    int r;
    cin >> r;
    int num[r][r];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < i+1; j++)
            cin >> num[i][j];
    }

    for (int i = r-2; i >= 0; i--) {
        for (int j = 0; j < i+1; j++) {
            num[i][j] += max(num[i+1][j], num[i+1][j+1]);
        }
    }

    cout << num[0][0] << endl;

    return 0;
}