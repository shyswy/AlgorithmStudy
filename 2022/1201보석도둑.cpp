#include <iostream>
#include<queue>
using namespace std;
typedef pair<int, int> p;
priority_queue<int> pq;
p b[300001];
int c[300001];
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> b[i].first >> b[i].second;

	for (int i = 0; i < k; i++)
		cin >> c[i];

	sort(b, b + n);
	sort(c, c + k);//���� ���԰� �������� �������� ����. >> �����͵��� ��ġ�� ���� ���� ���� ��Ī������Ѵ�


	long long ans = 0;
	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && b[j].first <= c[i])
			pq.push(b[j++].second);				// ����� pq�� �ְ� �̾ƽᵵ �Ǵ� ����: ������ �ڿ����� ������ '�� ũ��' 
		if (!pq.empty()) {						
			ans += pq.top();					//�տ��� �߰��� �������� ������ ���� ����鿡�� ����!!
			pq.pop();							
		}										
	}
	cout << ans;
}