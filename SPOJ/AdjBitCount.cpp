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
int dp[101][101][2];
int main(){
	dp[1][0][0]=1;
	dp[1][0][1]=1;
	dp[1][1][0]=0;
	dp[1][1][1]=0;
	for(int i=2;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(j!=0){
				dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j-1][1];
			}else{
				dp[i][j][1]=dp[i-1][j][0];
			}
			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
		}
	}
	int t;cin>>t;
	while(t--){
		int n,k,x;cin>>x;
		cin>>n>>k;
		cout<<x<<" ";
		cout<<dp[n][k][0]+dp[n][k][1]<<"\n";
	}
}
