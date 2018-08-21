#include<bits/stdc++.h>
using namespace std;
typedef long l;
int main() {
        l n,mx,mn,temp;
    l a=-100000000;
    l b=0;
    l c=100000000;
    l d=0;
    while(cin>>n){
        b+=n;
        if(b>a)
            a=b;
        if(b<0)
            b=0;
        d+=n;        
        if(d<c)
            c=d;
        if(d>0)
            d=0;
        

    }
    cout<<a<<"\n"<<c;

    return 0;
}

