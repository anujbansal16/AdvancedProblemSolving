#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l fact[1000007];
l pow(l a,l b,l MOD){
    l x=1,y=a; 
     while(b > 0){
        if(b%2 == 1){    
             x=(x*y);
             if(x>MOD) x%=MOD;
         }
         y = (y*y);
         if(y>MOD) y%=MOD; 
         b /= 2;
     }
    return x;
}
 
l inv(l n, l MOD){
    //euler formula to get inverse of n
     return pow(n,MOD-2,MOD);
}
 
l nCr(l n, l r, l MOD){
    //nCr%MOD= (((n!)/(r!))/(n-r)!)%MOD;
     return (fact[n]*((inv(fact[r], MOD)*inv(fact[n-r], MOD))% MOD)) % MOD;
}
 
int main() {
    l n,t,r,r1,r2;
    cin>>t;
    fact[0] = 1;
    for(int i=1;i<=1000007;i++)
        fact[i] = (fact[i-1]*i)%1000000007;
    while(t--){
        cin>>n>>r;     
        cout<<nCr(n,r,1000000007)<<"\n";
        
    }
    
    return 0;
}

