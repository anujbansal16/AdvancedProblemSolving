#include<bits/stdc++.h>
using namespace std;
typedef long  l;
int dist(string s1,string s2,int a, int b){
            int res[s1.size()+1][s2.size()+1];
            memset(res,0,sizeof(res));
            for (int i = 0; i <= s2.size(); ++i)
            {
                res[0][i]=i;
            }
            for (int i = 0; i <= s1.size(); ++i)
            {
                res[i][0]=i;
            }
            for (int i = 1; i <= s1.size(); ++i)
            {
                for (int j = 1; j <= s2.size(); ++j)
                {
                    if(s1[i-1]==s2[j-1])
                        res[i][j]=res[i-1][j-1];
                    else
                        res[i][j]=1+min(min(res[i][j-1],res[i-1][j]),res[i-1][j-1]);
                }
            }
            return res[s1.size()][s2.size()];

}
int main() {
    ios::sync_with_stdio(false);
    l n,t,count1,count2;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<dist(s1,s2,s1.size(),s2.size())<<endl;
    }
        return 0;
}


