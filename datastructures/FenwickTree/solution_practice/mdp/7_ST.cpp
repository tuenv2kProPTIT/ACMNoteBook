/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector < pair<int,int> > a,b;
int n,m,k;
class SegmentTree{
private :
    vector < int > Tree;
    vector< pair<int,int> > p;
public :
    int merge(int a , int b){ return max(a,b);}
    void build(int node , int l , int r){
		if ( l == r ){
			Tree[node] = p[l-1].second;
			return;
		}
		int mid = l + r >> 1;
		build(node*2,l,mid);
		build(node*2+1,mid+1,r);
		Tree[node] = merge(Tree[node*2],Tree[node*2+1]);
	}
    int get(int node , int l , int r , int x , int y){
		if ( l > y || r < x) return 0;
		if ( x <= l && r <= y ) return Tree[node];
		int mid = l + r >> 1;
		int a = get(node*2,l,mid,x,y);
		int b = get(node*2+1,mid+1,r,x,y);
		return merge(a,b);
	}
    SegmentTree ( vector< pair<int,int>> p){
        int sz = p.size();
        Tree.assign(4*sz+5,0) ;
        this->p = p;
    }
};
void Input(){
    cin >> n >> m >> k; 
    for(int i = 0 ; i < n ; i++){
        int u,w;
        char t;
        cin >> u >> w >> t;
        if(t == 'C') a.push_back({w,u});
        else b.push_back({w,u});
    }
}
int Find(vector <pair<int,int>> c , int val){
    if( c.size() <= 1 ) return 0;
    sort(c.begin(),c.end());
    SegmentTree st(c);
    st.build(1,1,c.size());
    int res = 0;
    for(int i = 0 ; i < c.size() - 1 ; i++){
        if( val >= c[i].first){
            int pos = upper_bound(c.begin(),c.end(),make_pair(val-c[i].first+1,0)) - c.begin() - 1;
            //cout << i << ' ' << pos << ' ' << st.get(1,1,c.size(),i+2,pos+1) << '\n';
            if(pos <= i) break;
            else res = max(res,c[i].second+st.get(1,1,c.size(),i+2,pos+1));
        }
    }
    //cout << res << '\n';
    return res;
}
int doubFind(){
    int res = 0 , res1 = 0;
    for(int i = 0 ; i < a.size() ; i++)
        if(a[i].first <= m) res = max(res,a[i].second);
    for(int i = 0 ; i < b.size() ; i++)
        if(b[i].first <= k) res1 = max(res1,b[i].second);
    if( res == 0 || res1 == 0) return 0;
    else return (res + res1);
}
void Solve(){
    cout << max(doubFind(),max(Find(a,m),Find(b,k)));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}