#include<bits/stdc++.h>
using namespace std;

#define N 1000006
struct FenwickTre2d{
    private:
    vector<int>node[N];
    vector<int>Tre[N];
    int max_size;
    public:
    FenwickTre2d(int max_sizeS){
        max_size=max_sizeS;
    }
    void fakeUp(int u,int v){
        while(u<=max_size){
            node[u].push_back(v);
            u+=(u&-u);
        }
    }
    void fakeGet(int u,int v){
        while(u){
            node[u].push_back(v);
            u-=(u&-u);
        }
    }
    void topo(){
        for(int i=1;i<=max_size;i++){
            node[i].push_back(INT_MAX);
            sort(node[i].begin(),node[i].end());
            node[i].resize(unique(node[i].begin(),node[i].end())-node[i].begin());
            Tre[i].assign(node[i].size()+5,INT_MAX);
        }
    }
    void update(int u,int v,int w){
        while(u<=max_size){
            int y=lower_bound(node[u].begin(),node[u].end(),v)-node[u].begin()+1;
            while(y<=node[u].size()){
                Tre[u][y-1]=min(Tre[u][y-1],w);
                y+=(y&-y);
            }
            u+=(u&-u);
        }
    }
    int get(int u,int v){
        int res=INT_MAX;
        while(u){
            int y=lower_bound(node[u].begin(),node[u].end(),v)-node[u].begin()+1;
            while(y){
                res=min(res,Tre[u][y-1]);
                y-=(y&-y);
            }
            u-=(u&-u);
        }
        return res;
    }
};


int main(){
    int n;
    cin>>n;
    vector<vector<int> > pos(n,vector<int>(4,0));
    for(int i=0;i<n;i++){
        cin>>pos[i][0]>>pos[i][1]>>pos[i][2]>>pos[i][3];
    }
    sort(pos.begin(),pos.end());
    FenwickTre2d solution(n+2);
    for(int i=0;i<n;i++){
        solution.fakeUp(pos[i][1],pos[i][2]);
        solution.fakeGet(pos[i][1],pos[i][2]);
    }
    solution.topo();
    int cnt=n;
    for(int i=0;i<n;i++){
        int u=pos[i][1],v=pos[i][2],w=pos[i][3];
        if(solution.get(u,v)<w){
            cnt-=1;
        }
        solution.update(u,v,w);
    }
    cout<<cnt;

}