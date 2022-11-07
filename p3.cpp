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
string solve(vector<int>&v,int n){
   set<int>st;
   for(auto it:v){
    st.insert(it);
   }
   


}
int main(){

    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    vector<int>p(m);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    int k;
    cin>>k;
    
    return 0;

}
