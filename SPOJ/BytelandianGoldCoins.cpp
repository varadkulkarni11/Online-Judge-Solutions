#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n;
map<ll,ll> m;
ll f(ll n){
	if(n==0){
		ans=0;
		return 0;
	}
	if(n==1){
		ans=0;
		return 1;
	}
	if(n==2){
		ans=0;
		return 2;
	}
	if(n==3){
		ans=0;
		return 3;
	}
	if(m[n]){
		ans=0;
		return  m[n];
	}
	ans=max(ans,max(n,f(n/2)+f(n/3)+f(n/4)));
	m[n]=ans;
	return ans;
}
int main(){
	while(cin>>n){
		ans=0;
		cout<<f(n)<<"\n";
	}
} 
