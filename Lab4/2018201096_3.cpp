#include<bits/stdc++.h>
using namespace std;
typedef long long l;

int main() {
    l ten=10;
    set <string> res;
    string s;
    map <string,bool> hash;
    cin>>s;
    l slen=s.size();
    for(l i=0;i<=slen-ten;i++){
            string s1=s.substr(i,10);
            if(hash.find(s1)==hash.end())
                hash[s1]=true;
            else{
                if(hash[s1]==true)
                    res.insert(s1);
            }
        
    }
    for (std::set<string>::iterator i = res.begin(); i != res.end(); ++i)
    {
        cout<<*i<<" ";
    }

    
    return 0;
}

