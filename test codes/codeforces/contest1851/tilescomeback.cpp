#include <iostream>
#include <vector>
using namespace std;

#define ll long long 
#define pb push_back
#define loop(n) for(long long i=0;i<n;i++)
#define rloop(n) for(long long i=n-1;i>=0;i--)

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {

        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        loop(n){
            cin >> a[i];
        }

        ll last = n - 1;
        ll cnt = 0;
        loop(n){
            if (a[i] == a[0])
                cnt++;
            if (cnt == k){
                last = i;
                break;
            }
        }

        if (cnt < k){
            cout << "NO" << endl;
            continue;
        } else {
            if (a[0] == a[n - 1]){
                cout << "YES" << endl;
                continue;
            }
        }

        cnt = 0;
        for (int i = n - 1; i > last; i--){
            if (a[i] == a[n - 1])
                cnt++;
        }

        if (cnt >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
