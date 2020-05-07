#include<bits/stdc++.h>
#define i64 long long
#define vi32 vector<int>
#define vi64 vector< long long>
#define  ii pair<i64,i64>
const  long long mod = 1e9 + 7, inf = 1e9, linf = 1 << 30; //linf = 9223372036854775807;
const long long hashmod[4] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
const long double EPS = 0.000000001L, pi = acos(-1);
using namespace std;
#define pb push_back
#define mp make_pair
#define N 200005
//int base = 311;
using namespace std;
vector<ii> pa[N];
int dt1[N],dt2[N],g1[N],g2[N];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pa[u].pb(mp(v,w));
        pa[v].pb(mp(u,w));
    }
    for(int i=1;i<=n;i++)
        dt1[i]=dt2[i]=inf;
    priority_queue<pair<int,int> ,vector<ii> ,greater<ii> >q;
    q.push(mp(0,1));
    dt1[1]=0;
    g1[1]=g2[n]=1;
    while(q.empty()==false)
    {
        int w=q.top().first;
        int u=q.top().second;
        q.pop();
        if(dt1[u]<w)continue;
        for(auto z:pa[u])
        {
            if(dt1[z.first]>z.second+dt1[u])
            {
                g1[z.first]=g1[u];
                dt1[z.first]=z.second+dt1[u];
                q.push(mp(dt1[z.first],z.first));
            }
            else
            {
                if(dt1[z.first]==z.second+dt1[u])g1[z.first]+=g1[u];
            }
        }
    }
    while(q.empty()==false)q.pop();
    dt2[n]=0;
    q.push(mp(0,n));
    while(q.empty()==false)
    {
        int w=q.top().first;
        int u=q.top().second;
        q.pop();
        if(dt2[u]<w)continue;
        for(auto z:pa[u])
        {
            if(dt2[z.first]>z.second+dt2[u])
            {
                g2[z.first]=g2[u];
                dt2[z.first]=z.second+dt2[u];
                q.push(mp(dt2[z.first],z.first));
            }
            else
            {
                if(dt2[z.first]==z.second+dt2[u])g2[z.first]+=g2[u];
            }
        }
    
    }
    int res=dt1[n];
    int cnt=0;
    
    for(int i=2;i<n;i++)
    {
        if(dt1[i]+dt2[i]>res)cnt++;
        else
        {
            if(g1[i]*g2[i]<g1[n])cnt++;
        }

    }
    cout<<cnt<<'\n';
    for(int i=2;i<n;i++)
    {

        if(dt1[i]+dt2[i]>res)cout<<i<<'\n';
        else
        {
            if(g1[i]*g2[i]<g1[n])cout<<i<<'\n';
        }
    }

}




/* Written by a random fan of Tokyo Square music

Association of people who died from abandonment

Gb_H_24_11_2000

*/
