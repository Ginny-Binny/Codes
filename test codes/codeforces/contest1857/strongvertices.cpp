#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define sz(x) ((int)(x).size())

void findStrongVertices()
{
    int n;
    cin >> n;

    vi a(n), b(n);
    rep(i, n)
            cin >>
        a[i];
    rep(i, n)
            cin >>
        b[i];

    vector<pii> differences;
    int maxDifference = INT_MIN;
    rep(i, n)
    {
        int diff = a[i] - b[i];
        differences.pb({diff, i + 1});
        maxDifference = max(maxDifference, diff);
    }

    vi strongVertices;
    rep(i, n)
    {
        if (differences[i].first == maxDifference)
        {
            strongVertices.pb(differences[i].second);
        }
    }

    cout << sz(strongVertices) << endl;
    rep(i, sz(strongVertices))
            cout <<
        strongVertices[i] << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        findStrongVertices();
    }

    return 0;
}
