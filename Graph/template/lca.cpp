#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define N 1000000
vector<int> Map[N];
vector<int> fa,dept,heavy;
vector<int> head,value,pos;
vector<int> Q;
int offset;
int dfs(int u)
{
    int siz=1;
    int masiz=0;
    for(auto z:Map[u])
    {
        if(z!=fa[u])
        {
            dept[z]=dept[u]+1;
            fa[z]=u;
            int si=dfs(z);siz+=si;
            if(si>masiz)
            {
                masiz=si;   
                heavy[u]=z;
            }
        }
    }
    return siz;
}
void hld(int u,int h)
{
    Q[offset]=value[u];
    head[u]=h;
    pos[u]=offset++;
    if(heavy[u]!=-1)
    {
        hld(heavy[u],h);
    }
    for(auto z:Map[u])
    {
        if(z!=fa[u]&&z!=heavy[u])hld(z,z);
    }
}
template<class T>class ST
{
private:
    vector<T> tre;
    int n;
public:
    void resert(const vector<T> &Q)
    {
        tre.assign(Q.size()*4+10,0);
        build(1,0,Q.size()-1,Q);
        n=Q.size();
    }
    void build(int node,int l,int r,const vector<int> &Q)
    {
        if(l==r)
        {
            tre[node]=Q[l];
            return;
        }
        build(node*2,l,(l+r)/2,Q);
        build(node*2+1,(l+r)/2+1,r,Q);
        tre[node]=tre[node*2]+tre[node*2+1];
    }
    void update(int node,int l,int r,int i)
    {
       // cout<<l<<' '<<r<<' '<<i<<endl;
        if(l==r&&r==i)
        {
            if(tre[node]==1)tre[node]=0;
            else tre[node]=1;
            return;
        }
        if(l>i||r<i)return;
        int mid=(l+r)>>1;
        if(mid<i)update(node*2+1,(l+r)/2+1,r,i);
        else update(node*2,(l),(l+r)/2,i);
        tre[node]=tre[node*2]+tre[node*2+1];
    }
    void update(int i){update(1,0,n-1,i);}
    int get(int node,int l,int r,int i,int j)
    {
        if(l>j||r<i)return 0;
        if(i<=l&&r<=j)return tre[node];
        int ll=get(node*2,(l),(l+r)/2,i,j);
        int rr =get(node*2+1,(l+r)/2+1,r,i,j);
        return ll+rr;
    }
    int get(int i ,int j){return get(1,0,n-1,i,j);}
};
ST<int> tre;
int query(int u,int v,int & lca)
{
    int res=0;
    while(head[u]!=head[v])
    {
        if(dept[head[u]]>dept[head[v]])swap(u,v);
        res+=tre.get(pos[head[v]],pos[v]);
        v=fa[head[v]];
    }
    if(dept[u]>dept[v])swap(u,v);
    lca=u;
    return res+tre.get(pos[u],pos[v]);
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    char s[N];
    scanf("%s",s);
    value.push_back(0);
    for(int i=0;i<n;i++)
    {
        value.push_back(s[i]-'0');
    }
    heavy.assign(n+1,-1);
    fa.assign(n+1,0);
    Q.assign(n+1,0);
    dept.assign(n+1,0);
    head.assign(n+1,0);
    pos.assign(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        u++;
        v++;
        Map[u].push_back(v);
        Map[v].push_back(u);
    }
    offset=1;
    dfs(1);
    hld(1,1);
    
    tre.resert(Q);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type==0)
        {
            int u;
            scanf("%d",&u);
            u++;
           
            tre.update(pos[u]);

        }
        else
        {
            int u,v;
            scanf("%d%d",&u,&v);u++;v++;
            int lca=1;
            int res=query(u,v,lca);
            if(dept[u]+dept[v]-2*dept[lca]==res-1||res==0)printf("YES\n");
            else printf("NO\n");
            
        }
        

    }
}