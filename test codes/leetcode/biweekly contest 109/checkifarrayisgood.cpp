#include <vector>
#include <algorithm>

class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            // An array with less than two elements cannot be a permutation of base[n].
            return false;
        }

        std::vector<int> base(n + 1);
        for (int i = 1; i <= n; i++) {
            base[i] = i;
        }
        base[n] = n; // Set the last element to n as it appears twice.

        // Sort both the input array and the base array for easy comparison.
        std::sort(nums.begin(), nums.end());
        std::sort(base.begin(), base.end());

        // Check if the sorted arrays are the same.
        return nums == base;
    }
};
