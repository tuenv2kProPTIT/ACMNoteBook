#include <bits/stdc++.h>
const int maxn = 1e4 + 10;
const int oo = 1e9;

using namespace std;

int n, m;
vector<vector<int>> a;
int Num[maxn], Low[maxn];
int cnt, Count;
stack<int> st;

void Tajan(int u)
{
	Num[u] = Low[u] = ++cnt;
	st.push(u);
	for(int x : a[u])
	{
		if(Num[x])
		{
			Low[u] = min(Low[u], Num[x]);
		}
		else
		{
			Tajan(x);
			Low[u] = min(Low[u], Low[x]);
		}
	}
	if(Num[u] == Low[u])
	{
		Count++;
		int v;
		do
		{
			v = st.top();
			Num[u] = Num[v] = oo;
			st.pop();
		}while(v != u);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	while(m--)
	{
		int u, v;
		scanf("%d%d",&u, &v);
		a[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
	{
		if(!Num[i]) Tajan(i);
	}
	cout << Count;
}
