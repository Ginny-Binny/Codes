#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int row=0;row<6;row++){
        if(row==0|| row==5){
            for(int col=0;col<6;col++){
                cout<<"*";
            }
        }
        else{
            cout<<"*";
            for(int a=0;a<3;a++){
                cout<<" ";
            }
            cout<<"*";
        }
        
        cout<<endl;
    } 
}