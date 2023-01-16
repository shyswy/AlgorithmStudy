#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int>> edge[10001];
vector<pair<int, int>> rev[10001];
//������ �ߺ����� �ʱ⸸ �ص� ����

int ind[10001];
int dist[10001];
int visit[10001];

int st, ed;
int ans = 0;

void dfs(int x) {
	
	if (visit[x])
		return;
	visit[x] = 1;
	for (auto prev : rev[x]) {
		if (dist[prev.first] + prev.second == dist[x]) {//�ִܰ�� ���ɼ��ִ� ����

			dfs(prev.first);
			ans++;
			
		
			}

		}
		
}
	




queue<pair<int, int>> qu;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		rev[b].push_back({ a,c });

		ind[b]++;
	}
	cin >> st >> ed;
	
	qu.push({ st,0 });
	while (!qu.empty()) {
		int now = qu.front().first, now_dist = qu.front().second;
		qu.pop();
		for (auto nxt : edge[now]) {
			if (dist[nxt.first] < dist[now] + nxt.second)
				dist[nxt.first] = dist[now] + nxt.second;
			ind[nxt.first]--;
			if (ind[nxt.first] == 0)
				qu.push(nxt);
		}
	}
	cout << dist[ed] << endl;

	dfs(ed);
	cout << ans;
	/*



	queue<pair<int,int>> root;
	root.push({ed,0});

	while (!root.empty()) {
		int now = root.front().first, now_num = root.front().second;
		root.pop();

		if (now == st) {

		}
		for (auto prev : rev[now]) {
			if (dist[now]- prev.second==dist[prev.first]) {





				root.push({ prev.first,now_num+1 });
			}
		}
	}
	cout << aa[st];
	*/


}