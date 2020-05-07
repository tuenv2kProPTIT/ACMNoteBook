#include<bits/stdc++.h>
#define i64 long long
#define vi32 vector<int>
#define vi64 vector< long long>
#define  ii pair<int,int>
#define pb push_back
#define mp make_pair
#define N 100005
const  long long mod = 1e9 + 7, inf = 1e9, linf = 1 << 30; //linf = 9223372036854775807;
using namespace std;
i64 f[1000][1000];
int pos[4];
int main()
{
    int n;
    cin>>n;    
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=INT_MAX;
    for(int i=0;i<4;i++)cin>>pos[i];
    int u,v,w;
    while(scanf("%d%d%d",&u,&v,&w)==3)
    {
       // if(u==0)break;
        f[u][v]=f[v][u]=w;
    }
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    i64 res=INT_MAX;
    sort(pos,pos+4);
    do
    {
        for(int u=1;u<=n;u++)
        {
            for(int v=1;v<=n;v++)
            {
                res=min(res,f[u][pos[0]]+f[u][pos[1]]+f[v][pos[2]]+f[v][pos[3]]+f[u][v]);
            }
        }

    } while (next_permutation(pos,pos+4));
    cout<<res;


}




/* Written by a random fan of Tokyo_Square 

Association of people who died from abandonment

Gb_H

*/
