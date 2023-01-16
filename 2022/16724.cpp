#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;
const int max_v = 11000000;
int parent[1000];
string str[1000];
pair<char,int> ma[1000][1000];
//safe 존까지 거리 저장.
int n, m;
int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
	
}
void join(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx != yy) {
		parent[yy] = parent[xx];
	}
}
int visit[1100000];

void dfs(int x, int y) {//맵밖가는 경우수 없다. 따라서 배제
	int i = x, j = y;
	visit[i * n + j] = 1;
	if (find(i) == find(j))
		return;
	if (ma[i][j].first == 'U') {
		join((j - 1) * n + i, i + j * n);//한칸 위 정점을 자식으로
		dfs((j - 1) * n + i, i + j * n);
	}
	if (ma[i][j].first == 'D') {
		join((j + 1) * n + i, i + j * n);
		dfs((j + 1) * n + i, i + j * n);
	}
	if (ma[i][j].first == 'L') {
		join((j)*n + i - 1, i + j * n);
		dfs((j)*n + i - 1, i + j * n);
	}
	if (ma[i][j].first == 'R') {
		join((j)*n + i + 1, i + j * n);
		dfs((j)*n + i + 1, i + j * n);

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < n; j++)
			ma[i][j].first = str[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i * n + j]) continue;
			dfs(i, j);
			ans++;
				
				
			
		}
	}
	cout << ans;
	


}