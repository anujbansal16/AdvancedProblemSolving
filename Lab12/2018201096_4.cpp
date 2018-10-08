#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef int l;
using namespace std;


int main() {
    l n,k,m=0,size=1,flag=0;
    cin>>n>>k;
    l a[n];
    for(l i=0;i<n;i++)
        cin>>a[i];
    vector< vector<l> > tradeVsDay(k+1,vector<l>(n+1));
    for (l i = 1; i <= k; i++) { 
        l temp = -9999; 
        for (l j = 1; j < n; j++) { 
            temp = max(tradeVsDay[i - 1][j - 1] - a[j - 1],temp); 
            if(tradeVsDay[i][j - 1]>a[j]+temp)
                tradeVsDay[i][j]= tradeVsDay[i][j - 1];
            else
                tradeVsDay[i][j] = a[j] + temp; 
        } 
    } 
    cout<<tradeVsDay[k][n-1]<<endl;
    return 0;
}

