#include <bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;
int main(){
     
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;

         vector<int> a(n);
         for(int & i : a)cin>>i;

        map<int, int> freq;
        long long int ans=1;
         int mod7=1e9+7;

         for(int i: a){
             freq[i]++;
         }
         for(auto pii : freq){
             int f= pii.second;
             ans*=(f+1);
             ans%=mod7;
         }
         ans--;
         cout<<ans<<endl;
     }
return 0;
}