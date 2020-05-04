/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <int,ll > cnt;
vector < ll > a;
int n;
void Input(){
    cin >> n ; a.resize(n);
    for(auto &x : a) cin >> x;
}
void Solve(){
    long double res = 0 , pre = 0;
    for(int i = 0 ; i < n ; i++){
        res += (long double)a[i] * (long double)i  - pre - (long double) cnt[a[i] - 1] + (long double) cnt[a[i] + 1];
        cnt[a[i]]++;
        pre += (long double)a[i];
    }
    cout << fixed << setprecision(0) << res;
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
