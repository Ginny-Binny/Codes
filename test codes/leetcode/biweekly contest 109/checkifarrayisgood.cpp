class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        int n = *std::max_element(nums.begin(), nums.end()); // Step 1

        std::vector<int> base;
        for (int i = 1; i <= n - 1; i++) {
            base.push_back(i);
        }
        base.push_back(n);
        base.push_back(n); // Step 2

        if (nums.size() != base.size()) { // Step 3
            return false;
        }

        std::sort(nums.begin(), nums.end());
        std::sort(base.begin(), base.end());

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != base[i]) {
                return false;
            }
        }

        return true;
    }
};