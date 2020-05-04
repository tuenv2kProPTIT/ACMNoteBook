#include <bits/stdc++.h>
const int maxn = 1005;
 
using namespace std;
 
int n, q;
int deep[maxn];
int P[maxn][23];
int dis[maxn];
int d[maxn][maxn];
int parent[maxn];
vector<vector<int>> a;
bool Visit[maxn];
 
void DFS(int u = 1, int dep =1) {
	Visit[u] = true;
	deep[u] = dep;
	for(auto x : a[u]) {
		if(Visit[x]) continue;
		dis[x] = dis[u] + d[u][x];
		parent[x] = u;
		DFS(x, dep + 1);
	}
}
 
void pre_lca() {
	for(int i = 1; i <= n; ++i) P[i][0] = parent[i];
	for(int k = 1; k <= 19; ++k) {
		for(int i = 1; i <= n; ++i) {
			P[i][k] = P[P[i][k - 1]][k - 1];
		}
	}
}
 
int lca(int u, int v) {
	if(deep[u] > deep[v]) swap(u, v);
	for(int i = 19; i >= 0; --i) {
		if(deep[P[v][i]] >= deep[u]) v = P[v][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; --i) {
		if(P[u][i] != P[v][i]) u = P[u][i], v = P[v][i];
	}
	return P[u][0];
}
 
int main() {
	cin >> n >> q;
	a.resize(n + 1);
	for(int i = 1; i < n; ++i) {
		int x, y, l;
		cin >> x >> y >> l;
		a[x].push_back(y);
		a[y].push_back(x);
		d[x][y] = d[y][x] = l;
	}
	DFS();
	parent[1] = 1;
	pre_lca();
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x] + dis[y] - 2 * dis[lca(x, y)] << '\n';
	}
} 
