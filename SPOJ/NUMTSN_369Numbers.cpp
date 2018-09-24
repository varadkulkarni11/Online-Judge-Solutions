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
vector<int>dig;
ll dp[52][18][18][18];
ll get(int pos,int t,int s,int n,int flag){
	if(t>=17||s>=17 ||n>=17)return 0;
    if(pos==-1){
        if(t==s&&s==n&&t>0)return 1;
        else return 0;
    }
    if(flag && dp[pos][t][s][n]!=-1) {
    	return dp[pos][t][s][n]%MOD;
    }
    int lmt=0;
    if(!flag){
    	lmt=dig[pos];
    }else{
    	lmt=9;
    }
	ll ans=0;
	for(int i=0;i<=lmt;i++){
		int th=0,si=0,ni=0,nf=flag;
		if(!flag&&i<lmt)nf=1;
		if(i==3)th=1;
		if(i==6)si=1;
		if(i==9)ni=1;
		ans+=(get(pos-1,t+th,s+si,n+ni,nf)%MOD)%MOD;
		ans%=MOD;
	}
	if(!flag)return ans;
	else return dp[pos][t][s][n]=ans;
}
ll give(string s){
	dig.clear();
	for(auto e:s){
		dig.pb(e-'0');
	}
	reverse(all(dig));
	ll ans=get(dig.size()-1,0,0,0,0);
	return ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	ms(dp, -1 ,sz dp);
	while(t--){
		string a,b;
		cin>>a>>b;
		int t=0,s=0,n=0;
		for(int i=0;i<a.size();i++){
			if(a[i]=='3')t++;
			if(a[i]=='6')s++;
			if(a[i]=='9')n++;	
		}
		int p=0;
		if(t==s&&s==n&&t>0)p=1;
		cout<<(((give(b)-give(a))+MOD)%MOD+p)%MOD<<"\n";;
	}
} 
