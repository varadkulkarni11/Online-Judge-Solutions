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
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int pr[10007];
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll inv(ll a,ll m){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
void spf(){
	pr[1]=1;
	for(int i=2;i<=10004;i++)pr[i]=i;
	for(int i=2;i<=10004;i++){
		if(pr[i]!=i)continue;
		for(int j=2*i;j<=10004;j+=i){
			pr[j]=i;
		}
	}
}
int dp[10003],totient[10003];
void phi(){
	for(int i=1;i<=10000;i++){
		int ans=i;
		set<int> s;
		int temp=i;
		while(temp!=1){
			s.insert(pr[temp]);
			temp/=pr[temp];
		}
		for(auto e:s){
			ans-=ans/e;
		}
		totient[i]=ans;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	spf();
	phi();
	dp[1]=1;
	for(int i=2;i<=10000;i++){
		int add=0;
		for(int j=1;j<i;j++)add+=totient[i]*totient[j];
		dp[i]=dp[i-1]+2*add+totient[i]*totient[i];
	}
	int t;cin>>t;
	while(t--){
		int n;cin>>n;cout<<dp[n]<<"\n";	
	}
}
