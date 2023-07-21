#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePositions(string moves, long long k) {
        vector<int> positions = {0};
        unordered_set<int> uniquePositions;
        uniquePositions.insert(0);

        for (char move : moves) {
            vector<int> newPositions;
            for (int pos : positions) {
                int newPosForward = pos + k;
                int newPosBackward = pos - k;
                if (uniquePositions.find(newPosForward) == uniquePositions.end()) {
                    newPositions.push_back(newPosForward);
                    uniquePositions.insert(newPosForward);
                }
                if (uniquePositions.find(newPosBackward) == uniquePositions.end()) {
                    newPositions.push_back(newPosBackward);
                    uniquePositions.insert(newPosBackward);
                }
            }
            positions = newPositions;
        }

        return uniquePositions.size();
    }
};
