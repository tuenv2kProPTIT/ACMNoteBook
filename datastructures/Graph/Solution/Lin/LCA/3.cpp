#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
 
using namespace std;
 
int n, k, root;
vector<vector<int>> Graph, Group;
int deep[maxn], P[maxn][23];
bool Visit[maxn];
 
void DFS(int u = root, int dep = 1) {
	Visit[u] = true;
	deep[u] = dep;
	for(auto x : Graph[u]) {
		if(Visit[x]) continue;
		P[x][0] = u;
		DFS(x, dep + 1);
	}
}
 
void Pre_LCA() {
	for(int k = 1; k <= 19; ++k) {
		for(int i = 1; i <= n; ++i) {
			P[i][k] = P[P[i][k - 1]][k - 1];
		}
	}
}
 
int LCA(int u, int v) {
	if(deep[u] > deep[v]) swap(u, v);
	for(int i = 19; i >= 0; --i) {
		if(deep[P[v][i]] >= deep[u]) v = P[v][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; --i) {
		if(P[u][i] != P[v][i]) {
			u = P[u][i];
			v = P[v][i];
		}
	}
	return P[u][0];
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	Graph.resize(n + 1);
	Group.resize(k + 1);
	for(int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		if(y == 0) {
			root = i;
			Group[x].push_back(i);
		}
		else {
			Graph[i].push_back(y);
			Graph[y].push_back(i);
			Group[x].push_back(i);
		}
	}
	P[root][0] = root;
	DFS();
	Pre_LCA();
	for(int i = 1; i <= k; ++i) {
		if(Group[i].size() == 0) {
			cout << 0 << '\n';
			continue;
		}
		int Max = 0, node = Group[i][0];
		for(auto x : Group[i]) {
			if(deep[x] > deep[node]) node = x;
		}
		for(auto x : Group[i]) {
			int dis = deep[node] + deep[x] - 2 * deep[LCA(node, x)];
			if(dis > Max) Max = dis;
		}
		cout << Max << '\n';
	}
} 
