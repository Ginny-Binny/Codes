#include <iostream>
#include <vector>

using namespace std;

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

    int rowToInsert = -1;
    int colToInsert = -1;

    // Iterate through rows in reverse order
    for (int i = 0; i < L; ++i) {
        if (flowerPots[i][0] > H) {
            rowToInsert = i;
            colToInsert = 0;
            break;
        }
        if (flowerPots[i][W - 1] < H) {
            continue;
        }
        for (int j = 1; j < W; ++j) {
            if (flowerPots[i][j - 1] <= H && H <= flowerPots[i][j]) {
                rowToInsert = i;
                colToInsert = j;
                break;
            }
        }
        if (rowToInsert != -1) {
            break;
        }
    }

    // Print the coordinates of the suitable position
    cout << rowToInsert << " " << colToInsert << endl;

    return 0;
}
