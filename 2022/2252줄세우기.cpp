#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ind[100000];
int visit[100000];
vector<int> edge[100000];
//순서 > 위상정렬 이문제는 시간초과 안나지만 이런거도 있다..!
int main() {
	int n, m,a,b;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		ind[b]++;
	}
	queue<int> qu;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			qu.push(i);

	}
	while (!qu.empty()) {
		int now = qu.front();
		//visit[now] = 1;
		cout << now << " ";
		qu.pop();
		for (auto nxt : edge[now]) {
			ind[nxt]--;
			if (ind[nxt] == 0)
				qu.push(nxt);
		}
	}
	

}