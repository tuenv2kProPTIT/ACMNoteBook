/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class FenwickTree2D{
private:
    // Matrix to store the tree
    vector<vector<ll>> ft;

public:
    // Function to get least significant bit
    int LSB(int x){return x & (-x);}
    ll query(int x, int y){
        ll sum = 0;
        for(int i = x; i > 0; i = i - LSB(i)){
            for(int j = y; j > 0; j = j - LSB(j)){
                sum = sum + ft[i][j];
            }
        }
        return sum;
    }
    ll query(int x1, int y1, int x2, int y2){
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
    }
    void update(int x, int y, ll value){
        // also update matrix[x][y] if needed.  
        for(int i = x; i < ft.size(); i = i + LSB(i)){
            for(int j = y; j < ft[0].size(); j = j + LSB(j)){
                ft[i][j] += value;
            }
        }
    }
    FenwickTree2D (int n , int m){ ft.assign(n + 1, vector<ll> (m + 1, 0)); }
    FenwickTree2D (vector<vector<ll>> matrix){
        int n = matrix.size();
        // matrix must not be empty.
        int m = matrix[0].size();
        // Initialize matrix ft
        ft.assign(n + 1, vector<ll> (m + 1, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                update(i + 1 , j + 1 , matrix[i][j]);
        }
    }
};
int n;
void Input(){
    cin >> n ; 
}
void Solve(){
    FenwickTree2D ft(n,n);
    map <pair<int,int>,int> a;
    while(1){
        string type; cin >> type;
        if(type == "SET"){
            int x,y;
            ll val;
            cin >> x >> y >> val;
            ft.update(x+1,y+1,val - a[{x+1,y+1}]);
            a[{x+1,y+1}]  = val;
        }
        else if (type == "SUM"){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << ft.query(x1+1,y1+1,x2+1,y2+1) << '\n';
        }
        else return;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
