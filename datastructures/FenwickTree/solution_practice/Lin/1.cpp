#include <bits/stdc++.h>
const int maxn = 2e5 + 10;

using namespace std;

int a[maxn];
long long dp[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + a[i];
	}
	long long res = 0;
	for(int i = 1; i <= n; ++i)
	{
		int ans = upper_bound(a + 1, a + 1 + n, a[i] + 1) - a;
		cout << ans << ' ';
	}
}

