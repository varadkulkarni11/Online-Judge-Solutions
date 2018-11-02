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
int pr[10000007];
bool isnotprime(int x){if(x==2)return 0;if(x%2==0)return 1;return(pr[x/64]&(1<<((x>>1)&31)));} 
void sieve(int n){for(ll i=3;i*i<=n;i+=2){if(!isnotprime(i))for(ll j=i*i,k=i<<1;j<n;j+=k)pr[j/64]|=(1<<((j>>1)&31));}}
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll inv(ll a,ll m){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
map<int,vector<int> >m; 
ll mai,n;
ll dp[103][1025][13];
ll recur(int pos,int mask,int ppl){
	if(ppl==n||pos==101){
		if(mask==mai){
			return 1;
		}else{
			return 0;
		}
	}
	if(dp[pos][mask][ppl]!=-1)return dp[pos][mask][ppl];
	ll ans=0;
	for(int i=0;i<m[pos].size();i++){
		int ts=m[pos][i];
		int nm=mask;
		if(!((1<<ts)&nm)){
			nm=nm|((1<<ts));
			ans=ans+recur(pos+1,nm,ppl+1);
			ans%=MOD;
		}
	}
	ans=ans+recur(pos+1,mask,ppl);
	ans%=MOD;
	return dp[pos][mask][ppl]=ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	int t;cin>>t;
	while(t--){
		ms(dp,-1,sz dp);
		for(auto e:m)m[e.f].clear();
		m.clear();
		cin>>n;
		mai=(1<<n)-1;
		for(int i=0;i<n;i++){
			char ch='a';
			while(ch!='\n'){
				int x;cin>>x;
				m[x].pb(i);
				cin.get(ch);
			}
		}
		cout<<recur(0,0,0)<<"\n";
	}
}
