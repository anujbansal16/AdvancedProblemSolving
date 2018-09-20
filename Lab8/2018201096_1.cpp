#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long l;

l myfind(long x[],l n){
    l z=0;
    do { 
        z=0;
            for(l a =0;a<3;a++){
                for(l b =0;b<3;b++){
                    for(l c =0;c<3;c++){
                        for(l d =0;d<3;d++){
                            if(a%3==0){
                                z=x[0]+x[1];    
                            }
                            else if(a%3==1){
                                z=x[0]-x[1];    
                            }
                            else{
                                z=x[0]*x[1];    
                            }
                            if(b%3==0){
                                z=z+x[2];    
                            }
                            else if(b%3==1){
                                z=z-x[2];    
                            }
                            else{
                                z=z*x[2];    
                            }
                            if(c%3==0){
                                z=z+x[3];    
                            }
                            else if(c%3==1){
                                z=z-x[3];    
                            }
                            else{
                                z=z*x[3];    
                            }
                            if(d%3==0){
                                z=z+x[4];    
                            }
                            else if(d%3==1){
                                z=z-x[4];    
                            }
                            else{
                                z=z*x[4];    
                            }
                            if(z==n)
                                return true;
                        }
                    }
                }
            }
    }while (next_permutation(x,x+5));
    return false;
}

int main() {
    long t,n;
    cin>>t;
    long a[5];
    while(t--){
        for(long i=0;i<5;i++)
            cin>>a[i];
        cin>>n;
        sort(a,a+5);
        myfind(a,n)?cout<<"Possible\n":cout<<"Impossible\n";
    }
    return 0;
}

