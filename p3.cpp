#include<bits/stdc++.h>
using namespace std;
class disjoint_set{
    public:
    vector<int>rank,parent,size;
    disjoint_set(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find_parent(parent[node]);
    }
    void make_union(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);

        if(ult_u==ult_v){
            return;
        }

        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }
    void make_size(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);

        if(ult_u==ult_v){
            return;
        }
        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
};
vector<int> solve(vector<vector<int>> &v){
    int n=v.size();
    disjoint_set ds(n);
    vector<int>ans(2);
    for(int i=0;i<n;i++){
        int a=v[i][0];
        int b=v[i][1];

        if(ds.find_parent(a)!=ds.find_parent(b)){
            ds.make_union(a,b);
        }
        else{
            ans[0]=a;
            ans[1]=b;
            ds.make_union(a,b);
        }
    }
    return ans;
}
int main(){
    cout<<"hello brother"<<endl;
    return 0;
}
/*
class disjoint_set{
    public:
    vector<int>rank,parent,size;
    disjoint_set(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int find_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find_parent(parent[node]);
    }
    void make_union(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);

        if(ult_u==ult_v){
            return;
        }

        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }
    void make_size(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);

        if(ult_u==ult_v){
            return;
        }
        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }

    }
};
bool compare(string a,string b){
    if(a[1]=='=' && b[1]=='!' ){
        return 1;
    }
    return 0;
}
bool solve(vector<string> &v){
    disjoint_set ds(26);
    sort(v.begin(),v.end(),compare);
    int f=0;
    for(int i=0;i<v.size();i++){
        string s=v[i];
        if(s[1]=='='){
            ds.make_union(s[0]-97,s[3]-97);
        }
        else{
            if(ds.parent[s[0]-97]==ds.parent[s[3]-97]){
                f=1;
                break;
            }
        }
    }
    if(f==1){
        return 0;
    }
    return 1;
}*/

/*#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int>&v,int n,int i,int j,vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int mn=1e9;
    for(int k=i;k<j;k++){
       int steps=v[i-1]*v[k]*v[j] + mcm(v,n,i,k,dp) + mcm(v,n,k+1,j,dp);
       mn=min(mn,steps);
    }
    return dp[i][j]=mn;
}
int problemoftheday(int n){
    string s=to_string(n);
    //bool flag=true;
    for(int i=0;i<s.length();i++){
       if(s[i]=='6'){
          s[i]='9';
          //flag=false;
          break;
       }
    }
    int a=stoi(s);
    return a;

}
int lis(vector<int>&v,int idx,int pre_idx,vector<vector<int>> &dp){
    if(idx==v.size()){
        return 0;
    }
    if(dp[idx][pre_idx+1]!=-1){
        return dp[idx][pre_idx+1];
    }
    int notatke=0+lis(v,idx+1,pre_idx,dp);
    int take=-1e9;
    if(pre_idx==-1 || v[idx]>v[pre_idx]){
        take=1+lis(v,idx+1,idx,dp);
    }
    return dp[idx][pre_idx+1]=max(take,notatke);
}
int find_lis(vector<int>&v,int n){
    vector<int>dp(n);
    dp[0]=1;
    for(int i=1;i<n;i++){
        int mx=INT16_MIN;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                mx=max(mx,dp[j]);
            }
        }
        if(mx==INT16_MIN){
            dp[i]=1;
        }
        else{
            dp[i]=mx+1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    return 1;
}

int sol(int pre_idx,int idx,vector<int>&v){
    if(idx==v.size()){
        return 0;
    }
    int nt=0+sol(pre_idx,idx+1,v);
    int take=INT_MIN;
    if(pre_idx==-1 || v[idx]>v[pre_idx]){
        take=1 + sol(idx,idx+1,v);
    }
    return max(nt,take);
}
int lis_using_bs(vector<int>&v,int n){
    vector<int>temp;
    temp.push_back(v[0]);
    for(int i=0;i<n;i++){
        if(v[i]>temp.back()){
            temp.push_back(v[i]);
        }
        else{
            int idx=lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin();
            temp[idx]=v[i];
        }
    }
    return temp.size();
}
int find_bridges(vector<pair<int,int>>&v){
    int n=v.size();
    sort(v.begin(),v.end());
    vector<int>dp;
    dp.push_back(v[0].second);
    for(int i=1;i<v.size();i++){
        if(v[i].second > dp.back() && ){
            dp.push_back(v[i].second);
        }
        else{
            int idx=lower_bound(dp.begin(),dp.end(),v[i].second) - dp.begin();
            dp[idx]=v[i].second;
        }
    }
    return dp.size();
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    cout<<find_bridges(v)<<endl;
    return 0;
}
*/