#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void myF(int i, int j, int a[15][15], int n, char res[], int count, bool visited[15][15]){
    visited[i][j]=true;
    if(i==n-1 && j==n-1){
        for(int i=0;i<count;i++)
            cout<<res[i];
        cout<<" ";
    }
    if( i+1<n && a[i+1][j]==1 && !visited[i+1][j]){
        //bottom
        res[count++]='D';
        myF(i+1,j,a,n,res,count,visited);
        count--;
    }
    
    if( j-1>=0 &&  a[i][j-1] && !visited[i][j-1]){
        //left
        res[count++]='L';
        myF(i,j-1,a,n,res,count,visited);
        count--;
    }
    
    if( j+1<n && a[i][j+1] && !visited[i][j+1]){
        //right
        res[count++]='R';
        myF(i,j+1,a,n,res,count,visited);
        count--;
    }
    
    if( i-1>=0 && a[i-1][j]==1 && !visited[i-1][j]){
        //top
        res[count++]='U';
        myF(i-1,j,a,n,res,count,visited);
        count--;
    }
    
    
    visited[i][j]=false;
}

int main() {
    int t,n;
    cin>>t;
    int a[15][15];
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        char res[500];
        bool visited[15][15]={false};
        myF(0,0,a,n,res,0, visited);
        cout<<endl;
    }
    return 0;
}

