#include <bits/stdc++.h>
 
const long long INF = LLONG_MAX;
const int maxn = 105;
 
using namespace std;
 
typedef pair<long long, int> II;
 
vector<vector<II>> a;
long long d[maxn][maxn];
int n, m;
 
void dijkstra(int u) {
	priority_queue<II, vector<II>, greater<II>> q;
	for(int i = 1; i <= n; ++i) d[u][i] = INF;
	d[u][u] = 0;
	q.push(make_pair(0, u));
	while(!q.empty()){
		long long du = q.top().first;
		int v = q.top().second;
		q.pop();
		if(du > d[u][v]) continue;
		for(auto x : a[v]) {
			long long l = x.first;
			int ans = x.second;
			if(du + l >= d[u][ans]) continue;
			d[u][ans] = du + l;
			q.push(make_pair(d[u][ans], ans));
		}
	}
}
 
int main() {
	cin >> n;
	a.resize(n + 1);
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	int u, v;
	long long c;
	while(cin >> u) {
		cin >> v >> c;
		a[v].push_back(make_pair(c, u));
		a[u].push_back(make_pair(c, v));
	}
	long long res = LLONG_MAX;
	for(int i = 1; i <= n; ++i) dijkstra(i);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			long long ans = d[i][j];
			ans += min(d[i][a1], d[j][a1]) + min(d[i][a2], d[j][a2]) + min(d[i][a3], d[j][a3]) + min(d[i][a4], d[j][a4]);
			res = min(res, ans);
		}
	}
	cout << res;
} 
