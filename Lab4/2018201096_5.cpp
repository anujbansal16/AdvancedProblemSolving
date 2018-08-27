#include<bits/stdc++.h>
using namespace std;
void printLL(struct node* head);
struct node{
    int val;
    node* next;
};

struct node* reverseK(struct node* head, int k){
    struct node* cur=head;
    int j=0,m=0;
    struct node* temp,*temp1, *final;
    struct node* nxt=NULL;struct node* pre=NULL;
    while(cur!=NULL){
        temp=cur;
        j++;
        m++;
        for(long i=0;i<k;i++){
            if(cur!=NULL){
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;}
        }
        if(j==1)
            final=pre;
        if(cur==NULL){
          temp->next=NULL;
          break;  
        } 
        temp1=cur;
        m=0;
        while(temp1->next!=NULL&&m<k-1){
            temp1=temp1->next;
            m++;
        }
        temp->next=temp1;
    }
return final;

}

void printLL(struct node* head){
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }
    return;
}
int main() {
    struct node* head = new node();
    struct node* insert = head;
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int temp;
        cin >> temp;
        struct node* data = new node();
        data->val = temp;
        insert->next = data;
        insert = insert->next;
        
    }
    head = head->next;
    int k;
    cin >> k;
    struct node* head_after_reversal = reverseK(head, k);
    printLL(head_after_reversal);
    return 0;
}