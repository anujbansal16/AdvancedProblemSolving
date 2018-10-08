#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long l;
bool comp(pair<l,l> i, pair<l,l> j){
    return j.second>i.second;
}

int main() {
    l t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        vector< pair<l,l> > a;
        for(l i=0;i<n;i++){
            cin>>x>>y;
            a.push_back(make_pair(x,y));
        }
        sort(a.begin(),a.end(),comp);
        bool visited[n+7]={false};
        l ashC=0,count=0;
        l rC=0;
        l i=0;
        l res1=0,res2=0;
        l eTime=0;
        bool isFirst=true;
        bool turn=true;//ash turn as true
        while(count!=n){
            if(i==n){
                turn=!turn;
                i=0;
                isFirst=true;
                // cout<<ashC<<" "<<rC<<endl;
                res1=res1^ashC;
                res2=res2^rC;
                ashC=0;
                rC=0;
            }
            if(turn){
                
                if(isFirst&&!visited[i]){
                    // cout<<"ash "<<i<<endl;
                    visited[i]=true;
                    ashC+=1;
                    eTime=a[i].second;
                    count++;
                    isFirst=false;
                }
                else if((!visited[i])&&(a[i].first>eTime)){
                    // cout<<"ash1 "<<i<<endl;
                    eTime=a[i].second;
                    visited[i]=true;
                    ashC+=1;
                    count++;
                }   
            }else{
                
                if(isFirst&&!visited[i]){
                    // cout<<"rah "<<i<<endl;
                    visited[i]=true;
                    rC+=1;
                    eTime=a[i].second;
                    count++;
                    isFirst=false;
                }
                else if((!visited[i])&&(a[i].first>eTime)){
                    // cout<<"rah1 "<<i<<endl;
                    eTime=a[i].second;
                    visited[i]=true;
                    rC+=1;
                    count++;
                }   
            }
            i++;
        }
        // cout<<ashC<<" "<<rC<<endl;
        res1=res1^ashC;
        res2=res2^rC;
        if(res1>res2)
            cout<<"Ashwini\n";
        else if(res2>res1)
            cout<<"Rahil\n";
        else
            cout<<"Tie\n";
    }
    return 0;
}

