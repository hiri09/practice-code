#include<bits/stdc++.h>
using namespace std;
/*
int main(){
    int mx=-9999;
    int arr[5]={1,5,0,2,3};
    for(int i=0;i<5;i++){
        mx=max(mx,arr[i]);
    }
    cout<<mx<<endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j]; 
            cout<<sum<<endl;  
        }
        
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mx=-999;
    int ans=0;
    for(int i=0;i<n;i++){
        
        if(arr[i]>mx && arr[i+1]<arr[i]){
            ans++;
        }
        mx=max(mx,arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n]={3,3,3};
    int d=arr[1]-arr[0];
    for(int i=0;i<n;i++){
        
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    int j=1;
    while(j<n && i<n){
        if(arr[i]+arr[j]==s){
            return i,j;   
        }
        else if(arr[i]+arr[j]<s){
            j++;
        }
        else{
            i++;
        }
    }   
    cout<<i<<j<<endl;
    return 0;
}*/



//when we pass the pointer array the we do arr++

/*#include<iostream>
using namespace std;
int main(){
    //int arr[10]={1,2,3,4,5,6,7,8,9,10};
    //int p= (arr+1)[5];
    //int k=(arr+2)[3];
    int a[]={5,1,15,20,25};
    int i,j,q;
    i=++a[1];
    j=a[1]++;
    q=a[i]++;
    cout<<i<<"  "<<j<<" "<<q<<endl;
    
    return 0;
}*/
/*
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a1[n];
    int a2[m];
    int sum_a1=0;
    int sum_a2=0;
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    for(int i=0;i<m;i++){
        cin>>a2[i];
    }
    for(int i=0;i<n;i++){
        sum_a1+=a1[i];
    }
    for(int i=0;i<m;i++){
        sum_a2+=a2[i];
    }
    cout<<sum_a2<<"  "<<sum_a1<<endl;
    return 0;
}*/
/*#include<iostream>
using namespace std;
int search(int arr[],int n,int k){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<search(arr,n,k)<<endl;;
    return 0;
}
*/
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mx=-999;
    int mn=9999;
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
    }
    for(int i=0;i<n;i++){
        mn=min(mn,arr[i]);
    }
    cout<<mx<<"  "<<mn<<endl;
    return 0;
}*/
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             if(arr[i]+arr[j]==sum){
                 count++;
             }
        }
    }
    cout<<count<<endl;
    return 0;
}*/
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5]={1,3,2,5,4};
    sort(arr,arr+5);// 10  11 22 34 55
    int k=2;
    
    cout<<"kth maximum element  "<<arr[k-1]<<endl;
    
    cout<<"kth minimum elemnet   "<<arr[4-k]<<endl;
    

    return 0;
}*/
/*#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int first=-1;
    while(first<n){
        if(arr[first]==k){
            break;
        }
        first++;
    }
    if(first<n){
        cout<<first<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    
    
    return 0;
}*/
/*#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int first=n;
    while(first>=0){
        if(arr[first]==k){
            break;
        }
        first--;
    }
    if(first<n && first>=0){
        cout<<first<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    
    
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int first=-1;
    for(int i=n-1;i>=0;i--){
        if(k==arr[i]){
            first=i;
            break;
        }
    }
    cout<<first<<endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[],int low,int high,int n){
    while(low<high){
         int temp=arr[low];
         arr[low]=arr[high];
         arr[high]=temp;
         low++;
         high--;
    }
}
void reverse(int arr[],int n,int k){
    rotate(arr,0,k-1,n);
    rotate(arr,k,n-1,n);
    rotate(arr,0,n-1,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}*/
/*int solve(int arr[],int n){
    vector<int> v(n+1,-1);
    v[n]=0;
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]>0){
            int mn=INT16_MAX;
        
            for(int j=1;j<=arr[i] && i+j<n+1;j++){
                if(v[i+j]!=-1){
                    mn=min(mn,v[i+j]);
                }
            }
            if(mn!=INT16_MAX){
                v[i]=mn+1;
            }
            else{
                v[i]=-1;
            }
        }  
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    return 0;
}*/
class student{
    
public:
    int age;
    bool gender;
    string name;
    /*void setname(string s){
        name=s;
    }*/

    void printf(){
        cout<<"age = ";
        cout<<age<<endl;
        cout<<"name = ";
        cout<<name<<endl;
    }
    void swp(student p1,student p2){
        student temp=p1;
        p1=p2;
        p2=temp;    
    }
};
int main(){
    student p1;
    p1.age=10;
    p1.name="A";

    student p2;
    p2.age=20;
    p2.name="B";
    
    p1.printf();
    p2.printf();
    
    cout<<endl;
    
    p1.printf();
    p2.printf();
    return 0;
}






































