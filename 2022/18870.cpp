#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long int> v;
long long int arr[1000001];
const long long int inf = 1000000001;

int main() {
	int n,tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[i] = tmp;
		v.push_back(tmp);
	}
	

	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) { //중복 제거
		if (v[i - 1] == v[i])
			v[i-1] = inf;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		auto idx = lower_bound(v.begin(), v.end(), arr[i])-v.begin();
		cout << idx << " ";
	}

}