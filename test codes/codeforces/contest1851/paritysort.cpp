#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> odd, even;
    vector<int> new_arr;
    for (int i = 0; i < n; i++)
    {
        if (v[i] & 1)
            odd.push_back(v[i]);
        else
            even.push_back(v[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int odd_p = 0, even_p = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] & 1)
        {
            new_arr.push_back(odd[odd_p]);
            odd_p++;
        }
        else
        {
            new_arr.push_back(even[even_p]);
            even_p++;
        }
    }

    if (is_sorted(new_arr.begin(), new_arr.end()))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}
