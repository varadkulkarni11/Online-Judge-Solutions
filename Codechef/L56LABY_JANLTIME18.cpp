#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define sz sizeof
using namespace std;
bool vis[1003][1003];
int level[1003][1003],n,m,a[1003][1003];
bool is(int i,int j){
	if(i>=0&&i<=n-1&&j>=0&&j<=m-1 && a[i][j]!=-1 && !vis[i][j]){
		return 1;
	}return 0;
}
vector<vector<pair<int,int> > > v(1003);
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;cin>>t;
	while(t--){
		ms(level,0,sz level);
		ms(vis,0,sz vis);
		ms(a,0,sz a);
		for(int i=0;i<=1000;i++)v[i].clear();
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				if(a[i][j]>0){
					v[a[i][j]].pb(mp(i,j));
				}
			}
		}
		for(int i=1000;i>=0;i--){
			for(int j=0;j<v[i].size();j++){
				if(vis[v[i][j].f][v[i][j].se]){
					continue;
				}
				vis[v[i][j].f][v[i][j].se]=1;
				if(i==0)continue;
				int x=v[i][j].f;
				int y=v[i][j].se;
				if(is(x+1,y)){
					v[i-1].pb(mp(x+1,y));
				}
				if(is(x-1,y)){
					v[i-1].pb(mp(x-1,y));
				}
				if(is(x,y+1)){
					v[i-1].pb(mp(x,y+1));
				}
				if(is(x,y-1)){
					v[i-1].pb(mp(x,y-1));
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){//cout<<vis[i][j]<<" ";
				if(a[i][j]==-1){
					cout<<"B";
					continue;
				}
				if(!vis[i][j]){
					cout<<"N";
					continue;
				}
				if(vis[i][j]){
					cout<<"Y";
					continue;
				}
			}cout<<"\n";
		}	
	}	
}
