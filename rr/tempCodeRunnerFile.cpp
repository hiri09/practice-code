
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
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    inversion(arr,n);
    return 0;
}