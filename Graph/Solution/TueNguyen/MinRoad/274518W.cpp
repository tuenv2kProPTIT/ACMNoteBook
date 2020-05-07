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
vi64 dis, cnt;
vector<bool> proces;
int main()
{
	int n, m;
	cin >> n >> m;
	dis.assign(n + 1, inf);
	cnt.assign(n + 1, 0);
	proces.assign(n + 1, 0);
	while (m--)
	{
		int k, u, v, l;
		cin >> k >> u >> v >> l;
		if (k == 1)
		{
			pa[u].pb(mp(v, l));
		}
		else
		{
			pa[u].pb(mp(v, l));
			pa[v].pb(mp(u, l));
		}
	}
	cnt[1] = 1;
	dis[1] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push(mp(0, 1));
	while (!q.empty())
	{
		int u = q.top().second;
		int d = q.top().first; q.pop();
		if (proces[u])continue;
		proces[u] = 1;
		for (auto z : pa[u])
		{
			if (dis[z.first] > z.second + d)
			{
				dis[z.first] = z.second + d;
				cnt[z.first] = cnt[u];
				q.push(mp(z.second + d, z.first));
			}
			else
			{
				if (dis[z.first] == z.second + d)
				{
					cnt[z.first] += cnt[u];
				}
			}
		}
	}
	cout << dis[n] << ' ' << cnt[n];
}
