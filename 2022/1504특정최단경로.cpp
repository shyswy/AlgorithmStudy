#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<pair<int, int>> pq;
const int max_v = 20005;
vector<pair<int, int>> edge[max_v];
const int inf = 987654321;
vector<int>dist(max_v, inf);//����� �⺻�� inf��
vector<int>tmp(max_v, inf);//�ʱ�ȭ�� 

//edge[u].first >> v  .second>> w
//�켱����ť�� pair������ 1�����ڷ� ũ��񱳸���
//�״��� 2�����ں�.
//pq    first: ����ġ, second: ��������
//�̷��� �ؾ� ����ġ ������ ����

void er_all() {
	while (!pq.empty())      //�ʱ�ȭ
		pq.pop();
	for (int i = 0; i < max_v; i++)
		dist[i] = tmp[i];
}

void dijk(int n) {
	dist[n] = 0; //�����ΰ��°Ÿ��� 0
	for (auto e : edge[n]) {//ù����������ȳ�� push(�ʱ⼼��)

		if (dist[e.first] == inf)
			pq.push({ -e.second,e.first });

	}
	while (!pq.empty()) {//�Ż���Ŭ���� pq���� �������� ������ �� ������ �� ������
		int now, nowdist;//����ȳ��push, �Ұ��ϸ� �ϴ� ��ŵ
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();
		if (dist[now] < nowdist) continue;//���ŵǴ� dist ���� ���� �ִܰŸ�.���ŵ��� �ʾ�����(inf) �ִܰŸ� �������ش�.
		dist[now] = nowdist;
		for (auto e : edge[now]) {//���Ӱ�  ���ŵ� �ִܰ�θ� ���� ��� �߰�.
			if (dist[e.first] == inf)//ù��° ������ ���� ���� �ȵȳ�鸸 ��� ã��(�̹� ���� ���ִٸ� �̹� �ִܰ��.
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
	ans = dist[p2];// p1 <> p2 �� ��δ� ������ ���ԵǾ���. 
	n1 = dist[n];// p1> n �� �ִܰŸ�
	er_all();

	dijk(p2);
	n2 = dist[n];// p2> n�� �ִܰŸ�
	er_all();

	dijk(1);
	f1 = dist[p1];
	f2 = dist[p2];
	if ((f1 + n2) < (f2 + n1)) { //������ ��ġ�� �ִܰ���� ���̽��� 2��.  1>p1>p2> n Ȥ�� 1>p2>p1>n
		ans += (f1 + n2);
	}
	else
		ans += (f2 + n1);

	if (ans >= inf || ans < 0)// inf �� �տ����� ���� �����÷ο츦 �����Ѵ�. . max_v �� õ������ �ص� ����.
		cout << -1;
	else
		cout << ans;





}



