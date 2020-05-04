#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define cin32(t) scanf("%d", &t)
#define cin64(t) scanf("%lld", &t)
#define endl '\n'
#define N 100006
int multitest = 0;
struct query{
    int type;
    int l,r;
    int val=0;
    query(int t,int ll,int rr,int val){
        type=t;
        l=ll;r=rr;
        this->val=val;
    }
};
struct Bit
{
    vector<int> node[N];
    vector<i64>f[N];
    int find(int i,int j){
        return (lower_bound(node[i].begin(),node[i].end(),j)-node[i].begin());
    }
    void fakeU(int i,int j){
        while(i<N){
            node[i].push_back(j);
            i|=(i+1);
        }
    }
    void fakeG(int i,int j)
    {
        while(i>=0)
        {
            node[i].push_back(j);
            i&=(i+1);i--;
        }
    }
    void topo()
    {
        for(int i=0;i<N;i++)
        {
            sort(node[i].begin(),node[i].end());
            node[i].resize(unique(node[i].begin(),node[i].end())-node[i].begin());
            f[i].assign(node[i].size()+2,0);
        }
    }
    void Up(int i,int j,int val){
        while(i<N)
        {
            int ptr=find(i,j);
            while(ptr>=0)
            {
                f[i][ptr]+=val;
                ptr&=(ptr+1);
                ptr--;
            }
            i|=(i+1);
        }
    }
    i64 Get(int i,int j)
    {
        i64 res=0;
        while(i>=0)
        {
            int ptr=find(i,j);
            while(ptr<f[i].size())
            {
                res+=f[i][ptr];
                ptr|=(ptr+1);
            }
            i&=(i+1);i--;
        }
        return res;
    }
    vector<i64> solve(vector<query > _query){
        for(auto q:_query)
        {
            if(q.type==1)fakeU(q.l,q.r);
            else fakeG(q.r,q.l),fakeG(q.l-1,q.l);
        }
        vector<i64> ans;
        topo();
        for(auto q:_query)
        {
            if(q.type==1)
            {
                Up(q.l,q.r,q.val);
            }
            else ans.push_back(Get(q.r,q.l)-Get(q.l-1,q.l));
        }
        return ans;
    }
};
Bit Work;
set<int>S[N];
vector<int>A;
vector<query> Q;
int n, q;
void change(int p, int val)
{
    vector<int>c(0, 0);
    auto it = S[A[p]].find(p);
    if (it != S[A[p]].begin())
    {
        c.push_back(*(--it));
        it++;
    }
    c.push_back(p);it++;
    if (it != S[A[p]].end())
    {
        c.push_back(*it);
    }
    if (c.size() == 1)return;
    if (c.size() == 2)
    {
        Q.push_back(query(1,c[1], c[0], (c[1]-c[0]) *val));
    }
    else
    {
         Q.push_back(query(1,c[1], c[0], (c[1]-c[0]) *val));
         Q.push_back(query(1,c[2], c[1], (c[2]-c[1]) *val));
         Q.push_back(query(1,c[2], c[0], (c[2]-c[0]) *-1*val));
    }
}

void solve()
{
    cin32(n);cin32(q);
    A.resize(n+1);
    for (int i = 1;i <= n;i++)
    {
        cin32(A[i]);
        S[A[i]].insert(i);
       
    }
    for (int i = 1;i <= n;i++)
    {
        auto it = S[A[i]].find(i);
        if (it != S[A[i]].begin())
        {
            --it;
            Q.push_back(query(1,i,*it,i-*it));
        }
    }
  
    
    //cout << "q\n";
    
    while (q--)
    {
        int t, p, s;
        cin32(t);cin32(p);cin32(s);
        if (t == 1)
        {
            change(p, -1);
           
            S[A[p]].erase(p);
            A[p] = s;
            S[s].insert(p);
            change(p, 1);
            
        }
        else
        {
            Q.push_back(query(2,p,s,0));
        }
    }
    vector<i64> ans=Work.solve(Q);
    for(auto z:ans)cout<<z<<endl;
    
    
}
void input() {}
int main()
{


    if (multitest) {
        int t;
        cin>>t;
        while (t--) {input();solve();}
      }
    else
    {
        input();
        solve();
    }

}
/*

Code written by a random fan of Tokyo_Square 
gb_DH_VNU
I_LOve_DH
*/