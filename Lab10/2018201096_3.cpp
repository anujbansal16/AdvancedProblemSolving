#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSafe(int a[20][20], int n, int col, int row){
    // cout<<row<<" "<<col<<endl;
    for(int i=1;i<row;i++){
        if(a[i][col]==1)
            return false;
    }
    for(int i=1;i<col;i++){
        if(a[row][i]==1)
            return false;
    }
    for(int i=row-1,j=col-1;i>=1&&j>=1;i--,j--){
        if(a[i][j]==1)
            return false;
    }
    for(int i=row+1,j=col-1;i<=n&&j>=1;i++,j--){
        if(a[i][j]==1)
            return false;
    }
    return true;
    
}

bool flag=false;
bool queenUtil(int a[20][20], int n, int col){
    if(col<=n){
        for(int i=1;i<=n;i++){
            a[i][col]=1;
            if(isSafe(a,n,col,i)){
                bool temp=queenUtil(a,n,col+1);
                if(col==n)
                    a[i][col]=0;              
                if(temp==false)
                    a[i][col]=0;                
            }
            else
                a[i][col]=0;            
        }
        return false;
    }
    cout<<"[";
    flag=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j][i]==1)
                cout<<j<<" ";
        }
    }
    cout<<"] ";
    return true;
}

void nQueen(int n, int a[20][20]){
    queenUtil(a,n,1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        flag=false;
        int a[20][20]={0};
        nQueen(n,a);
        if(!flag)
            cout<<"-1";
        cout<<endl;
    }
    return 0;
}

