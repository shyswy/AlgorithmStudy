#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[33000];
int ind[33000];
int main() {
	priority_queue<int> qu;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		ind[b]++;
	}


	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)qu.push(-i);
	}

	while (!qu.empty()) {
		int now = -qu.top();
		qu.pop();
		cout << now << " ";

		for (auto nxt : edge[now]) {
			ind[nxt]--;
			if (ind[nxt] == 0)
				qu.push(-nxt);
		}
	}
}