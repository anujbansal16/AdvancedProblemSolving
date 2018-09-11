#include<bits/stdc++.h>
using namespace std;
typedef long long  l;
int main() {
    //ios::sync_with_stdio(false);
    l n1,n2,t,count;
    cin>>t;
    while(t--){
        cin>>n1>>n2;
        count=0;
        bool prime[n2+1];
        //l result[n2+1];
        memset(prime,true,sizeof(prime));
        prime[0]=false;
        prime[1]=false;
        //memset(result,0,sizeof(result));
        for(l i=2;i<=(n2);i++){
            if(prime[i]){
                for(l j=2*i;j<=n2;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(l k=n1;k<=n2;k++)
        {
                if(prime[k])
                    count+=k;
        }
        cout<<count<<"\n";
    }
   
    return 0;
}


