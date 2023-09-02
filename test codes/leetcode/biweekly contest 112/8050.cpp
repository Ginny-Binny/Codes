class Solution {
public:
    int calculateCombinationsModM(int total, int select, int modulo) {
        if (select == 0)
            return 1;

        vector<int> factorial(total + 1);
        factorial[0] = 1;

        // Calculate factorial modulo modulo for each number up to total
        for (int i = 1; i <= total; i++)
            factorial[i] = (1LL * factorial[i - 1] * i) % modulo;

        int result = factorial[total];
        result = (1LL * result * calculateModularInverse(factorial[select], modulo)) % modulo;
        result = (1LL * result * calculateModularInverse(factorial[total - select], modulo)) % modulo;

        return result;
    }

    int calculateModularInverse(int num, int modulo) {
        int modulo0 = modulo;
        int y = 0, x = 1;

        while (num > 1) {
            int quotient = num / modulo;
            int temp = modulo;
            modulo = num % modulo;
            num = temp;
            temp = y;
            y = x - quotient * y;
            x = temp;
        }

        if (x < 0)
            x += modulo0;

        return x;
    }

    int countKSubsequencesWithMaxBeauty(string inputString, int kValue) {
        int modulo = 1e9 + 7;
        unordered_map<char, int> charCountMap;

        for (char character : inputString) {
            charCountMap[character]++;
        }

        if (charCountMap.size() < kValue) {
            return 0;
        }

        vector<int> charCounts;
        for (auto charCountPair : charCountMap) {
            charCounts.push_back(charCountPair.second);
        }

        sort(charCounts.begin(), charCounts.end());
        reverse(charCounts.begin(), charCounts.end());

        int answer = 1;
        int totalChars = charCounts.size();
        int lowestCharCount = charCounts[kValue - 1];
        int totalLowestCharCount = 0, currentLowestCharCount = 0;

        for (int i = 0; i < totalChars; i++) {
            if (i < kValue) {
                answer = (1LL * answer * charCounts[i]) % modulo;
                if (charCounts[i] == lowestCharCount) {
                    currentLowestCharCount++;
                }
            }

            if (charCounts[i] == lowestCharCount) {
                totalLowestCharCount++;
            }
        }

        answer = (1LL * answer * calculateCombinationsModM(totalLowestCharCount, currentLowestCharCount, modulo)) % modulo;
        return answer;
    }
};
