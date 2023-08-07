#include <iostream>
#include <vector>

std::string solveTestCase(std::vector<int>& arr) {
    int evenCount = 0;
    int oddCount = 0;

    for (int num : arr) {
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    if (evenCount > 0 && oddCount > 0) {
        return "YES";
    } else if (evenCount > 1 || oddCount > 1) {
        return "YES";
    } else {
        return "NO";
    }
}
