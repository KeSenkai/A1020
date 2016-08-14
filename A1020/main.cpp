#include<cstdio>  
#include<string>  
#include<cstring>  
#include<vector>  
#include<iostream>  
#include<queue>  
#include<algorithm>  
using namespace std;
typedef long long LL;
const int INF = 0x7FFFFFFF;
const int maxn = 1e3 + 10;
int n, a[maxn], b[maxn], ch[maxn][2], root;

void dfs(int&x, int l, int r, int ll, int rr)
{
	if (l > r) x = 0;
	for (int i = l; i <= r; i++)
	{
		if (a[i] == b[rr])
		{
			x = i;
			dfs(ch[x][0], l, i - 1, ll, ll + i - l - 1);
			dfs(ch[x][1], i + 1, r, ll + i - l, rr - 1);
		}
	}
}

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) scanf_s("%d", &b[i]);
	for (int i = 1; i <= n; i++) scanf_s("%d", &a[i]);
	dfs(root, 1, n, 1, n);
	queue<int> p; p.push(root);
	while (!p.empty())
	{
		int q = p.front();  p.pop();
		if (root != q) printf(" ");
		printf("%d", a[q]);
		if (ch[q][0]) p.push(ch[q][0]);
		if (ch[q][1]) p.push(ch[q][1]);
	}
	printf("\n");
	system("pause");
	return 0;
}