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
ll dp[6][1000009];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	string s;
	cin>>s;
	string k;
	string t="1807";
	vector< ll > v;
	int n=s.length();
	for(int i=0;i<n;i++){
		int j=i,c=0;
		while(s[j]==s[i]&&j<n){
			j++;
			c++;
		}
		k.pb(s[i]);
		v.pb(c);
		i=j-1;
	}
	n=k.size();
	s=k;
	for(int i=1;i<=n;i++){
		if(s[i-1]==t[0])dp[1][i]=v[i-1]+dp[1][i-1];
		else dp[1][i]=dp[1][i-1];
	}
	for(int i=2;i<=4;i++){
		for(int j=1;j<=n;j++){
			if(j>=i){
				if(s[j-1]==t[i-1]){
					if(dp[i-1][j-1])dp[i][j]=v[j-1]+max(dp[i-1][j-1],dp[i][j-1]);
				}else{
					dp[i][j]=dp[i][j-1];
				}
			}else{
				dp[i][j]=0;
			}
		}
	}
	cout<<dp[4][n];
}
