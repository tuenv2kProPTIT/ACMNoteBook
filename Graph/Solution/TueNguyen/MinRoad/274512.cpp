#include <bits/stdc++.h>

#define i64 long long
using namespace std;
#define debug(x); { cerr << #x << " = "; cerr << (x) << endl; }
#define debugA(a,f,s); { cerr << #a << " = "; for(int i=f;i<s;i++) cerr << a[i] << ' '; cerr << endl; }
int n,m,c;
vector<pair<i64,i64> > pa[300];
vector<i64> dt;
void input()
{
    cin>>n>>m>>c;
    dt.assign(n+1,INT_MAX);
    
    for(int i=1;i<=n;i++)pa[i].clear();
    while(m--)
    {
        i64 u,v,w;
        cin>>u>>v>>w;
        
        
        pa[u].push_back(make_pair(v,w));
        pa[v].push_back(make_pair(u,w));
    }
}
void solve()
{
    priority_queue<pair<i64,i64> ,vector<pair<i64,i64> > ,greater<pair<i64,i64> > > q;
    q.push(make_pair(0,n));
    dt[n]=0;


    while(q.empty()==false)
    {
        i64 u=q.top().second;
        i64 du=q.top().first;
        q.pop();
        if(du>dt[u])continue;
        debug(u);
        debug(du);
        for(auto z:pa[u])
        {
            i64 dv=du+z.second;
            if(dv<=c)
            {
                if(dv<dt[z.first])
                {
                    dt[z.first]=dv;
                    q.push(make_pair(dv,z.first));
                }
            }
            else
            {
                //m*(c-2*l)+x>=du
                i64 l=z.second;
                i64 k=(du-c+l)/(c-2*l)+((du-c+l)%(c-2*l)!=0);
                if(c-2*l>0&&(2*k+1)*l+du<dt[z.first])
                {
                    dt[z.first]=(2*k+1)*l+du;
                    q.push(make_pair(dt[z.first],z.first));
                }
            }
        }
    }
    debugA(dt,1,n+1);
    cout<<dt[1]<<'\n';
}
int main()
{
    int multitest;
    cin>>multitest;
    while(multitest--)
    {
        input();
        solve();
    }
}
/*
 
Code written by a random fan of Tokyo_Square 
gb_DH_VNU

 */
