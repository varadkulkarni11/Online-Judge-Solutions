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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i*i<(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
int dp[10003][10003],a[10003],has[100000003];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				if(has[j]){
					dp[has[j]][i]=max(dp[has[j]][i],j);
				}
				has[j]=i;
				if(j*j!=a[i]){
					if((has[a[i]/j]) ){
						dp[has[a[i]/j]][i]=max(dp[has[a[i]/j]][i],a[i]/j);
					}	
					has[a[i]/j]=i;
				}
			}
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dp[l][r]<<"\n";
	}
}
