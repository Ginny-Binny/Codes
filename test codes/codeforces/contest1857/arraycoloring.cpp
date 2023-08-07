#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> v;
        
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        int odd = 0, even = 0, cem = 0;
        for (int i = 0; i < v.size(); i++) {
            cem += v[i];
            if (v[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (cem % 2 == 0 && (odd > 0 || (even > 0 && n > 1))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
