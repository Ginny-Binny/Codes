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
        if (flowerPots[i][W-1] < H) {
            continue;
        }
        for (int j = 0; j < W; ++j) {
            if (flowerPots[i][j] > H) {
                return {i, j};
            }
        }
    }
    return {L-1, W-1};  // If it reaches here, replace the last pot.
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