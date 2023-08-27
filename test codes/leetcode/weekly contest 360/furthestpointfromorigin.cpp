class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int underscoreCount = 0;
        int leftCount = 0;
        int rightCount = 0;

        for (char move : moves) {
            if (move == '_') {
                underscoreCount++;
            } else if (move == 'L') {
                leftCount++;
            } else if (move == 'R') {
                rightCount++;
            }
        }

        int maxLRCount = max(leftCount, rightCount);
        int minLRCount = min(leftCount, rightCount);

        underscoreCount += maxLRCount - minLRCount;

        return underscoreCount;
    }
};