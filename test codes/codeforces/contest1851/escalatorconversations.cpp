#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k, H;
        cin >> n >> m >> k >> H;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        int conversations = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int stepHeight = (j + 1) * k;
                int heightDiff = abs(heights[i] - stepHeight);
                if (heightDiff > 0 && heightDiff <= H && heightDiff % k == 0) {
                    conversations++;
                    break; // Move to the next person
                }
            }
        }

        cout << conversations << endl;
    }

    return 0;
}
