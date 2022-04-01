#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*int main(){
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(1);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    return 0;
}
struct node{
    int data;
    struct node* left;
    struct node*right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorder_traversal(struct node* root){
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);

}
void display(struct node* root){
    if(root==NULL){
        return;
    }
    string s="";
    if(root->left!=NULL){
       s+=to_string(root->left->data);
    }else{
        s+=".";
    }
    s+=" <-"+to_string(root->data) +"-> ";
    if(root->right!=NULL){
        s+=to_string(root->right->data);
    }
    else{
        s+=".";
    }
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}
void postorder_traversal(struct node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";

}
void inorder(struct node* root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int number_of_node(struct node* root,int count){
    if(root==NULL){
        return 0;
    }
    int a=number_of_node(root->left,count+1);
    int b=number_of_node(root->right,count+1);

    return a+b;
}*/
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};
void insert_attail(node* &head,int val){
    
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
        
    }
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    
}
void print(node* head){
    node* temp=head;
    //int count=1;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        //count++;
        temp=temp->next;
    }
    //cout<<count<<endl;
}
void insert_at_head(node* &head,int val){
    node* n=new node(val);
    
    n->next=head;
    head=n;

}
/*void delete_at_head(node* &head){
    node* todelete=head;
    head=head->next;
    
    delete todelete;
}*/
/*void dtelete_at_pt(node* &head ,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete_at_head(head);
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}*/
/*node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummy=new node(-1);

    node* p3=dummy;
    while(p1!=NULL && p2!=NULL){
        if(p1->data > p2->data){
            p3->next=p2;
            p2=p2->next;
        }
        else{
            p3->next=p1;
            p1=p1->next;

        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummy->next;
}*/
/*node* m(node* &head1,node* &head2){
    node* p1=head1;
    node* res=p1;
    
    node* p2=head2;
    while(p1!=NULL && p2!=NULL){
        node* temp= NULL;
        while(p1->data <= p2->data){
            temp=p1;
            p1=p1->next;
        }
        temp->next=p2;
        node* swp=p1;
        p1=p2;
        p2=swp;
    }
    return res;
}*/
/*node* naya(node* &head1,node* &head2){
    if(head1->data > head2->data){
        return m(head2,head1);
    }
    else{
        return m(head1,head2);
    }
}*/
node* naya(node* &head){
    node* preptr=NULL;
    node* cur=head;
    node* nxt;

    while(cur!=NULL){
        nxt=cur->next;
        cur->next=preptr;

        preptr=cur;
        cur=nxt;
        
    }
    return preptr;
}
node* middle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* head(node* &head,int n){
    node* dummynode= new node(-1);
    dummynode->next=head;
    node* slow= dummynode;
    node* fast= dummynode;
    for(int i=0;i<=n;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=slow->next->next;
    return dummynode->next;

}
node* reverse_half(node* &head){
    node* pre=NULL;
    node* nxt=NULL;
    while(head!=NULL){
        nxt=head->next;
        head->next=pre;

        pre=head;
        head=nxt;
    }
    return head;
}
int length(node* head){
    node* p=head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
node* merge(node* &head){
    
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL ){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverse_half(slow->next);
    slow=slow->next;
    node* p1=head;
    node* temp=head->next;
    node* p2=slow->next;
    
    int l1=length(head);
    if(l1%2!=0){
        while (slow!=NULL )
        {
           p1->next=slow;
           slow->next=temp;
           p1=temp;
           temp=temp->next;

           slow=p2;
           p2=p2->next;
        }
        p1->next=NULL;
           
    }
    else{
        while (slow->next!=NULL )
        {
            p1->next=slow;
            slow->next=temp;
            p1=temp;
            temp=temp->next;

            slow=p2;
            p2=p2->next;
        }
        slow->next=NULL;

    }

}
int main(){
    node* head1= NULL;
    //node* head2= NULL;

    insert_attail(head1,1);
    insert_attail(head1,2);
    insert_attail(head1,3);
    insert_attail(head1,4);
    insert_attail(head1,5);
    print(head1);
    //node* newhead= naya(head1);
    //print(newhead);

    //node* nok= middle(head1);
    //print(nok);
    //cout<<nok->next->data<<endl;
    return 0;
}
