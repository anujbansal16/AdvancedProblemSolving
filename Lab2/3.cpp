#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,x,q;bool flag;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>q;
    sort(a,a+n);
    while(q--){
         flag=false;
        cin>>x;
           for(int left=0,right=n-1;left<right;){
        //cout<<"left"<<left<<"\n";
        //cout<<"right"<<right<<"\n";
        if((a[left]+a[right])==x){
            flag=true;
            break;}
        if((x-a[left])>a[right])
            left++;
        else if((x-a[left])<a[right])
            right--;
                
        
    }
    
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
            
     
    }
        
    return 0;
}

