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
int dp[1000005];
int main(){
	dp[0]=1;
	int t,k,l;cin>>k>>l>>t;
	for(int i=2;i<=1000000;i++){
		if(i<k){
			if(dp[i-1]==0){
				dp[i]=1;
			}
		}
		else if(i<l){
			if(dp[i-1]==0&&dp[i-k]==0){
				dp[i]=1;
			}
		}else{
			
			if(dp[i-1]==0&&dp[i-k]==0&&dp[i-l]==0){
				dp[i]=1;
			}
		}
	}
	while(t--){
		int n;cin>>n;
		if(dp[n]==0){
			cout<<"A";
		}else{
			cout<<"B";
		}
	}
}
