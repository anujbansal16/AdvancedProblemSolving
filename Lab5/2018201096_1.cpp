#include<bits/stdc++.h>
using namespace std;
typedef int  l;
int main() {
    ios::sync_with_stdio(false);
    l n,t,count=0;
    string s;
    cin>>s;
    for (int i = 0; i < s.size()-1;i++)
    {
        for (int j = i+1; j < s.size(); j++)
        {   
            for (int k = i, m=j;;k++,m--)
            {   
                if(s[k]!=s[m]) break;
                if(k==m||k>m){count++;break;}
            }
        }
    }
    cout<<count+s.size();
    return 0;
}


