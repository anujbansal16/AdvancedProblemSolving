#include<bits/stdc++.h>
using namespace std;
typedef long l;

int main() {
    l t,ans;
    string s;
    cin>>t;
    while(t--){
        ans=0;
        vector<l> st;
        st.push_back(-1);
        cin>>s;
        for(l i=0;i<s.size();i++){
                if(s[i]=='(')
                    st.push_back(i);
                else{
                    st.pop_back();
                    if(st.empty())
                        st.push_back(i);
                    else
                        ans=(ans>i-st.back())?ans:(i-st.back());
                }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}