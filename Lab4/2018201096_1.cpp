#include<bits/stdc++.h>
using namespace std;
typedef long  l;
int main() {
    ios::sync_with_stdio(false);
    l n,t,num1,num2,index1,index2,count;
    cin>>t;
    while(t--){
        count=0;
    cin>>n;
    //map <l,l> hash;
    l hash[200007];
    l a[2*n];
    for(l i=0;i<2*n;i++){
        cin>>a[i];
        hash[a[i]]=i;
    }
    for(l i=0;i<2*n;i+=2){
        if(a[i]%2){
            if(hash[a[i]-1]==i+1) continue;
            count++;
            num1=a[i]-1;//0
            num2=a[i+1];//3
            index1=hash[num1];//4
            index2=i+1;//1
            a[hash[num1]]=num2;
            a[i+1]=num1;
            hash[num1]=i+1;
            hash[num2]=index1;
        }else{
            if(hash[a[i]+1]==i+1) continue;
            count++;
            num1=a[i]+1;//0
            num2=a[i+1];//3
            index1=hash[num1];//4
            index2=i+1;//1
            a[hash[num1]]=num2;
            a[i+1]=num1;
            hash[num1]=i+1;
            hash[num2]=index1;
        }
        
    }
    cout<<count<<"\n";
}
   
    return 0;
}

