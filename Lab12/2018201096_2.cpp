#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,d=0;
    cin>>n;
    vector<string> deads;
    map<string,bool> visited;
    string s;
    for(int i=0;i<=n;i++){
        cin>>s;
        if(i!=n)
            deads.push_back(s);
    }
    for(int i=0;i<n;i++ )
        visited[deads[i]]=true;
    string initial="0000";
    bool flag=false;
    queue<string> q;
    q.push(initial);
    q.push("m");
    while(!q.empty()){
        string frnt=q.front();
        q.pop();
        if(s==frnt){
            flag=true;
            break;
        }
        if(visited[frnt])
            continue;
        if(frnt=="m" && q.empty())
            break;
        if(frnt=="m"){
            d++;
            q.push("m");
        }
        else{
            visited[frnt]=true;
            string temp=frnt;
            temp[0]=(temp[0]=='9'?'0':temp[0]+1);
            q.push(temp);
            temp=frnt;
            temp[1]=(temp[1]=='9'?'0':temp[1]+1);
            q.push(temp);
            temp=frnt;
            temp[2]=(temp[2]=='9'?'0':temp[2]+1);
            q.push(temp);
            temp=frnt;
            temp[3]=(temp[3]=='9'?'0':temp[3]+1);
            q.push(temp);
            temp=frnt;
            temp[0]=(temp[0]=='0'?'9':temp[0]-1);
            q.push(temp);
            temp=frnt;
            temp[1]=(temp[1]=='0'?'9':temp[1]-1);
            q.push(temp);
            temp=frnt;
            temp[2]=(temp[2]=='0'?'9':temp[2]-1);
            q.push(temp);
            temp=frnt;
            temp[3]=(temp[3]=='0'?'9':temp[3]-1);
            q.push(temp);
            
        }
    }
    if(flag)
        cout<<d;
    else
        cout<<"-1";
    
    return 0;
}

