#include<bits/stdc++.h>
using namespace std;
#define N 1000006
int F[N][2];
void update(int u,int v,int t)
{
    while(u<N)
    {
        F[u][t]+=v;
        u+=(u&-u);
    }
}
int get(int u,int t)
{
    int res=0;
    while (u)
    {
        res+=F[u][t];
        u-=(u&-u);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int>pos(n);for(auto &z:pos)cin>>z;
    vector<int> topo=pos;
    sort(topo.begin(),topo.end());
    for(auto &z:pos)z=lower_bound(topo.begin(),topo.end(),z)-topo.begin()+1;
    for(auto z:pos)update(z,1,1);
    int offset=n+4;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
       long long l=get(pos[i]-1,1);
       long long r=get(offset,0)-get(pos[i],0);
       ans+=l*r;
       update(pos[i],1,0);update(pos[i],-1,1);
    }
    cout<<ans;

    
}
