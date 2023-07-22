#include <vector>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        
        // Calculate the prefix sum and prefix sum of even and odd elements
        vector<long long> prefixSum(n + 1, 0);
        vector<long long> prefixEven(n + 1, 0);
        vector<long long> prefixOdd(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            if (i % 2 == 0) {
                prefixEven[i + 1] = prefixEven[i] + nums[i];
                prefixOdd[i + 1] = prefixOdd[i];
            } else {
                prefixEven[i + 1] = prefixEven[i];
                prefixOdd[i + 1] = prefixOdd[i] + nums[i];
            }
        }
        
        long long maxScore = 0;
        for (int i = 0; i < n; ++i) {
            // Calculate the score when moving from position 0 to the current position
            long long leftScore = prefixEven[i + 1];
            
            // Calculate the score when moving from the current position to the end
            long long rightScore = prefixSum[n] - prefixSum[i + 1] - prefixOdd[i + 1];
            
            // Calculate the total score when moving from 0 to the current position and then to the end
            long long totalScore = leftScore + rightScore - x * ((i + 1) / 2);
            
            // Update the maximum score
            maxScore = max(maxScore, totalScore);
        }
        
        return maxScore;
    }
};
