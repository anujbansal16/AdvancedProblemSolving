#include<bits/stdc++.h>
using namespace std;
typedef long long l;
int main() {
    l n,q,num,x,y,sum=0;
    cin>>n>>q;
    l a[n];
    l r[n];
    for(l i=0;i<n;i++)
        cin>>a[i];
    r[0]=a[0];
    for(l i=1;i<n;i++)
        r[i]=r[i-1]+a[i];
    while(q--){
        cin>>x>>y;
        sum=r[y]-r[x]+a[x];
        cout<<sum<<"\n";
    }
    return 0;
}

