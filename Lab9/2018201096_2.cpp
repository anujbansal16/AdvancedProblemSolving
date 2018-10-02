#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,t,count=0;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        char a[n+2];
        char b[n+2];
        
        for(int i=0;i<n;i++){
            cin>>s;
            a[i]=s[0];
            b[i]=s[s.size()-1];
        }
        int k,res=0;
       for(int i=0;i<n;i++){
           bool check[n+2]={false};
           k=i;
            check[k]=true;
           count=0;
           for(int j=0;j<n;j++){
               if(j==k&&check[j])
                   continue;
               if(b[k]==a[j]){
                   if(!check[j]){
                        k=j;
                        check[j]=true;
                        j=-1;
                        count++;    
                   }
                   else
                       break;
               }
           }
           res=max(res,count);
       }
        if(res+1==n)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        }

    return 0;
}

