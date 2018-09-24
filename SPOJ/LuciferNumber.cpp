#include<bits/stdc++.h>
#define pb push_back
#define ms memset
#define sz sizeof
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
bool pr[1000007];
void sieve(){pr[0]=1;pr[1]=1;for(int i=2;i*i<(1000007);i++){for(int j=2*i;j<=1000007;j+=i){pr[j]=1;}}}
vector<int> num;
ll dp[10][150][150][2];
ll get(int pos,int even_sum,int odd_sum,int flag){
	if(pos==num.size()){
		if(even_sum-odd_sum<=1)return 0;
		if(!pr[abs(even_sum-odd_sum)]){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[pos][even_sum][odd_sum][flag]!=-1){
		return dp[pos][even_sum][odd_sum][flag];
	}
	int lmt;
	if(flag){
		lmt=9;
	}else{
		lmt=num[pos];
	}
	ll ans=0;
	for(int i=0;i<=lmt;i++){
		int co=0,ce=0,nf=flag;
		if((num.size()&1)&&!(pos&1)|| (!(num.size()&1)&&(pos&1))){
			if(pos==0&&i==0)ce+=i;
			else co+=i;
		}else{
			if(pos==0&&i==0)co+=i;
			else ce+=i;
		}
		if(!flag&&i<lmt){
			nf=1;
		}
		ans+=get(pos+1,even_sum+ce,odd_sum+co,nf);
	}
	dp[pos][even_sum][odd_sum][flag]=ans;
	return ans;
}
ll give(ll n){
	num.clear();
	ms(dp,-1,sz dp);
	while(n){
		num.pb(n%10);
		n/=10;
	}
	reverse(all(num));
	ll ans=get(0,0,0,0);
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	sieve();
	int t;cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		cout<<give(b)-give(a-1)<<"\n";
	}	
}
