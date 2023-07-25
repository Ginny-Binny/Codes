#include <iostream>
#include <vector>
using namespace std;

bool can_construct_path(vector<int>& path_colors, int k) {
    int n = path_colors.size();
    vector<int> prefix_sum(n + 1, 0);

    // Calculate prefix sum
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + path_colors[i - 1];
    }

    // Check if path can be constructed
    for (int i = k; i <= n; ++i) {
        if ((prefix_sum[i] - prefix_sum[i - k]) % k != 0 || prefix_sum[i] % k != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> path_colors(n);
        for (int i = 0; i < n; ++i) {
            cin >> path_colors[i];
        }

        if (can_construct_path(path_colors, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
