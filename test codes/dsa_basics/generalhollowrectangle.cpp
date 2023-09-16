#include <bits/stdc++.h>
using namespace std;
int main(){
    int rownum, colnum;
    cin>>rownum>>colnum;
    for( int row=0;row<rownum;row=row+1){
        if(row==0 || row= rownum-1){
            for(int col=0; col=colnum;col=col+1){
                cout<<"*";
            }

        }
        else
        {
            cout<<"*";
            for(int col=0;col=colnum-2;col=col+1){
                cout<<" ";
            }
        }
    }




return 0;
}