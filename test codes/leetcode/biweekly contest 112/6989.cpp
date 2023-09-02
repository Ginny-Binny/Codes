#include <vector>
#include <unordered_map>

class Solution {
public:
    long maxSum(std::vector<int>& nums, int m, int k) {
        std::unordered_map<int, int> countMap;
        int distinct = 0;
        long sum = 0, maxSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            // Update count of the current number
            countMap[num] = countMap[num] + 1;

            // If it's the first occurrence of the current number, increment distinct count
            if (countMap[num] == 1) {
                distinct++;
            }

            // Add the current number to the sum
            sum += num;

            // If the window size exceeds k, remove the leftmost element from the window
            if (i >= k) {
                int prev = nums[i - k];
                countMap[prev] = countMap[prev] - 1;

                // If there are no more occurrences of the removed number, decrement distinct count
                if (countMap[prev] == 0) {
                    distinct--;
                }

                // Subtract the removed number from the sum
                sum -= prev;
            }

            // Check if the window size is at least k and distinct elements are >= m
            if (i >= k - 1 && distinct >= m) {
                // Update maxSum if the current sum is greater
                maxSum = std::max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
