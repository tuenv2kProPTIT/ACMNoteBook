/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class FenwickTree2D{
private:
    // Matrix to store the tree
    vector<vector<int>> ft;

public:
    // Function to get least significant bit
    int LSB(int x){return x & (-x);}
    int query(int x, int y){
        int sum = 0;
        for(int i = x; i > 0; i = i - LSB(i)){
            for(int j = y; j > 0; j = j - LSB(j)){
                sum = sum + ft[i][j];
            }
        }
        return sum;
    }
    int query(int x1, int y1, int x2, int y2){
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
    }
    void update(int x, int y, int value){
        // also update matrix[x][y] if needed.  
        for(int i = x; i < ft.size(); i = i + LSB(i)){
            for(int j = y; j < ft[0].size(); j = j + LSB(j)){
                ft[i][j] += value;
            }
        }
    }

    FenwickTree2D (vector<vector<int>> matrix){
        int n = matrix.size();
        // matrix must not be empty.
        int m = matrix[0].size();
        // Initialize matrix ft
        ft.assign(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                update(i + 1 , j + 1 , matrix[i][j]);
        }
    }
};
vector < vector <int> > a;
int n,q;
void Input(){
    cin >> n >> q;  
    a.assign(n , vector<int> (n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char x ; cin >> x;
            a[i][j] = (x - 'A' + 1);
        }
    }
}
void Solve(){
    FenwickTree2D ft(a);
    //cout << ft.query(1,1,4,4) << '\n';
    while(q--){
        int type ; cin >> type;
        if( type ){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << ft.query(x1+1,y1+1,x2+1,y2+1) << '\n';
        }
        else{
            int z,pos;
            string tmp;
            cin >> z >> pos >> tmp;
            for(int i = 0 ; i < n ; i++)
                if(z == 1 ) ft.update(i+1,pos+1,(int (tmp[i] - 'A') - a[i][pos] + 1)) ;
                else  ft.update(pos+1,i+1,(int (tmp[i] - 'A') - a[pos][i]) + 1) ;
           
        }
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
