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
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		ll x=s.length();
		s=s+s;
		ll n=s.length();
		ll pref[n+1],suf[n+1];
		pref[-1]=0;
		suf[n]=0;
		int p=27;
		for(int i=0;i<n;i++){
			pref[i]=pref[i-1]+((int)s[i]*fpow(p,i))%MOD;
			pref[i]=pref[i]%MOD;
		}
		int j=0;
		for(int i=n-1;i>=0;i--){
			suf[i]=suf[i+1]+((int)s[i]*fpow(p,j))%MOD;
			suf[i]=suf[i]%MOD;
			j++;
		}
		ll ans=0;
		for(int i=0;i<x;i++){
			int l=i,r=i+x-1;
			ll pp=pref[r]-pref[l-1];
			if(pp<0)pp+=MOD;
			pp=pp%MOD;
			ll in=fpow(p,l);
			pp=pp*fpow(in,MOD-2);
			pp=pp%MOD;
			ll qq=suf[l]-suf[r+1];
			if(qq<0)qq+=MOD;
			qq=qq%MOD;
			ll inv=fpow(p,n-1-r);
			qq=qq*fpow(inv,MOD-2);
			qq=qq%MOD;
			ans+=(pp==qq);
		}cout<<ans<<"\n";
	}
}
