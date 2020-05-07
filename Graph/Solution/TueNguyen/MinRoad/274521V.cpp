#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<stack>

#define i64 long long
#define vi32 vector<int>
#define vi64 vector< long long>
#define  ii pair<int,int>
const  long long mod = 1e9 + 7, inf = 1e9, linf = 1 << 30; //linf = 9223372036854775807;
const long long hashmod[4] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
const long double EPS = 0.000000001L, pi = acos(-1);
using namespace std;
#define pb push_back
#define mp make_pair
#define N 1000006
//i64 base = 311;

int dt[N];
struct node
{
	int v;
	int cost;
	int len;
	node(int _v = 0, int _cost = 0, int _len = 0)
	{
		v = _v;
		cost = _cost;
		len = _len;
	}
	
};
bool operator > (node a, node b)
{
	return a.cost > b.cost;
}
vector<node> pa[N];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k, n, m;
		cin >> k >> n >> m;
		for (int i = 1; i <= n; i++)dt[i] = inf;
		while (m--)
		{
			int u, v, c, l;
			cin >> u >> v >> l >> c;
			pa[u].pb(node(v, c, l));
		}
		priority_queue<node, vector<node>, greater<node> > q;
		q.push(node(1, 0, 0));
		while (q.size())
		{
			int v = q.top().v;
			int c = q.top().cost;
			int l = q.top().len;
			q.pop();
			if (l > dt[v])continue;
			dt[v] = l;
			for (auto z : pa[v])
			{
				if (c + z.cost > k)continue;
				q.push(node(z.v, c + z.cost, l + z.len));
			}
		}
		if (dt[n] == inf)dt[n] = -1;
		cout << dt[n]<<'\n';
		if (t)
		{
			for (int i = 1; i <= 1000; i++)pa[i].clear();
		}
	}
}