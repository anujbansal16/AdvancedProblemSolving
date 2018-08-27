#include<bits/stdc++.h>
using namespace std;
typedef long  l;
int main() {
    ios::sync_with_stdio(false);
    l n,t;
    cin>>t;
    while(t--){
    cin>>n;
    l a[n];
    l mx=0;
    for(l i=0;i<n;i++)
        cin>>a[i];

    for(l i=0;i<(n-mx);i++){
        l j=i;l k=n-1;
        for(;(k-j)>mx;k--){
            //if((k-j)<mx) break;
            if(a[j]<=a[k]){
                mx=(mx>(k-j)?mx:k-j);
            }

        }
    }
    cout<<mx<<"\n";
}
   
    return 0;
}

