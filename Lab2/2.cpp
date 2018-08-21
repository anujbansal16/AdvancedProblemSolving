#include<bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin>>n;
    long long a[n],temp=0;
    long long res[n];
    memset(res,0,sizeof(res));
    for(long long i=0;i<n;i++)
            cin>>a[i];
    for(long long i=n-1;i>=0;i--){
        if(a[i]>temp)
            res[i]=1;
        else
            res[i]=0;
        temp=max(temp,a[i]);
    }
    for(long long i=0;i<n;i++)
        cout<<res[i]<<" ";
    return 0;
}

