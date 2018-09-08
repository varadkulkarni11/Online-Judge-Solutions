#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define sp fixed<<setprecision
#define sz sizeof
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i*i<(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll dp[2003][2003];
ll solve(ll a[],int s,int e,int k){
	if(s==e){
		return k*a[s];
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	ll ans=0;
	ans=max(a[s]*k+solve(a,s+1,e,k+1),a[e]*k+solve(a,s,e-1,k+1));
	dp[s][e]=ans;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int n;cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=-1;
		}	
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<solve(a,0,n-1,1);	
}
