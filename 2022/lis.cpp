#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[100001];
vector<int> dp;
vector<pair<int, int>> vec;
int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		int bb = vec[i].second;//i°�� ���� a������ ��ġ�� ����� ���� b�����뿡 ����� ��ġ.
		if (dp.size() == 0 || dp.back() < bb)
			dp.push_back(vec[i].second);
		else {
			int iter = lower_bound(dp.begin(), dp.end(), bb) - dp.begin();
			dp[iter] = bb;
		}

	}
	cout << n - dp.size();

}