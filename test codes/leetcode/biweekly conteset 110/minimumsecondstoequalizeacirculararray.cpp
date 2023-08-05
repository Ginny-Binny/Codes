#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> indexMap;
        int n = nums.size();
        
        // Store the indices of each element in a map
        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }
        
        // Sort the indices for each element
        for (auto& entry : indexMap) {
            sort(entry.second.begin(), entry.second.end());
        }
        
        int ans = numeric_limits<int>::max();
        
        // Calculate the minimum seconds for each element's indices
        for (const auto& entry : indexMap) {
            int maxSeconds = (n - entry.second.back() - 1 + entry.second[0]) / 2 + (n - entry.second.back() - 1 + entry.second[0]) % 2;

            for (int i = 1; i < entry.second.size(); i++) {
                maxSeconds = max(maxSeconds, ((entry.second[i] - entry.second[i - 1] - 1) / 2) + ((entry.second[i] - entry.second[i - 1] + 1) % 2));
            }
            
            ans = min(ans, maxSeconds);
        }
        
        return ans;
    }
};

