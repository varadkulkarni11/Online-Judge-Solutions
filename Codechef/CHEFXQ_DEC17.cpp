#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define indd index
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef long double ld;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ull lopow(ll x,ll y){ull res=1ULL;while(y){if(y&1)res*=(ull)x;y>>=1;x*=x;}return res;}
ll a[1000003];
ll pre[100003],N=100001;
vector< vector<ll> > bucket(ceil(sqrt(N)),vector<ll>(1000003,0));
vector<ll> lazy(ceil(sqrt(100003)),0),cur_buck(100003);
vector<pair<ll,ll> >ind(ceil(sqrt(N)));
void build(ll n){
	int x=0,k=ceil(sqrt(n));
	for(int i=0;i<k;i++){
		ind[i].f=x;
		for(int itr=0;itr<k&&x<n;itr++,x++){
			ind[i].se=x;      //se(=)x
			cur_buck[x]=i;
			bucket[i][pre[x]]++;
		}
	}
}
ll query(ll in, ll n , ll k){
	ll ans=0;
    for(int i=0;i<cur_buck[in];i++){
            ans+=bucket[i][k^lazy[i]];
	}
	for(int j=ind[cur_buck[in]].f;j<=in;j++)if((pre[j]^lazy[cur_buck[in]])==k)ans++;
    return ans;
}
void update(ll x,ll in, ll a[],ll n){
	for(int i=cur_buck[in]+1;i<ceil(sqrt(n));i++){
        lazy[i]^=x;
	}
	for(int j=in;j<=ind[cur_buck[in]].se;j++) {
            bucket[cur_buck[in]][pre[j]]--;
            pre[j]^=a[in];
            bucket[cur_buck[in]][pre[j]]++;
    }
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	pre[0]=a[0];
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]^a[i];
	}
	build(n);
	while(q--){
		ll x;
		cin>>x;
		if(x==2){
			ll xx=0,k;
			cin>>xx>>k;
			xx--;
			cout<<query(xx,n,k)<<"\n";;
		}else{
			ll i,xx;
			cin>>i>>xx;
			i--;
			update(a[i],i,a,n);
			a[i]=xx;
			update(xx,i,a,n);
		}
	}
}
