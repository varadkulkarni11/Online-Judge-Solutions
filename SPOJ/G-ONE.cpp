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
vector<int> dig;
ll dp[24][204][2];
ll k;
ll get(int pos,int sum,int flag){
	if(pos==dig.size()){
		if(!pr[sum]){
			return 1;
		}
		else return 0;
	}
	if(dp[pos][sum][flag]!=-1){
		return dp[pos][sum][flag];
	}
	int lmt;
	ll ans=0;
	if(!flag){
		lmt=dig[pos];
	}else{
		lmt=9;
	}
	for(int i=0;i<=lmt;i++){
		int nf=flag;
		if(!flag&&i<lmt){
			nf=1;
		}
		ans+=get(pos+1,sum+i,nf);
	}
	return (dp[pos][sum][flag]=ans);
}
ll give(ll n){
	dig.clear();
	while(n){
		dig.pb(n%10);
		n/=10;
	}
	ms(dp,-1,sz dp);
	reverse(all(dig));
	ll ans=get(0,0,0);
	return ans;
}
int main(){
	sieve();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		cout<<give(r)-give(l-1)<<"\n";
	}
}
