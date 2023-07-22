class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";
        string t = s;
        // Extract and sort vowels from s
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        
        // Replace vowels in t
        int vowelIndex = 0;
        for (char& c : t) {
            if (isVowel(c)) {
                c = vowels[vowelIndex++];
            }
        }
        return t;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};