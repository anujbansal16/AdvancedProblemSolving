#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Node1 Node;
struct Node1{
    Node *childs[26];
    int count;
};

void insert(Node * root, string s){
    Node *temp=root;
    Node *child;
    for(int i=0;i<s.size();i++){
        child=temp->childs[s[i]-'a'];
        if(child==NULL){
            child=(Node*)malloc(sizeof(Node));
            child->count=1;
            for(int j=0;j<26;j++)
                child->childs[j]=NULL;
            temp->childs[s[i]-'a']=child;
        }
        else{
            child->count++;
        }
        temp=child;
    }
}
int search(Node *root, string s){
    Node *temp=root;
    Node * child;
    for(int i=0;i<s.size();i++){
        child=temp->childs[s[i]-'a'];
        if(child==NULL)
            return 0;
        temp=child;
    }
    if(temp==NULL)
        return 0;
    return temp->count;
}


int main() {
    int n,m;
    string s;
    cin>>n>>m;
    Node* root=(Node*)malloc(sizeof(Node));
    for(int i=0;i<26;i++)
        root->childs[i]=NULL;
    for(int i=0;i<n;i++){
        cin>>s;
        insert(root,s);
    }
    while(m--){
        cin>>s;
        cout<<search(root,s)<<"\n";
    }
    return 0;
}

