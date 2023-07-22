#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    unordered_map<int, unordered_map<int, int>> memo;

    int waysToSum(int n, int x, int num) {
        if (n == 0)
            return 1;

        if (n < 0 || num <= 0)
            return 0;

        if (memo.find(n) != memo.end() && memo[n].find(num) != memo[n].end())
            return memo[n][num];

        int without_num = waysToSum(n, x, num - 1);
        int with_num = 0;

        if (pow(num, x) <= n) {
            with_num = waysToSum(n - pow(num, x), x, num - 1);
        }

        int result = (without_num + with_num) % MOD;
        memo[n][num] = result;
        return result;
    }

    int numberOfWays(int n, int x) {
        if (pow(1, x) > n) // If x-th power of 1 exceeds n, no valid numbers
            return 0;

        int num = 1;
        while (pow(num, x) <= n) {
            num++;
        }
        return waysToSum(n, x, num - 1);};