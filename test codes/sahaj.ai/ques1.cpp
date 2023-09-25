#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, W;
    cin >> L >> W;

    vector<vector<int>> pots(L, vector<int>(W));

    // Read the input matrix
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < W; j++) {
            cin >> pots[i][j];
        }
    }

    int H;
    cin >> H;

    int row = -1, col = -1;

    // Traverse the matrix to find the position for the new pot
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < W; j++) {
            if(pots[i][j] > H) {
                row = i;
                col = j;
                break;
            }
        }
        if(row != -1) break;  // If position found, break out of loop
    }

    // If no position found in the matrix, it means the new pot will replace the last one
    if(row == -1) {
        row = L - 1;
        col = W - 1;
    }

    cout << row << " " << col << endl;

    return 0;
}