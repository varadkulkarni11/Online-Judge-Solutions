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
ll dp[5003][5003];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int n,m;
	cin>>n>>m;
	ll c[m+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=LLONG_MAX;
		}
	}
	sort(b+1,b+n+1);
	sort(c+1,c+m+1);
	for(int i=0;i<=m;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i>=j)
			dp[i][j]=min(dp[i-1][j-1]+abs(c[i]-b[j]),dp[i-1][j]);
		}
	}
	cout<<dp[m][n];
}
