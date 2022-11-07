#include<bits/stdc++.h>
using namespace std;
bool isvalid(int mid,vector<int> &v,int n,int m){
	int parts=0;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=v[i];
		if(sum>mid){
			sum=v[i];
			parts++;
		}
	}
	return parts < m;
}
int find_minimum(vector<int> &v,int n,int m){
	int sum=0;
	int mx=INT_MIN;
	for(int i=0;i<n;i++){
		sum+=v[i];
		if(mx<v[i]){
			mx=v[i];
		}
	}
	int l=mx;
	int h=sum;
	int ans;
	while(l<=h){
        int mid=(l+h)/2;

		if(isvalid(mid,v,n,m)==true){

		}
	}
	return mx;
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
	int m;
	cin>>m;
	if(m>n){
		cout<<"not possible"<<endl;
	}
	else{
		cout<<find_minimum(v,n,m)<<endl;
	}
	return 0;
}

/*
b bbaaa
[4,9,3,8,8,9]
23

15


Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. 
Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime 
where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

 

 colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
int solve(vector<int> v,int n,int k){

	int l=0;
	int h=n-1;
	while(l<=h){
		int mid=(l+h)/2;

		if(v[mid]==k)return 1;

		if(v[mid] >= v[0]){
            if(v[0]<k && k<v[mid]){
                h=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(v[mid] <= v[n-1]){
            if(v[mid]<k && k<v[n-1]){
                l=mid+1;
			}
			else{
				h=mid-1;
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
class  SGTree{
	vector<int> s;
	public:
    SGTree(int n){
        s.resize(4 * n +1);
	}
  void build(int idx,int l,int h,vector<int> a,bool orr){
	if(l==h){
        s[idx]=a[l];
		return ;
	}

	int mid= (l+h) >> 1;

	build(2 * idx + 1 ,l,mid, a,!orr);
	build(2 * idx + 2 ,mid+1, h, a,!orr);
 
    if(orr==1 ){
		s[idx]=s[2 * idx + 1] | s[2 * idx + 2];
	}
	else{
		s[idx]=s[2 * idx + 1] ^ s[2 * idx + 2];
	}
  }
  int solve(int i,vector<int> &value,vector<int> &weight,int n,int maxweight,vector<vector<int>> &dp){
    
	if(i==n-1){
		if(weight[n-1]<=maxweight){
             return value[i];
		}
		return 0;
	}
    if(dp[i][maxweight]!=-1)return dp[i][maxweight];
	int np=solve(i+1,value,weight,n,maxweight,dp);
	int p=INT_MIN;
	if(weight[i]<=maxweight){
		p=value[i]+ solve(i+1,value,weight,n,maxweight-weight[i],dp);
	}
	return dp[i][maxweight]=max(p,np);

	for(int i=weight[n-1];i<=maxweight;i++){
        dp[n-1][i]=value[n-1];
		//cout<<dp[n-1][i]<<" ";
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=maxweight;j++){
             int np=dp[i+1][j];
			 int p=INT_MIN;
			 if(weight[i]<=j){
		        p=value[i]+ dp[i+1][j-weight[i]];
	         }
			 dp[i][j]=max(p,np);
		}
	}
	return dp[0][maxweight];
}

int solve(string &s,string &p,int n,int m){
    if(i==0 || j==0){
        return 0;
	}
	if(s[i-1]==p[j-1]){
       return 1 + solve(s,p,i-1,j-1);
	}
	else{
        return max(solve(s,p,i-1,j),solve(s,p,i,j-1));
	}

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<n;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<m;j++){
			dp[0][j]=0;
	}
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==p[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
	        }
	        else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
		}
	}

	int i=n;
	int j=m;
	string ans="";
    while(i>0 && j>0){
         if(s[i-1]==p[i-1]){
			ans+=s[i-1];
			i--;
			j--;
		 }
		 else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		 }
		 else if(dp[i-1][j]<dp[i][j-1]){
			j--;
		 }
	}
	cout<<ans<<endl;
	return dp[n][m];
}
void substring_01(string s,string p,int count ,int &mx,int i){
    if(i==0 || j==0)return;

	if(s[i]==p[i]){
		count++;
	}
	else{
		if(count>mx){
			mx=count;
			count=0;
		}
	}
	substring_01(s,p,count,mx,i-1);
}
  void update(int idx,int l,int h,int i,int val,bool orr){
	if(l==h){
		s[idx]=val;
		return;
	}

	int mid=(l+h) >> 1;

	if(i<=mid){
		update(2 * idx + 1,l,mid,i,val,!orr);
	}
	else{
		update(2 * idx + 2,mid+1,h,i,val,!orr);
	}
	
    if(orr==1 ){
		s[idx]=s[2 * idx + 1] | s[2 * idx + 2];
	}
	else{
		s[idx]=s[2 * idx + 1] ^ s[2 * idx + 2];
	}

  }
  void print(int l){
	for(auto it:s){
		cout<<it<<" ";
	}
  }
};
void solve(string s,int &count,int i,string ans,unordered_map<char,int>st){
   
   if(s[i]=='0'){
	return ;
   }
   if(i>s.length()){
	return;
   }
   if(i==s.length()){
	  cout<<ans<<endl;
	  count++;
	  return;
   }
   if(i<s.length()){
	solve(s,count,i+1,ans+ " " + s[i], st);
   }
   if(i+1<s.length()){
	char a=s[i];
	char b=s[i+1];
	if(b<=54 && (a==49 || a==50)){
        solve(s,count,i+2,ans+" " + s[i] +s[i+1], st);
	}
	
   }


}
void uniquepath(int n,int m,int i,int j){
    if(i>=n || j>=m)return 0;
	if(i==n-1 && j==m-1)return 1;
    int r=solve(n,m,i,j+1);
	int d=solve(n,m,i+1,j);
	return r+d;
	vector<vector<int>> dp(n,vector<int>(m,0));
    dp[n-1][m-1]=1;
    for(int i=0;i<n-1;i++){
		dp[i][m-1]=1;
	}
    for(int i=0;i<m-1;i++){
		dp[n-1][i]=1;
	}
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			dp[i][j]=dp[i][j+1]+dp[i+1][j];
		}
	}
	cout<<dp[0][0];
}
void uniquepath2(int n,int m,vector<vector<int>> &v){
	vector<vector<int>> dp(n,vector<int>(m,0));
    dp[n-1][m-1]=1;
	
	bool flag1=false;
	int p;
	for(int i=m-2;i>=0;i--){
		if(v[n-1][i]==-1){
			flag1=true;
			p=i;
			break;;
		}
		dp[n-1][i]=1;
	}
	bool flag2=false;
	int q;
	for(int i=n-2;i>=0;i--){
		if(v[i][m-1]==-1){
			flag2=true;
			q=i;
			break;;
		}
		dp[i][m-1]=1;
	}
	if(flag1==true){
		for(int i=p;i>=0;i--){
			dp[n-1][i]=0;
		}
	}
	if(flag2==true){
		for(int i=q;i>=0;i--){
			dp[i][m-1]=0;
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			if(v[i][j]==-1){
				dp[i][j]=0;
			}
			else{
				dp[i][j]=dp[i][j+1]+dp[i+1][j];
			}
		}
	}
	cout<<dp[0][0]<<endl;
	
	return ;
}
int maximumpath(int n,int m,vector<vector<int>> &v){
    vector<vector<int>> dp(n,vector<int>(m,-1));

	for(int i=0;i<m;i++){
		dp[n-1][i]=v[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<m;j++){
			if(j>0 && j<m-1){
				int a=max(dp[i+1][j-1],dp[i+1][j]);
				dp[i][j]=v[i][j]+max(a,dp[i+1][j+1]);
			}
			if(j==0){
				dp[i][j]=v[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
			}
			if(j==m-1){
				dp[i][j]=v[i][j]+max(dp[i+1][j],dp[i+1][j-1]);
			}
		}
	}
	int mx=-1e9;
	for(int i=0;i<m;i++){
		mx=max(mx,dp[0][i]);
	}
	cout<<mx<<endl;
}
int numRollsToTarget(int n,int k,int t,vector<int> &dp){
    if(t<0)return 0;
	if(n==0){
		if(t==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[n]!=-1)return dp[n];
    int sum=0;
	for(int i=1;i<=k;i++){
        sum+=numRollsToTarget(n-1,k,t-i,dp);
	}
	return dp[n]=sum;
}
bool sumsubset(int i,vector<int> arr,int n,int t,vector<vector<bool>> &dp){
    
	/*if(t<0)return 0;

	if(i==n){
		if(t==0){
			return 1;
		}
		return 0;
	}
   if(dp[i][t]!=-1)return dp[i][t];
	bool p=solve(i+1,arr,n,t-arr[i],dp);
	if(p==true){
		return dp[i][t]=1;
	}
	bool np=solve(i+1,arr,n,t,dp);
	if(np==true){
		return dp[i][t]=1;
	}
	return dp[i][t]=0;;

   dp[n][0]=1;
   for(int i=1;i<=t;i++){
	  dp[n][i]=0;
   }
   for(int i=n-1;i>=0;i--){
       for(int j=0;j<=t;j++){
           if(j==0){
			 dp[i][j]=1;
		   }
		   else{
			    
                if(arr[i]<=j){
					bool p=dp[i+1][j-arr[i]];
					if(p==true){
						dp[i][j]=true;
					}
					bool q=dp[i+1][j];
					if(q==true){
						dp[i][j]=true;
					}
				}
				else{
					dp[i][j]=false;
				}
		   }
	   }
   }
   return dp[0][t];
}*/
/*void build(int idx,int l,int h,vector<int> a,vector<int> &s){
    
	if(l==h){
		s[idx]=a[l];
		return;
	}
    int mid=(l+h)/2;
	build(2*idx + 1,l,mid,a,s);
	build(2*idx + 2,mid+1,h,a,s);
	s[idx]=min(s[2 * idx + 1], s[2 * idx + 2]);
}
int query(int ind,int low,int high,int l,int r,vector<int> s){

	if(r < low || high < l)return INT_MAX;

	if(low>= l && high <=r )return s[ind];

	int mid=(low+high) >> 1;
    int left=query(2 * ind + 1,low,mid,l,r,s);
	int right=query(2 * ind + 2,mid+1,high,l,r,s);
	return min(left,right);

}
void update(int low,int high,int idx,int i,int val,vector<int> &s){
    if(low==high){
		s[idx]=val;
		return;
	 }

	 int mid=(low+high) >> 1;

	 if(i<=mid){
        update(low,mid,2 * idx + 1,i,val,s);
	 }
	 else{
		update(mid+1,high,2 * idx + 2,i,val,s);
	 }
	 s[idx]=min(s[2 * idx + 2 ],s[2 * idx + 1]);  
}
int main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	vector<int> s(4*n);
	build(0,0,n-1,a,s);
    update(0,n-1,0,n-1,0,s);
	cout<<s[0]<<endl;

	int q;
	cin>>q;
	while(q--){
		int l ,r;
		cin>>l>>r;
        cout<<query(0,0,n-1,l,r,s);

	}
	return 0;
}
*/

