#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        // Check if both strings have the same set of characters
        vector<int> count(26, 0);

        for (char c : s1) {
            count[c - 'a']++;
        }

        for (char c : s2) {
            count[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        // Check if there are even numbers of adjacent swaps needed to make the strings equal
        int n = s1.length();
        int swapCount = 0;

        for (int i = 0; i < n; i += 2) {
            if (s1[i] != s2[i]) {
                swapCount++;
            }
        }

        return (swapCount % 2 == 0);
    }
};

int main() {
    Solution solution;
    string s1 = "zzon";
    string s2 = "zozn";
    bool result = solution.canBeEqual(s1, s2);
    cout << "Result: " << (result ? "true" : "false") << endl;
    return 0;
}

