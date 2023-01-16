#include <iostream>
#include <vector>
#include<algorithm>//lower bound
using namespace std;
//O(NlogN)
long long int ans;
int N;
vector<int> v;
long long int idx[9876543];  // �ش� ��ġ�� ���� ������ lcs ���̸� �����Ѵ�. 
vector<long long int> lcs;
long long int arr[9876543];
int main() {
	long long int prev;
	cin >> N;

	v.push_back(-1000000001);   //������ �ʱ�ȭ �� �� �ִ� ���� ���� ��. 

	for (int i = 0; i < N; i++) {
		//int x;
		cin >> arr[i];
		if (arr[i] > v.back()) {//�Է� ���� ���� ���� ���� ��� ������ Ŭ�� �߰��ϰ� ans++;
			v.push_back(arr[i]);
			ans++;
			idx[i] = ans;   // ���� ���� ���� ��ȭ�� ���� ����. 
			//prev = arr[i];

		}
		else {
			int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();//upperbound �� x�� "�ʰ�" �ϴ� ���� ó�������� ��ġ ��ȯ
			//  -v.begin() �� ����  '��ġ ��' ����  ������� ��ġ ���� �ε��� ������ ��ȯ. 
			v[it] = arr[i];  //lower bound�� x "�̻�" �� ���� ó�� ������ ��ġ ��ȯ.
			idx[i] = it;
			// lower, upper bound �� ����� ����Ž���� ���� �������� �ʾƵ� �ȴ�!.
			
		}
	}
	cout << ans << endl;

	bool chk = false;
	int k = 0;
	for (int i = N - 1; i >= 0; i--) { //��� ����. ������ > ������� lcs ��θ� �����ϸ� �Ž��� �ö󰣴�. 
		//cout << idx[i] << " " << ans << endl; �׽�Ʈ. 
		if (idx[i] == ans) {
			if (chk) {
				if (prev > arr[i]) {
					prev = arr[i];
					ans--;
					lcs.push_back(prev);
				}
			}
			else {   //�ʱⰪ ����  
				chk = true;
				prev = arr[i];
				ans--;
				lcs.push_back(prev);
			}
		}
	}
	for (int i = k - 1; i >= 0; i--)  //�Ųٷ� ������ ��ΰ� ����� lcs�� �ݴ�� ����Ͽ� ������ ��θ� ��´�. 

		cout << lcs[i] << " ";
}