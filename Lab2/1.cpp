#include<bits/stdc++.h>
using namespace std;
int main() {
     long n,count=0,temp,temp2;
    cin>>n;
    long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;){
        //cout<<"i "<<i<<"\n";
        if(a[i]!=i){
            temp=a[i];
            a[i]=a[temp];
            a[temp]=temp;
            count++;
        }
        if(a[i]==i)
            i++;
    }
    cout<<count<<"\n";
    return 0;
}

