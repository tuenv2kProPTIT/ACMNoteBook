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
const  long long mod = 1e15 + 7, inf = 2147483647, linf = 9223372036854775807;
const long long hashmod[4] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
const long double EPS = 0.000000001L, pi = acos(-1);
using namespace std;
#define pb push_back
#define mp make_pair
#define N 100005
//int base = 311;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
using namespace std;
int pos[29][N];
int tre[29][4*N];
int laz[29][4 * N];
string s;
void build(int node, int l, int r,char a)
{
	if (l == r)
	{
		tre[a - 'a'][node] = (s[l] == a) ? 1 : 0;
		return;
	}
	build(node << 1, l, (l + r) >> 1, a);
	build(node << 1 | 1, (l + r) / 2 + 1, r, a);
	tre[a - 'a'][node] = tre[a - 'a'][node << 1] + tre[a - 'a'][node << 1 | 1];
}
void build()
{
	memset(laz, -1, sizeof(laz));
	for (int i = 'a'; i <= 'z'; i++)build(1, 0, s.size() - 1, char(i));
}
void update(int node, int l, int r,int ll,int rr, char a,int val)
{
	if (laz[a - 'a'][node] != -1)
	{
		tre[a - 'a'][node] = laz[a - 'a'][node]*(r-l+1);
		if (l != r)
		{
			laz[a - 'a'][node << 1] = laz[a - 'a'][node];
			laz[a - 'a'][node << 1 | 1] = laz[a - 'a'][node];
		}
		laz[a - 'a'][node] = -1;
	}
	if (l > rr || r < ll)return;
	if (ll <= l && r <= rr)
	{
		tre[a - 'a'][node] = val*(r-l+1);
		if (l != r)
		{
			laz[a - 'a'][node << 1] = val;
			laz[a - 'a'][node << 1 | 1] = val;
		}
		return;
	}
	update(node << 1, l,(l + r) / 2, ll, rr, a, val);
	update(node << 1 | 1, (l + r) / 2 + 1, r, ll, rr, a, val);
	tre[a - 'a'][node] = tre[a - 'a'][node << 1] + tre[a - 'a'][node << 1 | 1];
}
int get(int node, int l, int r, int ll, int rr, char a)
{
	if (l > rr || r < ll)return 0;
	if (laz[a - 'a'][node] != -1)
	{
		tre[a - 'a'][node] = laz[a - 'a'][node]*(r-l+1);
		if (l != r)
		{
			laz[a - 'a'][node << 1] = laz[a - 'a'][node];
			laz[a - 'a'][node << 1 | 1] = laz[a - 'a'][node];
		}
		laz[a - 'a'][node] = -1;
	}
	if (ll <= l && r <= rr)
	{
		return tre[a - 'a'][node];
	}
	return get(node << 1, l, (l + r) >> 1, ll, rr, a) + get(node << 1 | 1, (l + r) / 2 + 1, r, ll, rr, a);
}
int main()
{
	int n, q;
	scanf("%d%d",&n,&q);
	
	cin >> s;
	build();
//	cout << get(1, 0, n - 1, 0, 5, 'a');
	while (q--)
	{
		int l, r, t;
		scanf("%d%d%d",&l,&r,&t);
		l--;
		r--;
		if (t)
		{
			int cur = l;
			for (int i = 'a'; i <= 'z'; i++)
			{
				int len = get(1, 0, n - 1, l, r, char(i));
				update(1, 0, n - 1, l, r, char(i), 0);
				update(1, 0, n - 1, cur, cur + len - 1, char(i), 1);
				cur = cur + len; if (cur > r)break;
			}
		}
		else
		{
			int cur = r;
			for (int i = 'a'; i <= 'z'; i++)
			{
				int len = get(1, 0, n - 1, l, r, char(i));
				update(1, 0, n - 1, l, r, char(i), 0);
				update(1, 0, n - 1, cur-len+1, cur , char(i), 1);
				cur = cur - len; if (cur <l)break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 'a'; k <= 'z'; k++)
		{
			if (get(1, 0, n - 1, i, i, char(k)) == 1)
			{
				cout << char(k);
				break;
			}
		}
	}
}