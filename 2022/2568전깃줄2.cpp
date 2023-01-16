#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[500001];
vector<int> dp;
vector<pair<int, int>> track;// �ش���Ҹ� ������ lis ����, �ش����
vector<pair<int, int>> vec;
bool visit[500001];
int main() {
	//lis ��� ã��. 

	int n, a,b,len=0;//len�� �ǽð����� ���ϴ� lis ���� ����
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a>>b;
		vec.push_back({ a,b });
		visit[a] = true;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		int bb = vec[i].second;//i°�� ���� a������ ��ġ�� ����� ���� b�����뿡 ����� ��ġ.
		if (dp.size() == 0 || dp.back() < bb) {
			dp.push_back(bb);
			track.push_back({ ++len, vec[i].first });//���� ū���� ���Դ�> ���±����� LIS+ ���� ���� �� �� ���ο� LIS. 
			//���ο� LIS�� ���� LIS ���� (LEN) +1
			
		}
		else {
			int iter = lower_bound(dp.begin(), dp.end(), bb) - dp.begin();
			dp[iter] = bb;
			track.push_back({ iter+1 ,vec[i].first });
		}
	
	}

	cout << n-dp.size()<<endl;

	for (int i = track.size() - 1; i >= 0; i--) {//�����ʺ��� Ž������
		if (track[i].first == len) {				// ��ü lis �� ã�� ��, �ش� ���Ҹ� �������� lis ��� ����.
			//cout << track[i].second << endl;		//���� ��ġ ã��: ���̰� ���� ���� -1�̰� 
													//���� ������ ���� �� �������ִ³�. >> �� ������ Ȯ�ξ��ص� �ȴ�
			visit[track[i].second] = false;			//  1 2 3   4 9 8(lis) �� ����    �����������   1,2,3,4,8 ã�� ��. 
													//�ش� ��ġ���� ������ �Էµ� ���ҵ� �� ���̰� ������ �� ū �� �� ���� x 
		}
		if (len == 0)
			break;
	}
	for (int i = 1; i <500001; i++) {
		if (visit[i]==true)
			cout << i << "\n";

	}
	
}