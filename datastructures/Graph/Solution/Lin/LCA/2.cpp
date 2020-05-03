#include <bits/stdc++.h>
#define mp make_pair
const int maxn = 1e5 + 10;
 
using namespace std;
 
typedef pair<int, int> II;
 
int n, q;
vector<vector<II>> a;
bool Visit[maxn];
int deep[maxn];
int P[maxn][23];
int Wmax[maxn][23];
int Wmin[maxn][23];
 
void DFS(int u = 1, int dep = 1) {
	Visit[u] = true;
	for(auto x : a[u]) {
		if(Visit[x.first]) continue;
		deep[x.first] = deep[u] + 1;
		Wmax[x.first][0] = Wmin[x.first][0] = x.second;
		P[x.first][0] = u;
		DFS(x.first, dep + 1);
	}
}
 
void Pre() {
	for(int k = 1; k <= 19; ++k) {
		for(int i = 1; i <= n; ++i) {
			P[i][k] = P[P[i][k - 1]][k - 1];
			Wmin[i][k] = min(Wmin[i][k - 1], Wmin[P[i][k - 1]][k - 1]);
			Wmax[i][k] = max(Wmax[i][k - 1], Wmax[P[i][k - 1]][k - 1]);
		}
	}
}
 
II Find(int u, int v) {
	int Max = 0, Min = INT_MAX;
	if(deep[u] > deep[v]) swap(u, v);
	for(int i = 19; i >= 0; --i) {
		if(deep[P[v][i]] >= deep[u]) {
			Min = min(Min, Wmin[v][i]);
			Max = max(Max, Wmax[v][i]);
			v = P[v][i];
			if(u == v) break;
		}
	}
	if(u == v) return mp(Min, Max);
	for(int i = 19; i >= 0; --i) {
		if(P[u][i] != P[v][i]) {
			Min = min(min(Min, Wmin[u][i]), Wmin[v][i]);
			Max = max(max(Max, Wmax[u][i]), Wmax[v][i]);
			v = P[v][i];
			u = P[u][i];
		}
	}
	Min = min(min(Min, Wmin[u][0]), Wmin[v][0]);
	Max = max(max(Max, Wmax[u][0]), Wmax[v][0]);
	return mp(Min, Max);
}
 
int main() {
	cin >> n;
	a.resize(n + 1);
	for(int i = 1; i < n; ++i) {
		int x, y, l;
		cin >> x >> y >> l;
		a[x].push_back(mp(y, l));
		a[y].push_back(mp(x, l));
	}
	for(int k = 0; k <= 19; ++k) {
		for(int i = 1; i <= n; ++i) Wmin[i][k] = INT_MAX;
	}
	DFS();
	P[1][0] = 1;
	Pre();
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		II ans = Find(x, y);
		cout << ans.first << ' ' << ans.second << '\n';
	}
} 
