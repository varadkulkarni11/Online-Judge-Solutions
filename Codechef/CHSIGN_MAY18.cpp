#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define sp fixed<<setprecision
#define sz sizeof
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+5],pre[n+5];
		int vk[4][n+5][2],bana[n+5];
		ll god=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<n+5;j++){
				vk[i][j][0]=0;
				vk[i][j][1]=0;
			}
		}
		for(int i=0;i<n+5;i++){
			vk[0][i][1]=-1;
			vk[1][i][1]=-1;
			vk[2][i][1]=-1;
			vk[3][i][1]=-1;
		}
		ms(a,0,sz a);
		for(int i=0;i<n;i++){
			cin>>a[i];
			god+=a[i];
		}
		ms(bana,0,sz bana);
		ms(pre,0,sz pre);
		vector<int> v(n+5,0);
		vector<pair<int,pair<int,int> > >p;
		a[-1]=LLONG_MAX;
		a[n]=LLONG_MAX;
		for(int i=0;i<n;i++){
			if(a[i]<a[i-1]&& a[i]<a[i+1]){
				pre[i]=a[i];
			}
		}
		int xd=0;
		int kk=0;
		for(int i=0;i<n;i++){
			int j=i,s=0;
			while(pre[j]==0 && j<n){
				s+=a[j];
				j++;
			}
			p.pb(mp(0,mp(i-1,j)));
			v[kk++]=s;
			if(j!=n)v[kk++]=-1*a[j];
			i=j;
		}
		int k=0,in=0,st=0;
		if(v[0]==0){
			in=2;
			st=1;
		}
		if(in==0){
			vk[0][k][0]=god; 
			vk[1][k][0]=LLONG_MAX;  
			vk[2][k][0]=LLONG_MAX;   
			vk[3][k][0]=god+2*v[in+1];
			if(v[in+1]==0)vk[3][k][0]=LLONG_MAX; 
		}else{
			vk[0][k][0]=god;
			if(abs(v[in-1]+v[in+1])<v[in]){
				if(v[in+1]==0)vk[1][k][0]=LLONG_MAX;
				else vk[1][k][0]=god+2*v[in-1]+2*v[in+1];
			}else{
				vk[1][k][0]=LLONG_MAX;
			}
			vk[2][k][0]=god+2*v[in-1];
			vk[3][k][0]=god+2*v[in+1];
			if(v[in+1]==1)vk[3][k][0]=LLONG_MAX;
		}k++;
		in+=2;
		for(;in<=n;in+=2){
			if(v[in]==0)break;
			if(in==n && v[0]!=0)continue;
			vk[0][k][0]=min(vk[0][k-1][0],min(vk[1][k-1][0],min(vk[2][k-1][0],vk[3][k-1][0])));
			int inn=0,mi=LLONG_MAX;
			for(int j=0;j<4;j++){
				if(vk[j][k-1][0]<mi){
					mi=vk[j][k-1][0];
					inn=j;
				}
			}
			vk[0][k][1]=inn;
			if(abs(v[in-1]+v[in+1])<v[in]){
				if(v[in+1]==0)vk[1][k][0]=LLONG_MAX;
				else {
					vk[1][k][0]=min(vk[3][k-1][0]+2*v[in+1],2*v[in+1]+vk[1][k-1][0]);
					if(vk[1][k-1][0]<vk[3][k-1][0]){
						vk[1][k][1]=1;
					}else{
						vk[1][k][1]=3;
					}
				}		
			}else{
				vk[1][k][0]=LLONG_MAX;
			}
			
			vk[2][k][0]=vk[3][k-1][0];
			vk[2][k][1]=vk[3][k-1][1];	
			vk[3][k][0]=min(vk[0][k-1][0]+2*v[in+1],vk[2][k-1][0]+2*v[in+1]);
			if(vk[0][k-1][0]+2*v[in+1]<=vk[2][k-1][0]+2*v[in+1]){
				vk[3][k][1]=0;
			}else{
				vk[3][k][1]=2; 
			}
			
			if(v[in+1]==0)vk[3][k][0]=LLONG_MAX,vk[3][k][1]=-1;;
			
			if(in==n&&v[0]==0){
				vk[1][k][0]=LLONG_MAX;
				vk[1][k][1]=-1;
				vk[3][k][0]=LLONG_MAX;
				vk[3][k][1]=-1;
			}
			k++;
		}
		bana[-1]=0;
		int tr,mi=LLONG_MAX,id=0;
		for(int i=0;i<4;i++){
			if(vk[i][k-1][0]<mi){
				mi=vk[i][k-1][0];
				id=i;
			}
		}
		int ii=p.size()-1;
		if(id==1){
			bana[p[ii].se.f]=1;
			bana[p[ii].se.se]=1;
		}else if(id==2){
			bana[p[ii].se.f]=1;
		}else{
			if(id!=0)bana[p[ii].se.se]=1;
		}
		int go=id;
		ii--;
		for(int i=k-2;i>=0;i--){
			go=vk[id][i+1][1];
			if(go==1){
				bana[p[ii].se.f]=1;
				bana[p[ii].se.se]=1;
			}else if(go==2){
				bana[p[ii].se.f]=1;
				
			}else{
				if(go!=0)bana[p[ii].se.se]=1;
			}
			id=go;ii--;
		}
		/*for(int i=0;i<4;i++){
			for(int j=0;j<k;j++){
				if(vk[i][j][0]!=LLONG_MAX){
					if(vk[i][j][1]!=-1)cout<<vk[i][j][1]<<"->"<<vk[i][j][0]<<"\t";
					else cout<<"X->"<<vk[i][j][0]<<"\t";
				}else{
					cout<<"X\t";
				}
			}cout<<"\n";
		}*/
		vector<int> ans;
		for(int i=0;i<n;i++){
			if(bana[i]){
				cout<<-1*a[i]<<" ";
			}else{
				cout<<a[i]<<" ";
			}
		}cout<<"\n";
	}
}
