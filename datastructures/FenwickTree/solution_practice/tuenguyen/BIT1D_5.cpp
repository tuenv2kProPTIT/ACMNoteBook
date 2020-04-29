#include<bits/stdc++.h>
using namespace std;

#define N 60006

int f[N];
void update(int u,int val){
    while(u>=0){
        f[u]+=val;
        u&=(u+1);
        u-=1;
    }
}
int get(int u){
    int x=0;
    while(u<N){
        x+=f[u];
        u|=(u+1);
        // u-=1;
    }
    return x;
}
int main(){
    int n;
    cin>>n;
    long long ans=0;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans+=get(x+1);
        update(x,1);
    }
    cout<<ans;
    
}   