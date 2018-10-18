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
ll inv(ll a,ll m){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	int n;
	while(true){
		cin>>n;
		if(!n)return 0;
		vector<pair<int,int> >a;
		set<pair<int,int> > ss;
		set<double> s;
		for(int i=0;i<n;i++){
			pair<int,int> k;cin>>k.f>>k.se;
			ss.insert(k);
		}
		n=ss.size();
		for(auto e:ss){
			a.pb(e);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				double y=(double)(a[j].se-a[i].se)/(double)(a[j].f-a[i].f);
				s.insert(y);
			}
		}
		cout<<s.size()<<"\n";
	}
}
