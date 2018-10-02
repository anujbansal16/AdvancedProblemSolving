#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(int i, int j, int a[150][150], bool visited[150][150],int m, int n, int count){
    visited[i][j]=true;
    if(j+1<n && a[i][j+1]==1 && !visited[i][j+1]){
        // cout<<"right"<<endl;
        count=1+dfs(i,j+1,a,visited,m,n,count);
    }
    if(j-1>=0 && a[i][j-1]==1 && !visited[i][j-1]){
        // cout<<"left"<<endl;
        count=1+dfs(i,j-1,a,visited,m,n,count);
        
    }
    if(i+1<m && a[i+1][j]==1 && !visited[i+1][j]){
        // cout<<"bottom"<<endl;
        count=1+dfs(i+1,j,a,visited,m,n,count);
    }
    if(i-1>=0 && a[i-1][j]==1 && !visited[i-1][j]){
        // cout<<"top"<<endl;
        count=1+dfs(i-1,j,a,visited,m,n,count);
    }
    return count;
}

int main() {
    int m,n;
    int a[150][150];
        cin>>m>>n;
        string s;
        for(int i=0;i<m;i++){
            cin>>s;   
            for(int j=0;j<n;j++){
                a[i][j]=(s[j]=='1'?1:0);
            }
        }
int x,y, xC=-1, yC=-1,res=0;
for(x=0;x<m;x++){
    for(y=0;y<n;y++){
         if(a[x][y]==0){
             a[x][y]=1;   
             xC=x;yC=y;
         }
        bool visited[150][150]={false};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                if(!visited[i][j] && a[i][j]==1)
                    res=max(res,dfs(i,j,a,visited,m,n,count)+1);
            }
        }
        if(xC!=-1 && yC!=-1){
            a[xC][yC]=0;
            xC=-1;
            yC=-1;
        }
    }
}
    cout<<res;
    return 0;
}

