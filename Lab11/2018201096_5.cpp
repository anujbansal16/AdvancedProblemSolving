#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int a[30][30],int res[30][30], int x, int y, int n){
    for(int i=x;i<n;i++){
        for(int j=y;j<n;j++){
            int temp1=0,temp2=0,temp3=0;
            if(i-1>=0){
                temp1=a[i-1][j]+a[i][j];
                if(j-1>=0)
                    temp2=a[i-1][j-1]+a[i][j];
                if(j+1<n)
                    temp3=a[i-1][j+1]+a[i][j];
                a[i][j]=max(temp1,max(temp2,temp3));
        
            }       
        }
        
    }   
    int tem=0;
    for(int i=0;i<n;i++)
        tem=max(tem,a[n-1][i]);
    return tem;
        
}

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[30][30];
        int res[30][30];
        int res2[30][30];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                res[i][j]=a[i][j];
                res2[i][j]=a[i][j];
            }
        }
        int reslt=0;
            reslt=max(reslt,solve(a,res2,0,0,n));   
            cout<<reslt<<endl;
        }
    return 0;
}

