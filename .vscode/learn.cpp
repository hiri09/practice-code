#include<bits/stdc++.h>
using namespace std;
void fun(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<n;i++){
        arr[i]=arr[i]+2;
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void f(vector<int> &v,int k){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    int i=0;
    int j=v.size()-1;
    while(i<=j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int binary_search(vector<int> v,int k){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(v[mid]==k){
            return mid;
        }
        else if(v[mid]>k){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int k;
    cin>>k;
    int a=binary_search(v,k);
    cout<<a<<endl;
    return 0;
}
