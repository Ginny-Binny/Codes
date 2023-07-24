class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            int max_jump = min(i + nums[i], n - 1);
            for (int j = i + 1; j <= max_jump; j++) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
