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
ll fpow(ll x,ll y,ll m){x=x%m;ll res=1;while(y){if(y&1)res=res*x;res%=m;y=y>>1;x=x*x;x%=m;}return res;}
#define int long long
int n,s,k;
int dp[24][1003];
int get(int pos,int num){
	if(pos==k){
		if(num==0)return 1;
		else return 0;
	}
	if(dp[pos][num]!=-1){
		return dp[pos][num];
	}
	int lmt=9;
	ll ans=0;
	if(!pos){
		for(int i=1;i<=lmt;i++){
			ll extra=0,base=0;
			base=(fpow(10,s-(pos+1),n)*i)%n;;
			if((s&1)&&pos==(k-1)){
				
			}else{
				extra=(fpow(10,pos,n)*i)%n;
			}
			ans+=get(pos+1,(base+extra+num)%n);
		}
	}
	else{
		for(int i=0;i<=lmt;i++){
			ll extra=0,base=0;
			base=(fpow(10,s-(pos+1),n)*i)%n;;
			if((s&1)&&pos==(k-1)){
				
			}else{
				extra=(fpow(10,pos,n)*i)%n;
			}
			ans+=get(pos+1,(base+extra+num)%n);
		}
	}
	return (dp[pos][num]=ans);
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	int t;cin>>t;
	while(t--){
		ms(dp,-1,sz dp);
		cin>>n>>s;
		if(s&1)k=s/2+1;
		else k=s/2;
		cout<<get(0,0)<<"\n";;
	}
}
