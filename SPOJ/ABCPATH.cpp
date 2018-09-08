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
string s[52];
bool vis[53][53];
int n,m,anss,ans;	
bool is(int i,int j,char c){
	char d=c+1;
	if(i>=0&&i<n&&j>=0&&j<m&&s[i][j]==d&&!vis[i][j]){
		return 1;
	}
	return 0;
}
int f=0;
void dfs(int i,int j,int k){
	anss=max(anss,k);
	vis[i][j]=1;
	if(is(i+1,j,s[i][j])){
		dfs(i+1,j,k+1);
	}
	if(is(i-1,j,s[i][j])){
		dfs(i-1,j,k+1);
	}
	if(is(i,j+1,s[i][j])){
		dfs(i,j+1,k+1);
	}
	if(is(i,j-1,s[i][j])){
		dfs(i,j-1,k+1);
	}
	
	if(is(i+1,j+1,s[i][j])){
		dfs(i+1,j+1,k+1);
	}
	if(is(i-1,j+1,s[i][j])){
		dfs(i-1,j+1,k+1);
	}
	if(is(i+1,j-1,s[i][j])){
		dfs(i+1,j-1,k+1);
	}
	if(is(i-1,j-1,s[i][j])){
		dfs(i-1,j-1,k+1);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int a=1;
	while(true){
		ans=0;anss=0;
		f=0;
		ms(vis,0,sz vis);
		cin>>n>>m;
		if(n==0)return 0;
		for(int i=0;i<n;i++){
			s[i]="";
			cin>>s[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='A'&&!vis[i][j]){
					anss=0;
					f=0;
					dfs(i,j,1);
					ans=max(ans,anss);
				}
			}
		} 
		cout<<"Case "<<a<<": "<<ans<<"\n";
		a++;
	}
}
