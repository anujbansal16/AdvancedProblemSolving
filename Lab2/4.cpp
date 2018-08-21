#include<bits/stdc++.h>
using namespace std;
int main() {
        long t,n,m,x,y,temp,k,count;
    cin>>t;
    while(t--){
        count=0;
        cin>>n>>m;
        long a[n],b[m];
        for(long i=0;i<n;i++)
            cin>>a[i];
        for(long i=0;i<m;i++)
            cin>>b[i];
        cin>>k;
        x=0;y=0;
        while((x!=n)&&(y!=m)&&count!=k){
            if(a[x]<b[y]){
                temp=a[x];x++;}
            else{
                temp=b[y];y++;}
            count++;
        }
        if(count==k)
            cout<<temp<<"\n";
        else if(x!=n)
            cout<<a[x+k-count-1]<<"\n";
        else
            cout<<b[y+k-count-1]<<"\n";
        
                
    }
    
        
    return 0;
}

