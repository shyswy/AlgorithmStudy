#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int>> edge[10001];
vector<pair<int, int>> rev[10001];
//�ð��ʰ�!
bool v[100010000];
int ind[10001];
int dist[10001];

int st, ed;
int ans = 0;

//�ð��ʰ� 


//1��, ���� dist[prev.first] + prev.second == dist[x] ���ؼ� � ������ �߰��ߴµ�, ���� ��������
// �ִܰŸ��� �ƴϰԵ� ���ɼ��� ����.

// 1(�����) >3 ����� 7�̰�		3>5(������)  ����� 2    = 1>5 ���,      
//dist[prev.first] +				prev.second				== dist[x]

//�� ���ÿ��� �� �� �ִ°�, �ܼ��� 5> 3�� �մ� ������ '���ɼ� �ִ�' �� �ƴ϶�, ������ ���Եȴ�.
//�ֳĸ�  1>3 ���� ���� ���� ��� �ִ�, ó�� �������ķ� ����� �Ÿ������� 1>3�Ÿ��� 7, �� �츮�� ã��
//���� �Ÿ����� ����Ǿ��⿡.


//������ ���� dist[prev.first] + prev.second == dist[x] �� ������ ó���� ����ϰ� ������, ������� �����ϴ� ����
//����Ǿ�� �ش� ������ �����ο� ���Եȴٰ� ���ܼ� �̻�������.

//1�Ʒ� dfs���� 
//1: ���� ��ġ�� ���Ҷ� visit(�ߺ�) üũ ���� �ʴ´�. �װ��� ������� �����ϴ� ���� Ȯ���ϰ� ������,
//return���� ���ƿö� visit üũ( ���� ����� ���޸��ϴ� ����̾����� visit üũ�ϸ� �ȵǱ⿡

//2: edge�� �ߺ��� �˻��ߴ�.


//�� 2���� Ʋ�ȴ�.

//������ ó�� dist[prev.first] + prev.second == dist[x] ����� ����, �ش� ������ �����ο� 100% ����
//�׸��� ������ üũ�ϸ鼭 ������ �ȴ�.




bool dfs(int x) {
	bool chk = false;
	bool chk2 = false;
	if (x == st) {


		return true;

	}
	for (auto prev : rev[x]) {
		if (dist[prev.first] + prev.second == dist[x]) {//�ִܰ�� ���ɼ��ִ� ����

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
		else {// ���¿� ��ΰ� �ִܰ�� x ��� 
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