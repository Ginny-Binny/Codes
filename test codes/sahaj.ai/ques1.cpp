#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, W;
    cin >> L >> W;

    vector<vector<int>> r(L, vector<int>(W));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            cin >> r[i][j];
        }
    }

    int height;
    cin >> height;

    int row = -1;
    int col = -1;

    for (int i = 0; i < L; i++) {
        int left = 0, right = W - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (r[i][mid] > height) {
                col = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (col != -1) {
            row = i;
            break;
        }
    }

    
    cout << (row) << " " << (col) << endl;

    return 0;
}