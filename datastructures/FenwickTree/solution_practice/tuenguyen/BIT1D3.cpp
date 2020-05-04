#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define i64 long long
#define ii pair<int,int>
int n,m;
vector<int> topo;
vector<ii> pos;
i64 Tre[N],dp[N];
const i64 mod=int(1e9+7);
void update(int u,i64 value)
{
    while(u<N)
    {
        Tre[u]=(Tre[u]+value)%mod;
        u+=(u&-u);
    }
}
i64 get(i64 u)
{
    i64 x=0;
    while(u)
    {
        x=(x+Tre[u])%mod;
        u-=(u&-u);
    }
    return x%mod;
}
int main()
{

    cin>>n>>m;
    pos.resize(m);
    topo.push_back(0);
    topo.push_back(n);
    for(auto & z:pos)cin>>z.first>>z.second,topo.push_back(z.first),topo.push_back(z.second);
    sort(topo.begin(),topo.end());
    topo.resize(unique(topo.begin(),topo.end())-topo.begin());
    for(auto  & z:pos)
    {
        z.first=lower_bound(topo.begin(),topo.end(),z.first)-topo.begin()+1;
        z.second=lower_bound(topo.begin(),topo.end(),z.second)-topo.begin()+1;
    }
    sort(pos.begin(),pos.end(),[](ii a ,ii b){if(a.second==b.second)return a.first<b.first;return a.second<b.second;});
    update(1,1LL);
    dp[1]=1;
    for(auto z:pos)
    {
        dp[z.second]=((get(z.second-1))%mod-get(z.first-1)+mod*mod)%mod;
        update(z.second,dp[z.second]%mod);
    }
    cout<<(get(topo.size())-get(topo.size()-1)+mod)%mod;



}
