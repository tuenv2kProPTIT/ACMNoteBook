#include<bits/stdc++.h>
using namespace std;
#define N 400006
#define i64 long long

struct BIT{
	vector<int> F;
	BIT(){
		F.assign(400006,0);
	}
	void Update(int p){
		while(p<N)
		{
			F[p]+=1;
			p|=(p+1);
		}
	}
	int Get(int p)
	{
		int res=0;
		while(p>=0)
		{
			res+=F[p];
			p&=(p+1);p--;
		}
		return res;
	}
};
#define ii pair<int,int>
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<ii>p(n);
	vector<int>Pos;
	for(auto &z:p)cin>>z.first>>z.second,Pos.push_back(z.first),Pos.push_back(z.second);
	sort(Pos.begin(),Pos.end());
	Pos.resize(unique(Pos.begin(),Pos.end())-Pos.begin());
	for(auto &z:p){
		z.first=lower_bound(Pos.begin(),Pos.end(),z.first)-Pos.begin()+1;
		z.second=lower_bound(Pos.begin(),Pos.end(),z.second)-Pos.begin()+1;
	}
	//for(auto z:p)cout<<z.first<<' '<<z.second<<endl;cout<<"end\n";
	sort(p.begin(),p.end());
	//for(auto z:p)cout<<z.first<<' '<<z.second<<endl;cout<<"end\n";
	BIT Work=BIT();
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int mi=Work.Get(p[i].second);
		//cout<<i<<' '<<mi<<endl;
		Work.Update(p[i].second);
		int mii=abs(n-1-mi);
		mi=abs(mi-mii);
		
		if(mi>=k)cnt++;
	}
	cout<<cnt<<'\n';
	
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}