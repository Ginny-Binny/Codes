class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int end = n - 1;
        int start = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (!isBinarySearchHelpful(nums, start, nums[mid])) {
                start++;
                continue;
            }

            bool pivotArray = existsInFirst(nums, start, nums[mid]);

            bool targetArray = existsInFirst(nums, start, target);
            if (pivotArray ^ targetArray) { 
                if (pivotArray) {
                    start = mid + 1; 
                } else {
                    end = mid - 1; // target in the first, pivot in the second
                }
            } else { // If pivot and target exist in same sorted array
                if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }

    bool isBinarySearchHelpful(vector<int>& nums, int start, int element) {
        return nums[start] != element;
    }

    // returns true if element exists in first array, false if it exists in second
    bool existsInFirst(vector<int>& nums, int start, int element) {
        return nums[start] <= element;
    }
};