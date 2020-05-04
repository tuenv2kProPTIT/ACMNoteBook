/*  author : mdp
    problem : https://codeforces.com/problemset/problem/61/E
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class FenwickTree{
private:
    vector<ll> ft;
public:
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
vector < int > a;
map <int,vector<int>> d;
int n;
void Input(){
    cin >> n ; a.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        d[a[i]].push_back(i);
    }

}
void Solve(){
    int key = 1;
    for(auto x : d){
        for(auto xx : x.second) a[xx] = key;
        key++;
    }
    FenwickTree ft(1000005);
    ll res = 0;
    for(int i = n ; i >= 1 ; i--){
        int q = ft.query(a[i]);
        res += 1LL*q*(q+i-a[i]);
        ft.update(a[i],1);
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
