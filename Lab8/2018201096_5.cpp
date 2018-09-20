#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef int l;
int n,m;
void DFS(int a[1002][1002], bool visited[1002][1002], int i, int j, int n, int m){
        visited[i][j]=true;
        if(j<m&&!visited[i][j+1]&&(a[i][j+1]==1)){
            DFS(a,visited,i,j+1,n,m);
        }
        if(j-1>=0&&!visited[i][j-1]&&(a[i][j-1]==1)){
            DFS(a,visited,i,j-1,n,m);
        }
        if(i+1<n&&!visited[i+1][j]&&(a[i+1][j]==1)){
            DFS(a,visited,i+1,j,n,m);
        }
        if(i-1>=0&&!visited[i-1][j]&&(a[i-1][j]==1)){
            DFS(a,visited,i-1,j,n,m);
        }
}

int main() {
    int n,m;
    cin>>n>>m;
    int a[1002][1002];
    bool visited[1002][1002]={false};
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=(s[i][j]=='1'?1:0);
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&(a[i][j]==1)){
                count++;
                DFS(a,visited,i,j,n,m);
            }
        }
    }
    cout<<count;

    return 0;
}

