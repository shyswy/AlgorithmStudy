#include<iostream>
using namespace std;

int arr[100001];
int dp[100001];
//�ð��ʰ�!
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans = 0;
	int g, p;
	cin >> g >> p;
	for (int i = 1; i <= g; i++)
		dp[i] = i;
	bool chk = true;
	for (int i = 1; i <= p; i++) {
		cin >> arr[i];
		int tmp = arr[i];
		for (int j = tmp; j <= g; j++) {
			if (dp[j] != 0) {//�ϳ��� ����ִٸ� ���� �� �ִ�. , ������ ���� ������ȣ�� g�� ���´ٰ� ����.
				
				dp[j]--;
			
			}
			else {
				chk = false;
				break;
			}
		}
		if (!chk)
			break;
		else
			ans++;
		
	}
	
	cout << ans;





	
	
}