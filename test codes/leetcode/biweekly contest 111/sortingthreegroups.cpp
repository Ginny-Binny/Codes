#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis; // Store the Longest Increasing Subsequence elements
        int count = 0;

        lis.push_back(nums[0]); // Initialize with the first element

        for (int i = 1; i < n; i++) {
            auto lo = lower_bound(lis.begin(), lis.end(), nums[i]);
            auto up = upper_bound(lis.begin(), lis.end(), nums[i]);

            if (up == lis.end()) {
                lis.push_back(nums[i]); // Append to LIS
            } else {
                int ind = up - lis.begin();
                lis[ind] = min(lis[ind], nums[i]); // Update LIS element
                count++;
            }
        }

        return count;
    }
};
