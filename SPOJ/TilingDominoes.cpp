#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[1003],g[1003],h[1003];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;cin>>t;
	f[0]=1;
	g[0]=1;
	h[0]=1;
	f[1]=1;
	g[1]=2;
	h[1]=1;
	for(int i=2;i<=1000;i++){
		f[i]=f[i-1]+f[i-2]+2*g[i-2]+h[i-2];
		g[i]=f[i]+g[i-1];
		h[i]=f[i]+h[i-2];
	}
	int a=1;
	while(t--){
		int n;cin>>n;cout<<a<<" "<<f[n]<<"\n";a++;
	}
}
