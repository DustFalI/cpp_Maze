#include <bits/stdc++.h>
using namespace std;
int n, m, t, sx, sy, fx, fy, maze[10][10] = {0}, ans = 0;
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
void dfs(int x, int y)
{
	if(x == fx && y == fy)
	{
		ans++;
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		if(maze[x + dx[i]][y + dy[i]] == 1)
		{
			maze[x + dx[i]][y + dy[i]] = 0;
			dfs(x + dx[i], y + dy[i]);
			maze[x + dx[i]][y + dy[i]] = 1;
		}
	}
}
int main()
{
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			maze[i][j] = 1;
		}
	}
	for(int i = 1; i <= t; i++)
	{
		int x, y;
		cin >> x >> y;
		maze[x][y] = 0;
	}
	maze[sx][sy] = 0;
	dfs(sx,sy);
	cout << ans;
	return 0;
}
