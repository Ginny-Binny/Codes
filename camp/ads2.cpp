#include <bits/stdc++.h>

std::string rearrangeString(const std::string& input) {
    // Count the frequency of each character
    int frequency[26] = {0};
    for (char c : input) {
        frequency[c - 'a']++;
    }

    // Create a vector of pairs to store the character and its frequency
    std::vector<std::pair<char, int>> chars;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            chars.push_back(std::make_pair('a' + i, frequency[i]));
        }
    }

    // Sort the characters based on their frequency in descending order
    std::sort(chars.begin(), chars.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second > b.second;
    });

    // Rearrange the characters
    std::string rearrangedString;
    int n = input.length();
    int index = 0;
    while (n > 0) {
        int i = 0;
        while (i < chars.size() && chars[i].second == 0) {
            i++;
        }
        if (i == chars.size()) {
            // No valid character to add
            break;
        }

        if (rearrangedString.empty() || rearrangedString.back() != chars[i].first) {
            rearrangedString += chars[i].first;
            chars[i].second--;
            n--;
            index++;
        } else {
            i++;
            while (i < chars.size() && chars[i].second == 0) {
                i++;
            }

            if (i == chars.size()) {
                // No valid character to add
                break;
            }

            rearrangedString += chars[i].first;
            chars[i].second--;
            n--;
            index++;
        }
    }

    if (n > 0) {
        // Not possible to rearrange the string
        rearrangedString = "Not possible";
    }

    return rearrangedString;
}

int main() {
    std::string input;
    std::cout << "Enter the string: ";
    std::cin >> input;

    std::string rearranged = rearrangeString(input);
    std::cout << "Rearranged string: " << rearranged << std::endl;

    return 0;
}
