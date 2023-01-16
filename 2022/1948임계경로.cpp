#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int>> edge[10001];
vector<pair<int, int>> rev[10001];
//시간초과!
bool v[100010000];
int ind[10001];
int dist[10001];

int st, ed;
int ans = 0;

//시간초과 


//1번, 내가 dist[prev.first] + prev.second == dist[x] 통해서 어떤 간선을 추가했는데, 다음 간선에서
// 최단거리가 아니게될 가능성은 없다.

// 1(출발지) >3 비용이 7이고		3>5(도착지)  비용이 2    = 1>5 비용,      
//dist[prev.first] +				prev.second				== dist[x]

//위 예시에서 알 수 있는건, 단순히 5> 3번 잇는 간선이 '가능성 있다' 가 아니라, 무조건 포함된다.
//왜냐면  1>3 으로 가는 길이 몇개가 있던, 처음 위상정렬로 계산한 거리값에서 1>3거리는 7, 즉 우리가 찾는
//최장 거리임이 증명되었기에.


//하지만 나는 dist[prev.first] + prev.second == dist[x] 이 공식을 처음에 통과하고 나서도, 출발지에 도착하는 것이
//증명되어야 해당 간선이 최장경로에 포함된다고 여겨서 이상해진것.

//1아래 dfs에선 
//1: 다음 위치로 향할때 visit(중복) 체크 하지 않는다. 그것이 출발지에 도달하는 것을 확인하고 나서야,
//return으로 돌아올때 visit 체크( 만약 출발지 도달못하는 놈들이었으면 visit 체크하면 안되기에

//2: edge의 중복을 검사했다.


//위 2개는 틀렸다.

//어차피 처음 dist[prev.first] + prev.second == dist[x] 통과한 순간, 해당 간선은 최장경로에 100% 포함
//그리고 정점만 체크하면서 나가면 된다.




bool dfs(int x) {
	bool chk = false;
	bool chk2 = false;
	if (x == st) {


		return true;

	}
	for (auto prev : rev[x]) {
		if (dist[prev.first] + prev.second == dist[x]) {//최단경로 가능성있는 간선

			chk = dfs(prev.first);
			if (chk)
				chk2 = true;
			//cout << prev.first << ">" << x <<"   ee:" << chk << endl;
			if (chk == true) {
				if (v[prev.first * 10001 + x] != 1) {
					v[prev.first * 10001 + x] = 1;

					ans++;
				}





				//cout << prev.first << ">" << x << endl;
				/*
				if (visit[prev.first][x] != 1) {

					visit[prev.first][x] = 1;
					ans++;
				}
				

				if (v[prev.first * 10001 + x] != 1) {
					v[prev.first * 10001 + x] = 1;

					ans++;
				}
				*/
			}

		}
		else {// 여태온 경로가 최단경로 x 라면 
			chk = false;
		}
	}
	return chk2;


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