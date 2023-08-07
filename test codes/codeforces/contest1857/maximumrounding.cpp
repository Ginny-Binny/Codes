#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        string input;
        cin >> input;
        
        int index = 0;
        while (index < input.length() && input[index] < '5') {
            index++;
        }
        
        if (index == input.length()) {
            cout << input << endl;
        } else {
            for (int j = index + 1; j < input.length(); j++) {
                input[j] = '0';
            }
            
            for (int j = index; j > 0; j--) {
                if (input[j] >= '5') {
                    input[j - 1] += 1;
                    input[j] = '0';
                }
            }
            
            if (input[0] >= '5') {
                cout << "10";
            } else {
                cout << input[0];
            }
            
            for (int i = 1; i < input.length(); i++) {
                cout << input[i];
            }
            
            cout << endl;
        }
    }
    
    return 0;
}
