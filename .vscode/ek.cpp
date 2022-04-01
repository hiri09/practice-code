#include<bits/stdc++.h>
using namespace std;
void fun(vector<pair<char,char>> v){
    unordered_map<char,int> st;
    for(int i=0;i<v.size();i++){
        char a=v[i].first;
        char b=v[i].second;
        if(a==b){
            continue;
        }
        if(st.find(b)!=st.end()){
            if(st.find(a)!=st.end()){
                st[b]=st[b]+st[a]+1;
            }
            else{
                st[b]=st[b]+1;
            }
        }
        else{
            st[b]=1;
            if(st.find(a)!=st.end()){
                st[b]=st[a]+1;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        char a=v[i].first;
        if(st.find(a)!=st.end()){
            continue;
        }
        else{
            st[a]=0;
        }
    }
    vector<pair<char,int>> p;
    for(auto data: st){
        //cout<<data.first<<" "<<data.second<<endl;
        p.push_back({data.first,data.second});
    }
    sort(p.begin(),p.end());
    for(auto data: p){
        cout<<data.first<<" "<<data.second<<endl;
        //p.push_back({data.first,data.second});
    }
}
void fun1(vector<pair<string,string>> &v){
    unordered_map<string,int> st;
    for(int i=0;i<v.size();i++){
        st[v[i].first]++;
        st[v[i].second]++;
    }
    
    unordered_map<string,string> s;
    for(int i=0;i<v.size();i++){
        s[v[i].first]=v[i].second;
    }
    for(int i=0;i<v.size();i++){
        string a="bombay";
        string b=s[a];
        cout<<a<<"-"<<b<<endl;
       
    }
}
int fun2(int n,vector<int> &dp){
    /*if(n<=1){
        return 1;
    }
    int res=0;
    if(dp[n]>0){
        return dp[n];
    }
    for(int i=0;i<n;i++){
        
       res+=fun2(i,dp)*fun2(n-1-i, dp);
    }
    dp[n]=res;
    return res;*/
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<dp.size();i++){
        int res=0;
        int p=0;
        int q=i-1;
        while(p!=i){
            res+=dp[p]*dp[q];
            p++;
            q--;
        }
        dp[i]=res;
    }
    return dp[dp.size()-1];
}
int fun3(int n,int idx){

    if(idx==n){
        return 0;
    }
    if(idx>n){
        return INT16_MAX;
    }
    
    int a=1+fun3(n,idx+1);
    int b=INT_MAX;
    if(idx>=1){
        b=1+fun3(n,idx*2);
    }
    return min(a,b);
}
int fun4(vector<int> arr,int n,int k,int idx){  
     if(idx==n && k==0){
         return 0;
     }
     if(k<0){
         return INT_MAX;
     }
     if(idx==n && k>0){
         return INT16_MAX;
     }
     int a=1+fun4(arr,n,k-arr[idx],idx+1);
     int b=fun4(arr,n,k,idx+1);
     return min(a,b);
}
int main()
{
	
	int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    int target;
    cin>>target;
    fun4(arr,n,target,0);
    
	return 0;
}










