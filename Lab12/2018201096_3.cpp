#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long l;
using namespace std;


int main() {
    long n,x,y;
    cin>>n;
    vector<l> a[n];
    map<l,l> hash;
    for(long i=0;i<n;i++){
        cin>>x>>y;
        a[i].push_back(x);
        a[i].push_back(y);
        hash[x]++;
    }
    sort(a,a+n);
    l result[n+2]={0};
    int temp=0;
    vector< pair<l,l> > result2(n);
    for(int i=0;i<n;i++){
            if(i-1>=0&&a[i][0]==a[i-1][0])
                temp++;
            else
                temp=0;
            l pos=a[i][1]-temp;
            // cout<<pos<<endl;
            l j=0;
            for(l k = 0; k < n ; k++){
                     if(j == pos){
                        while(result[k] != 0 && k < n - 1){
                            k++;
                        }
                        result2[k]=make_pair(a[i][0],a[i][1]);
                        result[k]=1;
                        break;
                    }
            if(result[k] == 0) j++;
           }
    }
    for(auto it=result2.begin();it!=result2.end();++it)
        cout<<(it->first)<<" "<<(it->second)<<"\n";
        
    return 0;
}

