#include<bits/stdc++.h>
#define pb push_back
#define ms memset
#define sz sizeof
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,w;
ll dp[21][201][10];
ll memo(int pos,int wt,int prv){
	if(pos==n){
		if(wt==w){
			return 1;
		}else{
			return 0;
		}
	}
	if(dp[pos][wt][prv]!=-1){
		return dp[pos][wt][prv];
	}
	ll ans=0;
	if(pos==0){
		for(int i=1;i<=9;i++){
			ans=(ans+memo(pos+1,0,i)%MOD);
			ans%=MOD;
		}
	}else{
		for(int i=0;i<=9;i++){
			ll xd=0;
			xd+=abs(i-prv);
			ans=(ans+memo(pos+1,wt+xd,i)%MOD)%MOD;
		}
	}
	dp[pos][wt][prv]=ans;
	return ans;
	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;cin>>t;
	while(t--){
		ms(dp,-1,sz dp);
		cin>>n>>w;
		cout<<memo(0,0,0)<<"\n";;
	}	
}
