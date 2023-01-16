#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int>> vec[100001];
int dist[100001];
const int inf = 987654321;
void dijk(int st, int ed) {
	priority_queue<pair<int, int>> pq;
	dist[st] = 0;
	for (auto e : vec[st]) 
		pq.push({ -e.second,e.first });
	while (!pq.empty()) {
		int now = pq.top().second, now_dist = -pq.top().first;
		pq.pop();
		if (dist[now] <= now_dist)continue;
		dist[now] = now_dist;
		if (now == ed)
			break;
		for (auto e : vec[now]) {
			if (dist[e.first] == inf) {
				pq.push({ -(e.second+ now_dist),e.first });
			}
		}
	}
	
	
	

	
}
int main() {
	
	


	int n, m;
	int a, b, c;

	cin >> n >> m;
	for (int i = 1; i <= n + 1; i++)
		dist[i] = inf;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
	}
	cin >> a >> b;
	dijk(a, b);
	cout << dist[b];
}




