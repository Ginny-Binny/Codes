#include <iostream>
#include <vector>

using namespace std;
 
int main(){
    int t;
    cin>>t;
    vector<int>v;
    while(t--){
        vector<int> arr;
        int a;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }

        int odd=0, even=0, cem=0;
        for(int i=0;i<v.size();i++){
            cem += v[i];
            if(v[i]%2==0){
                odd++;

            }
            else{
                even++;
            }
        }
        if(cem%2 != 0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
