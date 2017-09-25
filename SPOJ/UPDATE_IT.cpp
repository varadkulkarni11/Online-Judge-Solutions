//Overall Complexity: O(n+q)
#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i<sqrt(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
ll fashtpower(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ull lopow(ll x,ll y){ull res=1ULL;while(y){if(y&1)res*=(ull)x;y>>=1;x*=x;}return res;}
ll a[100003];
ll sta[100003]; //hash for start points
ll en[100003];  //hash for end points 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ms(a,0,sizeof a);
		ms(sta,0,sizeof sta);
		ms(en,0,sizeof en);
		ll n,q;
		cin>>n>>q;
		ll l,r,val;
		while(q--){
			cin>>l>>r>>val;
			sta[l]+=val;    //updating start hash to prev value + val to remember how many started at L
			en[r]+=val;		//updating end hash to prev value + val to remember how many ended at R
		}
		ll curr_val=0;
		for(int i=0;i<n;i++){     //sweeping through the start and end hash
			curr_val+=sta[i];    
			a[i]=curr_val;
			curr_val-=en[i];
		}
		ll m,x;
		cin>>m;
		while(m--){
			cin>>x;
			cout<<a[x]<<"\n";
			
		}
	}
}	
