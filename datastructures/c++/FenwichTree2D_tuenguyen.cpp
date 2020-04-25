
#include <bits/stdc++.h>
using namespace std;

struct Bit
{
    #define i64 long long
    int N;
    vector<int> node[1000006];
    vector<i64>f[100006];
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
    
};