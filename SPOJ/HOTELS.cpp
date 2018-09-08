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

ll a[300005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	ll n,s;cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0,sum=0,j=0;
	for(int i=0;i<n;i++){
		while(sum<=s&&j<n){
			sum+=a[j];
			if(sum>s){
				j++;
				break;
			}
			ans=max(ans,sum);
			j++;
		}
		while(sum>s&&i<n){
			sum-=a[i];
			if(sum<=s){
				ans=max(ans,sum);
				break;
			}
			i++;
		}
	}
	cout<<ans<<"\n";;
	
}
/*
20 100
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
