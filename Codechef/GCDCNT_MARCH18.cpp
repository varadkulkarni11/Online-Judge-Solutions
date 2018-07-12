#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define sp fixed<<setprecision
#define sz sizeof
#define all(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int spf[1000007];
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
int a[100003];
typedef tree<
   int ,
  null_type,
  less<int >,
  rb_tree_tag,
  tree_order_statistics_node_update>ordered_set;
 
void spff(){
	for(int i=0;i<=100003;i++){
		spf[i]=i;
	}
	for(int i=2;i<=100003;i++){
		if(spf[i]!=i)continue;
		for(int j=2*i;j<=100003;j+=i){
			spf[j]=i;
		}
	}	
}
ordered_set x;
map<vector<int> , ordered_set >m;
void build(vector<int>arr,int ind){	
	int n=arr.size();
	vector<int> v;
    unsigned int opsize = pow(2, n);
	int k=1;
    for (int counter = 1; counter < opsize; counter++){
        for (int j = 0; j < n; j++){
            if (counter & (1<<j))
                v.pb(arr[j]);
        }
        m[v].insert(ind);
        v.clear();
    }
}
void eras(vector<int>arr,int ind){	
	int n=arr.size();
	vector<int> v;
    unsigned int opsize = pow(2, n);
	int k=1;
    for (int counter = 1; counter < opsize; counter++){
        for (int j = 0; j < n; j++){
            if (counter & (1<<j))
                v.pb(arr[j]);
        }
        m[v].erase(ind);
        v.clear();
    }
}
void ins(vector<int>arr,int ind){	
	int n=arr.size();
	vector<int> v;
	unsigned int opsize = pow(2, n);
	int k=1;
    for (int counter = 1; counter < opsize; counter++){
        for (int j = 0; j < n; j++){
            if (counter & (1<<j))
                v.pb(arr[j]);
        }
        m[v].insert(ind);
        v.clear();
    }
}
int query(vector<int>arr,int l,int r){	
	int n=arr.size();
	int ans=0;
	vector<int> v;
    unsigned int opsize = pow(2, n);
	int k=1;
    for (int counter = 1; counter < opsize; counter++){
        for (int j = 0; j < n; j++){
            if (counter & (1<<j))
                v.pb(arr[j]);
        }
        int xx=0;
        xx=(m[v].order_of_key(r+1))-(m[v].order_of_key(l));
       	if(v.size()&1){
        	ans+=xx;
        }else{
        	ans-=xx;
        }
        v.clear();
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	spff();
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		set<int>s;
		vector<int> v;
		set<int> :: iterator it;
		cin>>x;
		a[i]=x;
		while(x!=1){
			s.insert(spf[x]);
			x/=spf[x];
		}
		for(it=s.begin();it!=s.end();it++){
			v.pb(*it);
		}
		build(v,i);
	}
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		if(x==1){
			int xx,y;
			cin>>xx>>y;
			int t=a[xx];
			set<int>s;
			vector<int> v;
			set<int> :: iterator it;
			while(t!=1){
				s.insert(spf[t]);
				t/=spf[t];
			}
			for(it=s.begin();it!=s.end();it++){
				v.pb(*it);
			}
			eras(v,xx);
			t=y;
			s.clear();
			v.clear();
			while(t!=1){
				s.insert(spf[t]);
				t/=spf[t];
			}
			for(it=s.begin();it!=s.end();it++){
				v.pb(*it);
			}
			a[xx]=y;
			ins(v,xx);
		}else{
			int l,r,g;
			cin>>l>>r>>g;
			set<int>s;
			vector<int> v;
			set<int> :: iterator it;
			while(g!=1){
				s.insert(spf[g]);
				g/=spf[g];
			}
			for(it=s.begin();it!=s.end();it++){
				v.pb(*it);
			}
			int nn=(r-l+1);
			cout<<nn-query(v,l,r)<<"\n";;
		}
	}
}
/*
9
2 3 4 5 6 8 24 25 30
2
1 8 1	
2 5 9 1
*/
