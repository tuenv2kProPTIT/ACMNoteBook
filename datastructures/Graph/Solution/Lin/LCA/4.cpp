#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>
#include <sstream>
#include <iomanip>
const int maxn = 2e5 + 200;
 
using namespace std;
 
int n, m;
vector<vector<int>> a;
bool Visit[maxn];
int deep[maxn], P[maxn][20], parent[maxn];
 
void DFS(int u = 1, int dep = 1) {
	Visit[u] = true;
	deep[u] = dep;
	for(auto x : a[u]) {
		if(Visit[x]) continue;
		P[x][0] = u;
		DFS(x, dep + 1);
	}
}
 
void Pre() {
	for(int k = 1; k <= 18; ++k) {
		for(int i = 1; i <= n; ++i) {
			P[i][k] = P[P[i][k - 1]][k - 1];
		}
	}
}
 
int LCA(int u, int v) {
	if(deep[u] > deep[v]) swap(u, v);
	for(int i = 18; ~i; --i) {
		if(deep[v] - (1 << i) >= deep[u]) v = P[v][i];
	}
	if(u == v) return u;
	for(int i = 18; ~i; --i) {
		if(P[u][i] ^ P[v][i]) {
			u = P[u][i];
			v = P[v][i];
		}
	}
	return P[u][0];
}
 
int Find(int u, int v) {
	if(parent[u] == u && deep[u] > deep[v]) {
		parent[u] = P[u][0];
		Visit[u] = true;
		return parent[u] = Find(parent[u], v);
	}
	if(parent[u] == u) return u;
	return parent[u] = Find(parent[u], v);
}
 
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for(int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	P[1][0] = 1;
	for(int i = 1; i <= n; ++i) parent[i] = i;
	DFS();
	Pre();
	for(int i = 1; i <= n; ++i) Visit[i] = false;
	scanf("%d", &m);
	while(m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		int par = LCA(u, v);
		if(u != par) {
			parent[u] = P[u][0];
			Visit[u] = true;
		}
		Find(u, par);
		if(v != par) {
			parent[v] = P[v][0];
			Visit[v] = true;
		}
		Find(v, par);
	}
	int cnt = 0;
	Visit[1] = false;
	for(int i = 1; i <= n; ++i) {
		if(!Visit[i]) cnt++;
	}
	printf("%d", cnt - 1);
} 
