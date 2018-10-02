#include <bits/stdc++.h>
using namespace std;
int cou=0;
vector<int> adj[140009];
vector<int> adj2[140009];
int mystack[140009];
int adder[140009];

void insert(int a, int b){
    adj[a].push_back(b);
}

void dfs(int u, bool visited[]) {
    mystack[u]=true;
    visited[u]=true;
    for(auto v=adj[u].begin();v!=adj[u].end();++v){
        if (visited[*v]) {
            if (mystack[*v]) {
                adder[u] = true;
            }
        } else {
            dfs(*v, visited);
        }
        adder[u]|=adder[*v];
    }
    mystack[u] = false;
}

int main() {
    int t,n,e,a,b;
    cin>>t;
    while(t--){
        bool visited[140009]={false};
        memset(mystack, false, sizeof(mystack));
        memset(adder, false, sizeof(adder));
        cou=0;
        cin>>n>>e;
        for(int i=0;i<e;i++){
            cin>>a>>b;
            insert(a,b);
        }  
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,visited);
        }
    }
    int result=0;
    for(int i=1;i<=n;i++){
        for(auto v=adj[i].begin();v!=adj[i].end();++v){
            if(adder[*v]){
                result++;
            }
        }
    }
        cout<<result<<endl;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
    return 0;
}

