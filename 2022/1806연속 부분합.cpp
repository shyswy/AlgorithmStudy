#include<iostream>
using namespace std;
long long int arr[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long int  s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 0, ed = 0,sum=0,ans=100001;
	//2������ �˰��� st�� �տ��� ���̰�, ed�� �ڿ��� �߰��Ͽ� ���Ӽ� ����
	while (st<=ed) {
		
		if (sum >= s) { //s �̻��ΰ� ã����, �տ��� ���� �����س����� ���̸� �ٿ�����!

			if (ans > (ed - st)) {
				ans = ed - st;
			}
			sum -= arr[st++];
		}
		else if (ed == n)break;      //��������
		else if( sum<s)   //���� sum �� S���� �۴ٸ�, �ڿ� 1�� �߰��ؼ� �κ��� �������Ѻ���.
			sum += arr[ed++];
		
		
		
	}
	if (ans == 100001)
		ans = 0;
	cout << ans;
	
	
}