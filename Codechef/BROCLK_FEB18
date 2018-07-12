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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll f;
ll I,d,t;
ll inv(ll n){
	return fpow(n,MOD-2);
}
void multiply(ll F[2][2], ll M[2][2]);
 
void power(ll F[2][2], ll n);
ll ini[2];; 
ll fib(ll n){
  ll F[2][2] = {{0,-1},{1,(2*f)%MOD}};
  if (n == 1)return (ini[1]*I)%MOD;
  power(F,n-1);
  ll ans=(ini[1]%MOD*F[1][1]%MOD)%MOD+(ini[0]%MOD*F[0][1]%MOD)%MOD;
  if(ans<0)ans=(ans+MOD)%MOD;
  ans=(ans*I)%MOD;
  return ans;
}
void power(ll F[2][2], ll n){
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{0,-1},{1,(2*f)%MOD}};
  power(F, n/2);
  multiply(F, F);
  if (n%2 != 0) multiply(F, M);
}
 
void multiply(ll F[2][2], ll M[2][2]){
  ll x =  (F[0][0]%MOD*M[0][0]%MOD + F[0][1]%MOD*M[1][0]%MOD)%MOD;
  ll y =  (F[0][0]%MOD*M[0][1]%MOD + F[0][1]%MOD*M[1][1]%MOD)%MOD;
  ll z =  (F[1][0]%MOD*M[0][0]%MOD + F[1][1]%MOD*M[1][0]%MOD)%MOD;
  ll w =  (F[1][0]%MOD*M[0][1]%MOD + F[1][1]%MOD*M[1][1]%MOD)%MOD;
  if(x<0)x=(x+MOD)%MOD;
  if(y<0)y=(y+MOD)%MOD;
  if(z<0)z=(z+MOD)%MOD;
  if(w<0)w=(w+MOD)%MOD;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll _;
	cin>>_;
	while(_--){
		cin>>I>>d>>t;
		f=(d*inv(I))%MOD;
		ini[0]=1,ini[1]=f;
		cout<<fib(t)<<"\n";
	}
}
