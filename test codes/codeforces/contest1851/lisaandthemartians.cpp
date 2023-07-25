#include <iostream>
#include <vector>

using namespace std;

// Function to find optimal indices i, j, and x
void findOptimalIndicesAndX(int n, int k, const vector<int>& martian_numbers) {
    int max_value = -1;
    int i = 1, j = 2, x = 0;

    for (x = 0; x < (1 << k); x++) {
        for (int i_idx = 0; i_idx < n; i_idx++) {
            for (int j_idx = i_idx + 1; j_idx < n; j_idx++) {
                int value = (martian_numbers[i_idx] ^ x) & (martian_numbers[j_idx] ^ x);
                if (value > max_value) {
                    max_value = value;
                    i = i_idx + 1; // Convert to 1-based index
                    j = j_idx + 1; // Convert to 1-based index
                }
            }
        }
    }

    cout << i << " " << j << " " << x << endl;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, k; // Length of sequence and value of k
        cin >> n >> k;

        vector<int> martian_numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> martian_numbers[i];
        }

        findOptimalIndicesAndX(n, k, martian_numbers);
    }

    return 0;
}
