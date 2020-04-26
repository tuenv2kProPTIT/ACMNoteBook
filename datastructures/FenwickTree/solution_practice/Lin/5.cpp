#include <bits/stdc++.h>
const int maxn = 1e5 + 10;

using namespace std;

vector<vector<int>> a(maxn);
int ST[4 * maxn];

void build(int id, int l, int r)
{
	if(l == r)
	{
		ST[id] = 1;
		return ;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2  + 1, mid + 1, r);
	ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

void update(int id, int l, int r, int pos)
{
	if(l > pos || r < pos)
	{
		return ;
	}
	if(l == pos && pos == r)
	{
		ST[id] = 0;
		return ;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, pos);
	update(id * 2 + 1, mid + 1, r, pos);
	ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

int Get(int id, int l, int r, int left, int right)
{
	if(l > right || r < left)
	{
		return 0;
	}
	if(left <= l && r <= right)
	{
		return ST[id];
	}
	int mid = (l + r) / 2;
	return Get(id * 2, l, mid, left, right) + Get(id * 2 + 1, mid + 1, r, left, right);
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		int ans;
		cin >> ans;
		a[ans].push_back(n + 1 - i);
	}
	build(1, 1, n);
	long long res = 0;
	int from = n;
	for(int i = 1; i <= (int) 1e5; ++i)
	{
		if(a[i].size() == 0) continue;
		sort(a[i].begin(), a[i].end());
		int ans = upper_bound(a[i].begin(), a[i].end(), from) - a[i].begin();
		if(ans == a[i].size())
		{
			res += Get(1, 1, n, a[i][0], from);
			from = a[i][0] - 1;
		}
		else
		{
			res += Get(1, 1, n, 1, from);
			res += Get(1, 1, n, a[i][ans], n);
			from = a[i][ans] - 1;
		}
		if(from == 0) from = n;
		for(int j = 0; j < a[i].size(); ++j)
		{
			update(1, 1, n, a[i][j]);
		}
	}
	cout << res;
}
