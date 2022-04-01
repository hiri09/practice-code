#include<bits/stdc++.h>
using namespace std;
/*
int fun2(int n,vector<pair<int,int>> &p){
    
    vector<int> v;
    for(auto k:p){
        v.push_back(k.second-k.first);
    }
    for(int i=1;i<n;i++){
        v[i]=v[i]+v[i-1];
    }
    int mn=INT16_MIN;
    for(auto p:v){
        mn=max(p,mn);
    }
    return mn;
}*/
/*


void fun6(int n,vector<int> &v){
    
    int i=1;
    int count=1;
    int mv=INT_MIN;
    for(auto p:v){
        cout<<p<<" ";
    }
    cout<<endl;
    while(i<n){
        cout<<v[i]<<" "<<endl;
       if(v[i]>v[i-1]){
           count++;
       }
       else if(v[i]<v[i-1]){
           mv=max(count,mv);
           count=0;
       }
       i++;
    }
    
    cout<<mv<<endl;
}*//*
int fun3(int n,int a){

    while(a!=0){
        int p=n%10;
        if(p!=0){
           n--;
        }
        else if(p==0){
            n=n/10;
        }
        a--;
    }   
    return n;
}*/
int fun4(int k,int n,int w){
    vector<int> v;
    for(int i=1;i<=w;i++){
        v.push_back(i*k);
    }
    int sum=0;
    for(auto p:v){
        sum+=p;
    }
    if(sum<n){
        return 0;
    }
    else{
        return sum-n;
    }
}
void fun5(string s){
    unordered_map<char,int> mp;

    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }   
    if(mp.size()%2!=0){
        cout<<"IGNORE HIM!"<<endl;
    }
    else{
        cout<<"CHAT WITH HER!"<<endl;
    }
}
void fun(int n){
    
    int a=n;
    int count=0;
    while(n!=0){
        count++;
        n=n/10;
    }
    int c=pow(10,count);
    //bool flag=0;
    int s=10;
    int p=1;
    int ans=0;
    while(s!=(c*10)){
        int digit=(a%s)/p;
        cout<<digit<<" ";
        if(digit==4 || digit==7){
            ans++;
        }
        
    }
    if(ans==4 || ans==7){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}
void decimaltobinary(int n){
    vector<int> v;
    while(n>0){
        int r=n%2;
        v.push_back(r);
        n=n/2;
    }
    for(auto t:v){
        cout<<t<<" ";
    }
}/*
4
3
2 4 3
4
3 2 3 1
2
69 69
6
719313 273225 402638 473783 804745 323328

*/
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<k<<" ";
        for(int i=1;i<k;i++){
            cout<<i<<" ";
        }
    }
    return 0;
}








