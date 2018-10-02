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
ll dp[1003][2][1003];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	int t;cin>>t;
	while(t--){ms(dp,0,sz dp);
		int n,b;cin>>n>>b;
		string s;
		cin>>s;
		dp[0][0][0]=0;
		dp[0][1][0]=2;
		for(int i=1;i<n;i++){
			if(s[i]=='#'){
				dp[0][0][i]=1e5;
			}
		}
		for(int i=1;i<n;i++){
			if(s[i]!='#')dp[0][0][i]=min(1+dp[0][0][i-1],4+dp[0][1][i-1]);
			dp[0][1][i]=min(2+dp[0][1][i-1],4+dp[0][0][i-1]);
		}
		for(int i=1;i<=b;i++){
			dp[i][0][0]=0;
			dp[i][1][0]=2;
		}
		for(int i=1;i<=b;i++){
			for(int j=1;j<n;j++){
				if(s[j]=='#')dp[i][0][j]=1+dp[i-1][0][j-1];
				if(s[j]!='#')dp[i][0][j]=min(1+dp[i][0][j-1],4+dp[i][1][j-1]);
				dp[i][1][j]=min(2+dp[i][1][j-1],4+dp[i][0][j-1]);
			}
		}
		cout<<dp[b][0][n-1]<<"\n";
	}
}
