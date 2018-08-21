#include<bits/stdc++.h>
using namespace std;
typedef long l;
int main() {
    l n,m,temp,count;
    cin>>n>>m;
    l a[m]; l res[n+1];
    for(l i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m);
    memset(res,0,sizeof(res));
    res[0]=1;
    for(l i=0;i<m;i++){        
        for(l j=a[i];j<=n;j++){
                res[j]=res[j]+res[j-a[i]];
        }
    }
    cout<<res[n];
    return 0;
}
