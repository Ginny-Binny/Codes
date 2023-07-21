#include <iostream>
#include <unordered_set>
using namespace std;

int countUniquePositions(int k, const string& moves) {
    int position = 0;
    unordered_set<int> uniquePositions;
    uniquePositions.insert(position);

    for (char move : moves) {
        if (move == 'F') {
            position += k;
        } else if (move == 'B') {
            position -= k;
        }
        uniquePositions.insert(position);
    }

    return uniquePositions.size();
}

int main() {
    int k = 2;
    string moves = "FBFB";

    int uniquePositions = countUniquePositions(k, moves);
    cout << "Number of unique positions: " << uniquePositions << endl;

    return 0;
}
