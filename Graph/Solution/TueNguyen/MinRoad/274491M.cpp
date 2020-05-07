clude <bits/stdc++.h>
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
#include<assert.h>
#define i64  long long
#define vi32 vector<int>
#define vi64 vector< long long>
#define  ii pair<int,int>
const  long long mod = 1e9 + 7, inf = 1e9, linf = 1 << 30;//linf = 9223372036854775807;
const long long hashmod[4] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
const long double EPS = 0.000000001L, pi = acos(-1);
using namespace std;
#define pb push_back
#define mp make_pair
#define N 100006
//i64 base = 311;
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
// God of debug OPP
#define debugg assert
using namespace std;
vector<ii> pa[N];
vi32 dt[N];
vi32 fa[N];
vector<bool> dfs[N];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		pa[u].pb(mp(v, w));
		pa[v].pb(mp(u, w));
	}
	for (int i = 1; i <= n; i++)
	{
		dt[i].assign(n + 1, inf);
		fa[i].assign(n + 1, i);
		dfs[i].assign(n + 1, false);
	}
	for (int i = 1; i <= n; i++)
	{
		dt[i][i] = 0;
		priority_queue<ii, vector<ii>, greater<ii> >q;
		q.push(mp(0, i));
		while (!q.empty())
		{
			ii front = q.top(); q.pop();
			if (dfs[i][front.second])continue;
			dfs[i][front.second] = true;
			for (auto z : pa[front.second])
			{
				if (dt[i][z.first] > dt[i][front.second] + z.second)
				{
					dt[i][z.first] = dt[i][front.second] + z.second;
					q.push(mp(dt[i][z.first], z.first));
					fa[i][z.first] = front.second;
				}
			}
		}
	}
	while (k--)
	{
		int t, u, v;
		cin >> t >> u >> v;
		if (!t)
		{
			cout << dt[u][v] << '\n';
		}
		else
		{
			int d = 1;
			int cur = u;
			vi32 ans;
			
			while (cur != v)
			{
				ans.push_back(cur);
				d++;
				
				cur = fa[v][cur];
			}
			cout << d << '\n';
			for (auto z : ans)cout << z << ' ';
			cout << v << ' ';
			cout << '\n';
		}
	}
}
 