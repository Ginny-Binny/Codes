#include <bits/stdc++.h>

// Find the maximum length among all the strings in the array
int findMaxLength(const std::vector<std::string>& arr) {
    int maxLength = 0;
    for (const std::string& str : arr) {
        maxLength = std::max(maxLength, static_cast<int>(str.length()));
    }
    return maxLength;
}

// Perform counting sort based on the character at a specific position
void countingSort(std::vector<std::string>& arr, int pos) {
    const int n = arr.size();
    const int k = 256; // Assuming ASCII characters

    std::vector<int> count(k, 0);
    std::vector<std::string> output(n);

    // Count the frequency of characters at the specified position
    for (const std::string& str : arr) {
        if (pos < str.length()) {
            count[str[pos]]++;
        } else {
            count[0]++; // Append 0 if the string is shorter than pos
        }
    }

    // Calculate cumulative counts
    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = n - 1; i >= 0; i--) {
        const std::string& str = arr[i];
        int index = (pos < str.length()) ? str[pos] : 0;
        output[count[index] - 1] = str;
        count[index]--;
    }

    // Update the original array with the sorted values
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort algorithm to sort an array of strings
void radixSort(std::vector<std::string>& arr) {
    int maxLength = findMaxLength(arr);

    // Perform counting sort for each position from right to left
    for (int pos = maxLength - 1; pos >= 0; pos--) {
        countingSort(arr, pos);
    }
}

int main() {
    std::vector<std::string> arr = { "LAKSHMAN", "RAJ", "CHIRAG", "ADI", "ROHAN", "KING" };

    std::cout << "Original array: ";
    for (const std::string& str : arr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (const std::string& str : arr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}

