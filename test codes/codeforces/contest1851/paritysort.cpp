#include <iostream>
#include <vector>

bool canSortArray(const std::vector<int>& arr) {
    int oddCount = 0;
    int evenCount = 0;

    for (int num : arr) {
        if (num % 2 == 1) {
            oddCount++;
        } else {
            evenCount++;
        }
    }

    return (oddCount > 0 && evenCount > 0);
}

int main() {
    int t; // Number of test cases
    std::cin >> t;

    while (t--) {
        int n; // Size of the array
        std::cin >> n;
        
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        
        bool result = canSortArray(arr);
        std::cout << (result ? "YES" : "NO") << std::endl;
    }

    return 0;
}
