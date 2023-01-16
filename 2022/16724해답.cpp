#include <bits/stdc++.h>
using namespace std;

int cnt = 1;
vector<string> grid;
vector<vector<int>> check;

void dfs(int x, int y) {
	int nx = x, ny = y;
	switch (grid[x][y]) {
	case 'D':
		nx++;
		break;
	case 'U':
		nx--;
		break;
	case 'L':
		ny--;
		break;
	case 'R':
		ny++;
		break;
	}
	if (check[nx][ny] != 0) {
		if (check[nx][ny] == cnt) cnt++;
		check[x][y] = check[nx][ny];
		return;
	}
	check[x][y] = cnt
	dfs(nx, ny);
	check[x][y] = check[nx][ny];
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}
	check = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] != 0) continue;
			
			dfs(i, j);

		}
	}

	cout << cnt - 1;
}