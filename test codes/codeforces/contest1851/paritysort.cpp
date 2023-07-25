#include <iostream>
#include <vector>

using namespace std;

bool canSortArray(vector<int>& a) {
    int n = a.size();
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    return (evenCount == n || oddCount == n || evenCount % 2 == 0);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (canSortArray(a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
