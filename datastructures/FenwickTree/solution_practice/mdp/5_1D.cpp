/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class FenwickTree{
private:
    // Matrix to store the tree
    vector<ll> ft;

public:
    // Function to get least significant bit
    int LSB(int x){return x & (-x);}
    ll query(int x){
        ll sum = 0;
        for(int i = x; i > 0; i = i - LSB(i))
            sum = sum + ft[i];
        return sum;
    }
    ll query(int l , int r){
        return (query(r) - query(l-1));
    }
    void update(int x, ll value){ 
        for(int i = x; i < ft.size(); i = i + LSB(i))
                ft[i] += value;
    }
    FenwickTree (int n){ ft.assign(n + 1,0);}
    FenwickTree (vector<ll> arr){
        int n = arr.size(); ft.assign(n + 1,0);
        for(int i = 0; i < n; ++i) update(i + 1 ,arr[i] );
    }
};
int n ;
vector < ll > a;
map <ll,vector<int>> b;
void Input(){
    cin >> n ; a.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        b[a[i]].push_back(i);
    }
}
void Solve(){
    FenwickTree ft(n);
    for(int i = 1 ; i <= n ; i++) ft.update(i,1);
    //cout << ft.query(1,n);
    int pre = 1 ; ll res = 0;
    for(auto &z : b){
        sort(z.second.begin(),z.second.end());
        int pos = lower_bound(z.second.begin(),z.second.end(),pre) - z.second.begin();
        //cout << pos << '\n';
        for(auto zz : z.second){
            if(pos == z.second.size()) pos = 0;
            ll r = z.second[pos];
            if( pre <= r) res += ft.query(pre,r);
            else res += ft.query(pre,n) + ft.query(1,r);
            //cout << r << ' ' <<  res << '\n';
            ft.update(r,-1);
            pre = r , pos ++;
        }
    }
    cout << res ;
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
