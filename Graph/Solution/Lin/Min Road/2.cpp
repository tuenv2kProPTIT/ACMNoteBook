#include <bits/stdc++.h>
 
const long long INF = LLONG_MAX;
const int maxn = 5005;
 
using namespace std;
 
typedef pair<long long, int> II;
vector<vector<II>> a;
long long pre[maxn];
long long d[maxn];
int n, m;
 
void dijkstra() {
	priority_queue<II, vector<II>, greater<II>> q;
	for(int i = 1; i <= n; ++i) d[i] = INF;
	d[1] = 0;
	pre[1] = 1;
	q.push(make_pair(0LL, 1));
	while(!q.empty()) {
		long long du = q.top().first;
		int u = q.top().second;
		q.pop();
		if(du > d[u]) continue;
		for(auto x : a[u]) {
			int v = x.second;
			long long l = x.first;
			if(du + l > d[v]) continue;
			if(du + l < d[v]) {
				pre[v] = pre[u];
				d[v] = du + l;
				q.push(make_pair(d[v], v));
			}
			else {
				pre[v] += pre[u];
				d[v] = du + l;
			}
		}
	}
}
 
int main() {
	cin >> n >> m;
	a.resize(n + 1);
	while(m--) {
		int u, v, ans;
		long long dis;
		cin >> ans >> u >> v >> dis;
		a[u].push_back(make_pair(dis, v));
		if(ans == 2) {
			a[v].push_back(make_pair(dis, u));
		}
	}
	dijkstra();
	cout << d[n] << ' ' << pre[n];
} 
