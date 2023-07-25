#include <iostream>
#include <vector>
using namespace std;

bool canSort(vector<int>& arr) {
    int n = arr.size();
    int even = 0, odd = 0;
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            if (i % 2 != 0)
                even++;
        } else {
            if (i % 2 == 0)
                odd++;
        }
    }
    
    return even == odd;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        if (canSort(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
