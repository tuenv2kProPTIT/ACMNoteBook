#include<bits/stdc++.h>
using namespace std;
#define N 200006
#define i64 long long
struct node
{
    int a,b,h;
};
i64 f[N];
void update(int u,i64 v)
{
    while(u<N)
    {
        f[u]=max(f[u],v);
        u+=(u&-u);
    }
}
i64 get(int p)
{
    i64 res=0;
    while(p)
    {
        res=max(res,f[p]);
        p-=(p&-p);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<node> pos(n);
    vector<int>topo;
    for(auto &z:pos)
        cin>>z.a>>z.b>>z.h,topo.push_back(z.a),topo.push_back(z.b);
    sort(topo.begin(),topo.end());
    topo.resize(unique(topo.begin(),topo.end())-topo.begin());
    for(auto & z:pos)
    {
        z.a=lower_bound(topo.begin(),topo.end(),z.a)-topo.begin()+2;
        z.b=lower_bound(topo.begin(),topo.end(),z.b)-topo.begin()+2;
    }
    sort(pos.begin(),pos.end(),[](node a,node b){
        if(a.b==b.b)return a.a>b.a;
        return a.b>b.b;
    });

   // for(auto z:pos)cout<<z.a<<' '<<z.b<<' '<<z.h<<endl;
   // cout<<"end\n";
    update(pos[0].a,pos[0].h);
    i64 ans=pos[0].h;
    for(int i=1;i<n;i++)
    {
        i64 tmp=get(pos[i].b-1);
       // cout<<tmp<<endl;
        update(pos[i].a,pos[i].h+tmp);
        ans=max(ans,tmp+pos[i].h);
       // cout<<ans<<endl;
    }
    cout<<ans;

    
    
}
