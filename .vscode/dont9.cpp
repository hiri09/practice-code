#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void square_pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void triangle1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void triangle2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void triangle3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<n-1-i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
void new_cross(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+j==n-1 || i==j){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void doblu(int n){

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i+j==i || j==n-1){
            cout<<"*";
        }
        if(i>=n/2 && (i>0 &&i<n-2)){
            if(i==j){
                cout<<"*";
            }
            else if(i+j==n-1){
                cout<<"*";
            }
        }
        else{
            cout<<" ";
        }
    }//wrong 
    cout<<endl;
}
}
void inversion(int arr[],int n){
    int p[n];
    for(int i=0;i<n;i++){
        int index=arr[i];
        p[index]=i;
    }   
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
void bar_graph_of_an_array(int arr[],int n){
    int mx=-99;
    for(int i=0;i<n;i++){
        if(mx<arr[i]){
            mx=arr[i];
        }
    }
    for(int i=mx;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i<=arr[j]){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void sum_array(int arr1[],int arr2[],int n,int m){
    int i=n-1;
    int j=m-1;
    int k=n-1;
    int arr3[k];
    int carry=0;
    int amount=0;
    while(i>=0 || j>=0){
       amount=arr1[i]+arr2[j]+carry;
       arr3[k]=amount%10;
       carry=amount/10;
       i--;
       j--;
       k--;
    }
    while(i>=0){
       amount=arr1[i]+carry;
       arr3[k]=amount%10;
       carry=amount/10;
       i--;
       k--;
    }   
    
    if(carry>0){
       cout<<carry;
    }
    for(int i=0;i<n;i++){
        cout<<arr3[i]<<" ";
    }
}
int decimal_to_binary(int n){
    int ans=0;
    int p=1;

    while(n>0){
        int r=n%2;
        int b=n/2;
        ans+=(r*p);
        p=p*10;
    }
    return ans;
}
bool ispallidrome(string s){
    for(int i=0;i<(s.length())/2;i++){
        if(s[i]!=s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}
string string_no_compression(string s){
    string p;
    p+=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!=s[i+1]){
           p+=s[i+1];   
        }
    }
    return p;
}
string string_compression(string s){
    string p;
    int count=1;
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            if(s[i]==s[j]){
                p+=s[j];
                
            }
            if(s[j]==s[j+1]){
                i++;
            }
        }
    }
    return p;
}
void subsequence11(string s ){

    string empty=" ";

}
void subsequence(int ind,vector<int> &ds,int arr[],int n){
    if(ind==n){
        for(int i=0;i<ds.size();i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
    }
    ds.push_back(arr[ind]);
    subsequence(ind+1,ds,arr,n);
    ds.pop_back();
    subsequence(ind+1,ds,arr,n);
}
void print(string s,string ans){
   if(s.length()==0){
       cout<<ans<<endl;
       return;
   }
   print(s.substr(1),ans+s[0]);
   print(s.substr(1),ans);
   
}
void printStairPaths(int n, string psf){
    // write your code here
    if(n==0){
        cout<<psf<<endl;
        return;
    }
    printStairPaths(n-1,psf+"1");
    printStairPaths(n-2,psf+"2");
    printStairPaths(n-3,psf+"3");
    
}
vector<string> get(int n){
    if(n<0){
        vector<string> base;
        
        return base;
    }
    if(n==0){
        
      vector<string> base;
      base.push_back("");
      return base;
    }
    
    vector<string>v1=get(n-1);
    vector<string>v2=get(n-2);
    vector<string>v3=get(n-3);
    
    vector<string> ans;
    for(int i=0;i<v1.size();i++){
        ans.push_back(v1[i]+"1");
    }
    for(int i=0;i<v2.size();i++){
        ans.push_back(v2[i]+"2");
    }
    for(int i=0;i<v3.size();i++){
        ans.push_back(v3[i]+"3");
    }
    return ans;
}

void floodfill(vector<vector<int>> &arr, int sr, int sc,string asf) {
    if(sr<0 || sr==arr.size() || sc<0 ||sc==arr[0].size() || arr[sr][sc]==1){
        return;
    }
    if(sr==arr.size()-1 && sc==arr[0].size()-1){
        cout<<endl;
        return;
    }
    arr[sr][sc]=1;
    floodfill(arr,sr-1,sc,+"t");
    floodfill(arr,sr,sc-1,+"l");
    floodfill(arr,sr+1,sc,+"d");
    floodfill(arr,sr,sc+1,+"r");
    arr[sr][sc]=0;
    
}
void find_target(int arr[], int idx,string s, int sos, int tar,int n){
    
    if(idx==n){
        if(sos==tar){
            cout<<s<<endl;
            return;
        }
    }
    string p=to_string(arr[idx]);
    find_target(arr,idx+1,s+p+" ,",sos+arr[idx],tar,n);
    find_target(arr,idx+1,s,sos,tar,n);
}
void show(vector<vector<int>>&arr, string asf,int row){
    
    
}
/*int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    string s=" ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
        }
    }
    floodfill(arr, 0, 0, s);

}*/