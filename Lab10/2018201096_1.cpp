#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
unordered_map<int,int> mymap[10006];
void solve(int arr[],int MOD, int n){
    mymap[0][arr[0]%MOD] =0;
    unordered_map<int,int>::iterator it;
    int v = 0;
    for(int i = 0; i<n - 1; i++){
        for(it = mymap[i].begin(); it != mymap[i].end(); ++it){
            v = (it->first + arr[i + 1])%MOD;
            mymap[i + 1][v]=it->first;
            v = (it->first-arr[i + 1]+MOD)%MOD;
            mymap[i + 1][v]=it->first;
        }
    }
    if ( mymap[n-1].find(0) != mymap[n-1].end() ) {
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main() {
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        solve(a,k,n);
        for(int i = 0; i < n; ++ i)
            mymap[i].clear();
    }
    return 0;
}

