#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long l;
using namespace std;
void print(vector<l> adj[],int m){
    for(l i=1;i<=m;i++){
            for(auto it=adj[i].begin();it!=adj[i].end();++it)
                cout<<*it<<" ";   
            cout<<endl;
        }
}

void dfs(vector<l> adj[], bool visited[2007][2007], int first, int second, int i, int j,int &count, int m, int n){
    visited[i][j]=true;
    // cout<<i<<" "<<j<<" "<<first<<" "<<second<<endl;
    if(adj[i][j]==first || adj[i][j]==second){
        count++;
                    if(i+1<=m && !visited[i+1][j])
                        dfs(adj,visited,first,second,i+1,j,count,m,n);
                    if(j+1<n && !visited[i][j+1])
                        dfs(adj,visited,first,second,i,j+1,count,m,n);
        }        

}

int main() {
    l t,m,n,num;
        cin>>m>>n;
        vector<l> adj[m+1];
        for(l i=1;i<=m;i++){
            for(l j=0;j<n;j++){
                cin>>num;
                adj[i].push_back(num);   
            }
        }
        int res=0;
        int temp=0;
        bool visited[2007][2007]={false};
        for(int k=1;k<m;k++){
            for(int s=k+1;s<=m; s++){
                // for(int i=1;i<=m;i++){
                    // for(int j=0;j<n;j++){
                        int count=0;
                        if(!visited[0][0]){
                            dfs(adj,visited,k,s,1,0,count,m,n);
                        }
                        res=max(res,count);
                        temp+=count;
                        if(res>(m*n-temp)){
                            k=m;
                            break;
                        }
                    // }
                // }   
                memset(visited,false,sizeof(visited));
            }
        }
    cout<<res;
        
        
    return 0;
}
