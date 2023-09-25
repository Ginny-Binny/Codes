#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findPosition(const vector<vector<int>>& flowerPots, int H) {
    int L = flowerPots.size();
    int W = flowerPots[0].size();

    for (int i = 0; i < L; ++i) {
        if (flowerPots[i][0] > H) {
            return {i, 0};
        }
        if (flowerPots[i][W-1] >= H) {
            // Binary search in this row
            int l = 0, r = W - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (flowerPots[i][mid] == H) {
                    return {i, mid};
                } else if (flowerPots[i][mid] > H) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return {i, l};  // Insert at the found position
        }
    }
    return {-1, -1};  // Should never reach this if room is full.
}

int main() {
    int L, W, H;
    cin >> L >> W;

    vector<vector<int>> flowerPots(L, vector<int>(W));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> flowerPots[i][j];
        }
    }

    cin >> H;

    pair<int, int> position = findPosition(flowerPots, H);
    cout << position.first << " " << position.second << endl;

    return 0;
}