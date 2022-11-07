#include<bits/stdc++.h>
using namespace std;
/*int fun(vector<int> &v,int n){
    int count=0;
    vector<int>r(n);
    int mx=INT16_MIN;
    int mn=INT16_MAX;
    for(int i=n-1;i>=0;i--){
        mn=min(mn,v[i]);
        r[i]=mn;
    }
    r.push_back(1e9);
    for(int i=0;i<n;i++){
        mx=max(mx,v[i]);
        if(mx<=r[i+1]){
            count++;
        }
    }
    return count;
}
int solve(string s){
    int n=s.length();
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]=i;
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    int count=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        int idx=mp[s[i]];
        mx=max(mx,idx);
        if(i==mx){
            cout<<i<<endl;
            count++;
        }
    }
    cout<<n<<endl;
    return count;
}
int solve(string s,string p){
    unordered_map<char,int> mp2;
    for(int i=0;i<p.length();i++){
        mp2[p[i]]++;
    }
    unordered_map<char,int>mp1;
    int i=0;
    int j=-1;
    
}
int solve(vector<int>&v,int n,int k){
     
    sort(v.begin(),v.end());
    int count=0;
    int i=0;
    int j=n-1;
    while(i<j){
        int sum=v[i]+v[j];
        if(sum==k){
            if(i==0){
                count++;
            }
            if(i!=0 && v[i]!=v[i-1]){
                count++;
            }
            i++;
            j--;
        }
        if(sum>k){
            j--;
        }
        if(sum<k){
            i++;
        }
    }
    return count;
}*/
int to(vector<int>&v,int k,int idx){
    int n=v.size();
    int count=0;
    int p=idx+1;
    while(p+2<n){
        int i=p+1;
        int j=n-1;
        if(p!=idx+1 && v[p]==v[p-1]){
            p++;
        }
        else{
            while(i<j){
                
                if(v[p]+v[i]+v[j]==k){
                  if(i==p+1){
                    cout<<idx<<" "<<p<<" "<<i<<" "<<j<<endl;
                    count++;
                  }
                  if(i!=p+1 && v[i]!=v[i-1]){
                    cout<<idx<<" "<<p<<" "<<i<<" "<<j<<endl;
                    count++;
                  }
                  i++;
                  j--;
                }
                if(v[p]+v[i]+v[j]>k){
                  j--;
                }
                if(v[p]+v[i]+v[j]<k){
                  i++;
                }
            }
            p++;
        }  
    }
    return count;
}
int solve(vector<int>&v,int n,int k){
    sort(v.begin(),v.end());
    int i=0;
    int count=0;
    while(i<=v.size()-4){
        count+=to(v,k-v[i],i);
        i++;
    }
    return count;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_map<string,int> mp;
        for(auto it:wordList){
            if(it!=beginWord){
                mp[it]++;
            }
        }
        while(!q.empty()){
            string s=q.front().first;
            int b=q.front().second;
            q.pop();
            //cout<<s<<endl;
            if(s==endWord){
                return b;
            }
            for(int i=0;i<s.length();i++){

                for(char j='a';j<='f';j++){
                    s[i]=j;
                    cout<<s<<endl;
                    if(mp.find(s)!=mp.end()){
                        q.push({s,b+1});
                        mp.erase(s);
                    }
                }
            }
        }
        return 0;
}
/*beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]*/
int dhinchakpooja(int n,vector<int> out[],vector<int>in[],vector<int>&vis,int src,int dest){
    queue<pair<int,int>> q;
    q.push({src,0});
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        if(a==dest){
            break;
        }
        for(auto it:out[a]){
           if(vis[it]>b){
             vis[it]=b;
             q.push({it,b});
           }
        }
        for(auto it:in[a]){
           if(vis[it]>b+1){
             vis[it]=b+1;
             q.push({it,b+1});
           }
        }
    }
    return vis[dest];
}
void solving(vector<vector<int>>&v,int n,int src,int dest){
    vector<int>out[n];
    vector<int>in[n];
    for(int i=0;i<v.size();i++){
        out[v[i][0]].push_back(v[i][1]);
        in[v[i][1]].push_back(v[i][0]);
    }
    vector<int> vis(n,1e9);
    vis[src]=0;
    cout<<dhinchakpooja(n,out,in,vis,src,dest);
}
vector<vector<int>> merge(vector<vector<int>>&v){
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
    ans.push_back({v[0][0],v[0][1]});
    for(int i=1;i<n;i++){
       int p1=ans[ans.size()-1][0];
       int p2=ans[ans.size()-1][1];
       int f1=v[i][0];
       int f2=v[i][1];
       if(p2>f1){
          ans.pop_back();
          ans.push_back({p1,max(p2,f2)});
       }
       else{
         ans.push_back({f1,f2});
       }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return ans;
}
//"145"  "234" A C G T
void prob(string s,string e,vector<string>&v){
    unordered_map<string,int>mp;
    for(string it:v){
        mp[it]++;
    }
    queue<vector<string>> q;
    vector<vector<string>> ans;
    int mx=INT_MIN;
    q.push({s});
    while(!q.empty()){
        vector<string>p=q.front();
        q.pop();
        string traverse=p[p.size()-1];
        mp.erase(traverse);
        if(traverse==e){
            if(mx>p.size()){
                mx=p.size();
            }
            if(p.size()==mx){
                ans.push_back(p);
            }
        }
        for(int i=0;i<traverse.length();i++){
            string d=traverse;
            for(char j='a';j<='z';j++){
                d[i]=j;
                vector<string> temp=p;
                if(mp.find(d)!=mp.end()){
                    temp.push_back(d);
                    q.push(temp); 
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
int romrom(vector<int>&v,int k,int idx){
    if(idx==0){
        if(k%v[0]==0){
            return k/v[0];
        }
        else{
            return 1e9;
        }
    }
    int nottake=0+romrom(v,k,idx-1);
    int take=INT_MAX;
    if(v[idx]<=k){
        take=1+romrom(v,k-v[idx],idx);
    }
    return min(take,nottake);
}
int romrom1(vector<int>&v,int k,int idx){
   /*
    if(idx==0){
        if(k%v[0]==0){
            return 1;
        }
        return 0;
    }
    int nottake=romrom1(v,k,idx-1);
    int take=0;
    if(v[idx]<=k){
        take=romrom1(v,k-v[idx],idx);
    }
    return take+nottake;*/

    vector<vector<int>> ans(v.size(),vector<int>(k+1));

    for(int i=0;i<k+1;i++){
        if(i%v[0]==0){
            ans[0][i]=1;
        }
    }
    for(int i=1;i<v.size();i++){
        for(int j=0;j<k+1;j++){
            int nottake=ans[i-1][j];
            int take=0;
            if(v[i]<=j){
                take=ans[i][j-v[i]];
            }
            ans[i][j]=take+nottake;
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<k+1;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans[v.size()-1][k];
}
int longestcoomonsubsequences(string s,string p,int i,int j){
   /*
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1]==p[j-1]){
        return dp[i][j]=1+longestcoomonsubsequences(s,p,i-1,j-1,dp);
    }
    
    return dp[i][j]=max(longestcoomonsubsequences(s,p,i-1,j,dp),longestcoomonsubsequences(s,p,i,j-1,dp));*/
    int n=s.length();
    int m=p.length();
   vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
   for(int i=0;i<=n;i++){
     dp[i][0]=0;
   }
   for(int j=0;j<=m;j++){
     dp[0][j]=0;
   }
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==p[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
   }
   for(int i=0;i<=n;i++){
    for(j=0;j<=m;j++){
        cout<<dp[i][j]<<" ";
        }
        cout<<endl;
   }
   return dp[n][m];
    
}
int problemoftheday(vector<string>&v){
    int n=v.size();
    unordered_map<string,int> f;
    unordered_map<string,int> t;
    
    for(auto it:v){
        f[it]++;
    }
    for(auto it:v){
        string p=it;
        string s=it;
        reverse(s.begin(),s.end());
        if(p!=s && f.find(s)!=f.end()){
            t[p]++;
            f[p]--;
            if(f[p]==0){
                f.erase(p);
            }
            f[s]--;
            if(f[s]==0){
                f.erase(s);
            }
        }
    }
    cout<<endl;
    cout<<endl;
    for(auto it:f){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    for(auto it:t){
        cout<<it.first<<" "<<it.second<<endl;
    }
    int count=0;
    bool flag=true;
    for(auto it:f){
        string s=it.first;
        reverse(s.begin(),s.end());
        if(s==it.first){
            int a=f[it.first];
            if(a%2==0){
                count+=(a/2);
            }
            else{
                flag=false;
                count+=(a/2);
            }
        }
    }
    int sum=0;
    for(auto it:t){
        sum+=(4*it.second);
    }
    if(flag==false){
        count=(count*4)+2;
    }
    else{
        count=count*4;
    }
    return count+sum;
    
}
//["em","pe","mp","ee","pp","me","ep","em","em","me"]
int longestPalindrome(vector<string>&v){
    unordered_map<string,int>mp;
    int n=v.size();
    for(auto it:v){
        mp[it]++;
    }
    int count=0;
    bool flag=true;
    for(auto it:mp){
        string s=it.first;
        reverse(s.begin(),s.end());
        if(s==it.first){
            int a=mp[it.first];
            if(a%2==0){
               count+=(a*2);
            }
            else{
                a=a-1;
                count+=(a*2);
                flag=false;
            }
        }
        else{
            if(mp.find(s)!=mp.end() && mp[s]>0 && mp[it.first]>0){
                int a=mp[it.first];
                int b=mp[s];
                if(a>b){
                    mp[it.first]=mp[it.first]-b;
                    mp[s]=0;
                }
                else{
                    mp[s]=mp[s]-a;
                    mp[it.first]=0;
                }
                count+=(4*(min(a,b)));
            }
        }
    }
    if(flag==false){
        count+=2;
    }
    return count;
}
string longestPalindrome(string s){
    string p=s;
    reverse(p.begin(),p.end());
    int n=s.length();
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        if(s[0]==p[i]){
            v[i][0]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(p[0]==s[i]){
            v[0][i]=1;
        }
    }
    int mx=INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(p[i]==s[j]){
                v[i][j]=1+v[i-1][j-1];
            }
        }
    }
    int idx;
    int jdx;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mx<v[i][j]){
                mx=v[i][j];
                idx=i;
                jdx=j;
            }
        }
    }
    cout<<idx<<" "<<jdx<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<idx<<" "<<jdx<<endl;
    string ans="";
    while(idx>=0 && jdx>=0 && v[idx][jdx]>0){
        //cout<<idx<<" "<<jdx<<endl;
        cout<<s[jdx];
        jdx--;
        idx--;
    }
    cout<<ans<<endl;
    return ans;
}

vector<string> generateParenthesis(int n){
    vector<vector<string>>dp;
    dp.push_back({""});
    //cout<<dp.size()<<endl;
    dp.push_back({"()"});
    for(int i=2;i<=n;i++){
        vector<string> ans;
        for(int j=0;j<i;j++){
            vector<string> t1=dp[j];
            vector<string> t2=dp[i-j-1];
            for(int k=0;k<t1.size();k++){
                string temp1=t1[k];
                for(int h=0;h<t2.size();h++){
                    string temp2=t2[h];
                    ans.push_back("(" + temp2 + ")" + temp1);
               }
            } 
        }
        dp.push_back(ans);
    }
    return dp[n];
}
//["((()))","(()())","(())()","()(())","()()()"]
bool canJump(vector<int>& arr){
    /*if(idx>=arr.size()){
        return false;
    }
    if(idx==arr.size()-1){
         return true;
    }
    if(arr[idx]==0){
        return false;
    }
    int max_jumpt=arr[idx];
    for(int i=1;i<=max_jumpt;i++){
        bool get=canJump(arr,idx+i);
        if(get==true){
            return true;
        }
    }
    return false;*/
  /* int n=arr.size();
    vector<bool> dp(n,false);
   dp[n-1]=true;
   for(int i=n-2;i>=0;i--){
        int max_jumpt=arr[i];
        for(int j=1;j<=max_jumpt;j++){
            if(i+j<n && arr[i]!=0){
                if(dp[i+j]==true){
                    dp[i]=true;
                }
            }
        }
   }
    return dp[0];
}
bool solve(vector<vector<char>> & board,string s,int i,int j,int k,vector<vector<bool>> &vis,int n,int m){  
       if(k==s.length()){
           return true;
       }
       if(i<0 || j<0 || i==n || j==m || board[i][j]!=s[k] || vis[i][j]==true){
           return false;
       }
       vis[i][j]=true;
       bool d=solve(board,s,i+1,j,k+1,vis,n,m);
       bool u=solve(board,s,i-1,j,k+1,vis,n,m);
       bool l=solve(board,s,i,j+1,k+1,vis,n,m);
       bool r=solve(board,s,i,j-1,k+1,vis,n,m);

       vis[i][j]=false;
       return d || u || l || r;
}
bool wordserach(vector<vector<char>> &v,string s){
    int n=v.size();
    int m=v.size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==s[0]){
                cout<<"HELP"<<endl;
                if(solve(v,s,i,j,0,vis,n,m)){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    string s;
    cin>>s;
    cout<<wordserach(v,s)<<endl;
    return 0;
}*/