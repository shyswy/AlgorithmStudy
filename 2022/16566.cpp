#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> card;
vector<int> v;
vector<int> p;
int find(int x) {
	if (x==p[x])
		return x;
	return p[x]=find(p[x]);

}
void join(int x, int y) {
	int p_x = find(x), p_y = find(y);
	if (p_x != p_y)
		p[p_y] = p_x;

}

int main() {
	ios_base::sync_with_stdio(false);    
	cin.tie(0);
	cout.tie(0);

	int n, m, k,tmp,idx;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		v.push_back(tmp);// �μ��� �� �� �ִ� ī�� ���
		p.push_back(i);
	}
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		card.push_back(tmp);//����(ö��) �� �� ī�尡 ������� ����.
	}
	sort(v.begin(), v.end()); // �� �� �ִ� ī�� ����� �������� ����( ���� ������ ���� �տ� ����)
	for (int i = 0; i < k; i++) {
		idx=  find( upper_bound(v.begin(), v.end(), card[i])-v.begin() );   
		//disjoin set ���� �ߺ� ����
		// ����� ī��(idx°)�� idx+1° ��( �� ������ �־��ش�) 
		//v ���ʹ� �������� ������ ���ֱ⿡, idx+1�� idx�������� ������ >> �ߺ�
		//i° ���ʿ� ö���� �� ī�庸�� ū �� �� ���ʷ� ������ ��ġ == ū �� �� ���� ���� ���� ��ġ
		cout<<v[idx]<<endl;
		//v.erase(v.begin()+ idx);    �׳� erase�� �ߺ� ���Ž�  O(N)�� �ð��� ��� �ð��ʰ�����!
		if (i == k - 1)
			break;
		join(idx + 1, idx);
	}
}