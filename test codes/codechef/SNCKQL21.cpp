#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(), v.end()
#define display(A) for (auto &aa:A) cout<<aa<<" ";cout <<"\n";
#define FOR(i,a,n) for(ll i=a; i<=n; i++)
#define TTT template<typename T>

const ll MAX = 2e6+50, INF = 1e15; ll MOD = 1e9 +7;

string x,s ,t, S;
int k,n ,m,N;
int z[MAX], pi[MAX], g[MAX], found[MAX];

void test_case(ll tc=0){
    cin>>s>>t>>x;
    int k=x.length(), n= s.length(), m=t.length();
    for(int i=0;i<=max(n,m)+ k+10;i++){
        z[i] = 0, pi[i] =0 , g[i]=0, found[i]=0;

    }

    S= t+"?"+x;
    N=S.length();

    for(int i=1,l=0,r=0;i<N;++i){

        if(i<=r){
            z[i]=min(r-i+1,z[i-1]);
        }
        while(i+z[i]<N && S[z[i]]==S[i+z[i]]){
            ++z[i];
        }

        if(i+z[i]-1>r){
            l=i,r=i+z[i]-1;

        }


    }

    S=s+"?"+x;
    N=S.length();
    for(int i=1,j; i<N ; i++){
    j=pi[i-1];
    while(j>0&& S[i]!= S[j]){
        j=pi[j-1];
    }
    if(S[i]==S[j]){
        j++;
    }
    }
}