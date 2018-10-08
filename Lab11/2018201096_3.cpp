#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long n;
    cin>>n;
    vector<bool> a(n+1,true);
    for(long i=2;i<=n;i++){
        for(long j=i;j<=n;j+=i){
            a[j]=!a[j];
        }
    }
    int count=0;
    for(long i=1;i<=n;i++){
        if(a[i])
            count++;
    }
    cout<<count;
    return 0;
}

