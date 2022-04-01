/*#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* right;
    struct node* left;

    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    struct node* root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
void iterativePrePostInTraversal(node* root) {
  // write your code here
  
  stack<pair<node*,int>> st;
  
  st.push({root,1});
  string pre=" ";
  string in=" ";
  string post=" ";
  while(st.size()>0){
      node* p=st.top().first;
      int q=st.top().second;
      if(q==1){
         pre+=to_string(p->data)+" ";
         q++;
         st.push({p,q});
         if(p->left!=NULL){
             st.push({p->left,1});
         }
      }
      if(q==2){
         in+=to_string(p->data)+" ";
         q++;
         st.push({p,q});
         if(p->right!=NULL){
             st.push({p->right,1});
         }
      }
      if(q==3){
         post+=to_string(p->data)+" ";
         st.pop();
      }
  }
}

int main(){
 /*   
    int arr[]={50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    treenode* root=new treenode(arr[0]);
    Pair* rp=new Pair(root,1);
    stack<treenode*> st;
    st.push(rp);
*/
    node* root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    iterativePrePostInTraversal(root);
    

    return 0;
}
// Note that by default C++ creates a max-heap
// for priority queue

int main()
{
	
	int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        v.push_back({a,b});
    }
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
	return 0;
}












