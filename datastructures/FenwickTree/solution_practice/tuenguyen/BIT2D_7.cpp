#include <bits/stdc++.h>
using namespace std;
#define N 200006
#define i64 long long
#define ii pair<int, int>
vector<pair<int, int>> C, D;
int F[N][25];
int Log[N];
void process(vector<pair<int, int> > X)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<25;j++)F[i][j]=0;
    }
    for(int i=0;i<X.size();i++)F[i][0]=X[i].second;
    for(int k=1;k<25;k++)
    {
        for(int i=0;i+(1LL<<k)<=X.size();i++)
        {
            F[i][k]=max(F[i][k-1],F[i+(1LL<<(k-1))][k-1]);
        }
    }
}
int get(int u, int v)
{
    int k=Log[v-u+1];
    int tmp=v-(1LL<<(k))+1;
    int ans= max(F[u][k],F[tmp][k]);//cout<<u<<' '<<v<<' '<<ans<<endl;
    return ans;
}

int main()
{
    int n, c, d;
    cin >> n >> c >> d;
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i / 2] + 1;
    while (n--)
    {
        int cost, beuty;
        char type;
        cin >> beuty >> cost >> type;
        if (type == 'D')
            D.push_back({cost, beuty});
        else
            C.push_back({cost, beuty});
    }
    sort(C.begin(), C.end() );
    sort(D.begin(), D.end());
    int ans=0;
    if (C.size() && D.size())
    {
        int ansl = 0, ansr = 0;
        for (auto z : C)
        {
            if (z.first <= c)
            {
                ansl = max(ansl, z.second);
            }
        }
        for (auto z : D)
        {
            if (z.first <= d)
            {
                ansr = max(ansr, z.second);
            }
        }
        if (ansl != 0 && ansr != 0)
            ans = max(ans, ansl + ansr);
    }
   // cout<<ans<<endl;
    process(C);

    for(int i=0;i<C.size();i++)
    {
        int cc=c-C[i].first;
        if(cc<=0)break;
        int l=i+1;
        int r=C.size()-1;
        int ll=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(C[mid].first<=cc)
            {
                l=mid+1;
                ll=mid;
            }
            else r=mid-1;
        }
        if(ll!=i)
        {
            ans=max(ans,get(i+1,ll)+C[i].second);
        }
    }
   // cout<<ans<<endl;
    process(D);
    for(int i=0;i<D.size();i++)
    {
        int dd=d-D[i].first;
        if(dd<=0)break;
        int l=i+1;
        int r=D.size()-1;
        int ll=i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(D[mid].first<=dd)
            {
                l=mid+1;
                ll=mid;
            }
            else r=mid-1;
        }
        if(ll!=i)ans=max(ans,get(i+1,ll)+D[i].second);
    }
   // cout<<ans;


    cout << ans;
}