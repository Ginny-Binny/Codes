#include <bits/stdc++.h>
using namespace std;
int main(){
    int rownum, colnum;
    cin>>rownum>>colnum;
    for( int row=0; row<rownum; row=row+1){
        if(row==0 || row== rownum-1){
            for(int col=0; col<colnum;col=col+1){
                cout<<"* ";
            }

        }
        else
        {
            cout<<"* ";

            for(int i=0;i<colnum-2;i=i+1){
                cout<<"  ";
         
            }

            cout<<"* ";
        }
        cout<<endl;
    }

}