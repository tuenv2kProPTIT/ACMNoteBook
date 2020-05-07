#include <bits/stdc++.h>
 
const long long INF = LLONG_MAX;
const int maxn = 1003;
 
using namespace std;
 
typedef pair<long long, int> II;
 
vector<vector<II>> a;
long long d[maxn][maxn];
int pre[maxn][maxn];
int n, m, q;
 
void dijkstra(int u) {
	for(int i = 1; i <= n; ++i) d[u][i] = INF;
	d[u][u] = 0;
	pre[u][u] = u;
	priority_queue<II, vector<II>, greater<II>> q;
	q.push(make_pair(0LL, u));
	while(!q.empty()) {
		int v = q.top().second;
		long long dv = q.top().first;
		q.pop();
		if(dv > d[u][v]) continue;
		for(auto x : a[v]) {
			long long l = x.first;
			long long ans = x.second;
			if(dv + l > d[u][ans]) continue;
			d[u][ans] = dv + l;
			pre[u][ans] = v;
			q.push(make_pair(dv + l, ans));
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	a.resize(n + 1);
	while(m--) {
		long long l;
		int u, v;
		cin >> u >> v >> l;
		a[u].push_back(make_pair(l, v));
		a[v].push_back(make_pair(l, u));
	}
	for(int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	while(q--) {
		int chose, u, v;
		cin >> chose >> u >> v;
		if(chose) {
			if(u == v) {
				cout << 1 << " " << u << '\n';
				continue;
			}
			stack<int> st;
			st.push(v);
			do {
				v = pre[u][v];
				st.push(v);
			} while(v != u);
			cout << st.size() << ' ';
			while(!st.empty()) {
				cout << st.top() << ' ';
				st.pop();
			}
			cout << '\n';
		}
		else cout << d[u][v] << '\n';
	}
}
