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
int spf[1103];
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
void s(){
	for(int i=0;i<=1103;i++)spf[i]=i;
	for(int i=2;i<=1103;i++){
		if(spf[i]!=i)continue;
		for(int j=2*i;j<=1103;j+=i){
			spf[j]=i;
		}
	}
}
bool is[1103];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	s();
	for(int i=2;i<=1100;i++){
		map<int,int> m;
		int t=i;
		while(t!=1){
			m[spf[t]]++;
			t/=spf[t];
		}
		int ce=0,co=0;
		for(auto e:m){
			if(e.se & 1)co++;
			else ce++;
		}
		if(ce>co)is[i]=1;
	}
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		vector<int>v;
		int sum=0;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			if(is[x])v.pb(x),sum+=x;			
		}
		if(k>sum){
			cout<<"No\n";
			continue;
		}
		sort(all(v));
		int c=v.size();
		bool dp[c+3][sum+3];
		ms(dp,0,sz dp);
		for(int i=0;i<c;i++)dp[i][0]=1;
		dp[0][v[0]]=1;
		for(int i=1;i<c;i++){
			for(int j=0;j<=sum;j++){
				if(j>=v[i])dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i]];
				else dp[i][j]=dp[i-1][j];
			}
		}
		dp[c-1][k]?cout<<"Yes\n":cout<<"No\n";
	}
	
}
