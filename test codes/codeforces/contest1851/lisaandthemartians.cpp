#include <iostream>
#include <vector>

using namespace std;

// Function to find optimal indices i, j, and x
void findOptimalIndicesAndX(int n, int k, const vector<int>& martian_numbers) {
    int max_value = -1;
    int i = 0, j = 0, x = 0;

    // Precompute the XOR of all possible pairs and store in a 2D matrix
    vector<vector<int>> xor_pairs(n, vector<int>(n, 0));
    for (int i_idx = 0; i_idx < n; i_idx++) {
        for (int j_idx = i_idx + 1; j_idx < n; j_idx++) {
            xor_pairs[i_idx][j_idx] = xor_pairs[j_idx][i_idx] = martian_numbers[i_idx] ^ martian_numbers[j_idx];
        }
    }

    // Iterate through the bits of x from MSB to LSB
    for (int bit = k - 1; bit >= 0; bit--) {
        // Check if flipping the current bit increases the maximum value
        int new_max_value = max_value;
        int new_i = i, new_j = j, new_x = x;

        for (int i_idx = 0; i_idx < n; i_idx++) {
            for (int j_idx = i_idx + 1; j_idx < n; j_idx++) {
                int value = xor_pairs[i_idx][j_idx] ^ (x ^ (1 << bit));
                if (value > new_max_value) {
                    new_max_value = value;
                    new_i = i_idx + 1; // Convert to 1-based index
                    new_j = j_idx + 1; // Convert to 1-based index
                    new_x = x ^ (1 << bit);
                }
            }
        }

        // Update the maximum value and related variables if needed
        if (new_max_value > max_value) {
            max_value = new_max_value;
            i = new_i;
            j = new_j;
            x = new_x;
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
