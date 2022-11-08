#include<bits/stdc++.h>
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
int main(){
   /* int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //cout<<lis(v,0,-1,dp);
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int notatke=0+dp[i+1][j+1];
            int take=-1e9;
            if(j==-1 || v[i]>v[j]){
                  take=1+dp[i+1][i+1];
            }
            dp[i][j+1]=max(take,notatke);
        }
    }
    cout<<dp[0][-1+1]<<endl;*/
    return 0;
}
