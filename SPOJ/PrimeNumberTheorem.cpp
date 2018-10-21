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
bool pr[50000001];
void sieve(){pr[0]=1;pr[2]=0;for(ll i=3;i*i<(100000001);i+=2){if(!pr[i/2])for(ll j=i*i;j<=(100000001);j+=2*i){pr[j/2]=1;}}}
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll inv(ll a,ll m){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
vector<int> prime;
int main(){
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 	
	sieve();
	double temp1,temp;
	long k;
	prime.pb(2);
	for(int i=3;i<=100000000;i+=2)if(!pr[i/2])prime.pb(i);
	while(true){
		scanf("%ld",&k);
        if(k==0)
        exit(0);
        temp=(double)(k/log(k));
        temp1=(double)(upper_bound(all(prime),k)-prime.begin());
        if(temp>temp1)
        temp=(double)(temp-temp1);
        else
        temp=(double)(temp1-temp);
        temp=(double)((temp/temp1)*100.0);
        printf("%.1lf\n",temp);
	}
 
}
