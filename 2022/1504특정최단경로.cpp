#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<pair<int, int>> pq;
const int max_v = 20005;
vector<pair<int, int>> edge[max_v];
const int inf = 987654321;
vector<int>dist(max_v, inf);//모든노드 기본값 inf로
vector<int>tmp(max_v, inf);//초기화용 

//edge[u].first >> v  .second>> w
//우선순위큐에 pair넣으면 1번인자로 크기비교먼저
//그다음 2번인자비교.
//pq    first: 가중치, second: 도착정점
//이렇게 해야 가중치 순으로 정리

void er_all() {
	while (!pq.empty())      //초기화
		pq.pop();
	for (int i = 0; i < max_v; i++)
		dist[i] = tmp[i];
}

void dijk(int n) {
	dist[n] = 0; //스스로가는거리는 0
	for (auto e : edge[n]) {//첫정점과연결된놈들 push(초기세팅)

		if (dist[e.first] == inf)
			pq.push({ -e.second,e.first });

	}
	while (!pq.empty()) {//매사이클마다 pq안의 정점으로 도달할 수 있으면 그 정점과
		int now, nowdist;//연결된놈들push, 불가하면 일단 스킵
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();
		if (dist[now] < nowdist) continue;//갱신되는 dist 값은 전부 최단거리.갱신되지 않았으면(inf) 최단거리 갱신해준다.
		dist[now] = nowdist;
		for (auto e : edge[now]) {//새롭게  갱신된 최단경로를 통한 경로 추가.
			if (dist[e.first] == inf)//첫번째 정점과 아직 연결 안된놈들만 계속 찾기(이미 값이 들어가있다면 이미 최단경로.
				pq.push({ -(nowdist + e.second),e.first });
		}
	}
}

int main() {
	int a, b, c, n, e, p1, p2, ans, n1, n2, f1, f2;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	cin >> p1 >> p2;
	dijk(p1);
	ans = dist[p2];// p1 <> p2 의 경로는 무조건 포함되야함. 
	n1 = dist[n];// p1> n 의 최단거리
	er_all();

	dijk(p2);
	n2 = dist[n];// p2> n의 최단거리
	er_all();

	dijk(1);
	f1 = dist[p1];
	f2 = dist[p2];
	if ((f1 + n2) < (f2 + n1)) { //두정점 거치는 최단경로의 케이스는 2개.  1>p1>p2> n 혹은 1>p2>p1>n
		ans += (f1 + n2);
	}
	else
		ans += (f2 + n1);

	if (ans >= inf || ans < 0)// inf 의 합연산은 스택 오버플로우를 유발한다. . max_v 를 천만으로 해도 정답.
		cout << -1;
	else
		cout << ans;





}



