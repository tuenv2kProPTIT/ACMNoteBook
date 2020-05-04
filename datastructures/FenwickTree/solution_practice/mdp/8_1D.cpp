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
int n,q;
vector < ll > a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    
}
void Solve(){
    sort(a.begin(),a.end());
    FenwickTree ft(a);
    cin >> q; 
    while(q--){
        ll lval , rval;
        cin >> lval >>  rval;
        int l = lower_bound(a.begin(),a.end(),lval) - a.begin();
        int r = upper_bound(a.begin(),a.end(),rval) - a.begin() - 1;
        //cout << l << ' ' << r << '\n';
        cout << ft.query(l+1,r+1) << '\n';
    }
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
