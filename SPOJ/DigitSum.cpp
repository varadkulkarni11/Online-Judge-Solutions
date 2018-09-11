#include<bits/stdc++.h>
#define pb push_back
#define ms memset
#define sz sizeof
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
ll vk[20][300][2];
vector<int> di;
ll get(int pos,ll sum,int flag){
	if(pos==di.size()){
		return sum;
	}
	if(vk[pos][sum][flag]!=-1){
		return vk[pos][sum][flag];
	}
	int lmt;
	ll ret=0;
	if(!flag){
		lmt=di[pos];
	}else{
		lmt=9;
	}
	for(int i=0;i<=lmt;i++){
		ll xd=0;
		int ne=flag;
		if(!flag&&i<lmt){
			ne=1;
		}
		xd+=i;
		ret+=get(pos+1,sum+xd,ne);
	}
	return vk[pos][sum][flag]=ret;
}
ll give(ll n){
	di.clear();
	while(n){
		di.pb(n%10);
		n/=10;
	}	
	ms(vk,-1,sz vk);
	reverse(all(di));
	ll ans=get(0,0,0);
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	ll a,b;
	int t;cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<give(b)-give(a-1)<<"\n";	
	}	
}
