#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k, H;
        cin >> n >> m >> k >> H;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        queue<int> candidates;
        candidates.push(1);
        candidates.push(2);

        int valid_count = 0;
        for(int i = 0; i < n; i++) {
            int diff = abs(H - heights[i]);
            bool divisible = candidates.size() && (diff % k == 0);
            bool within_range = candidates.size() && (diff <= (m - 1) * k);
            bool not_zero_diff = candidates.size() && (diff > 0);
            if (divisible && within_range && not_zero_diff) {
                valid_count++;
            }
        }
        cout << valid_count << endl;
    }

    return 0;
}
