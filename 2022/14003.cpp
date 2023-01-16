#include <iostream>
#include <vector>
#include<algorithm>//lower bound
using namespace std;
//O(NlogN)
long long int ans;
int N;
vector<int> v;
long long int idx[9876543];  // 해당 위치의 값을 포함한 lcs 길이를 저장한다. 
vector<long long int> lcs;
long long int arr[9876543];
int main() {
	long long int prev;
	cin >> N;

	v.push_back(-1000000001);   //무조건 초기화 될 수 있는 가장 작은 값. 

	for (int i = 0; i < N; i++) {
		//int x;
		cin >> arr[i];
		if (arr[i] > v.back()) {//입력 값이 현재 벡터 내의 모든 값보다 클시 추가하고 ans++;
			v.push_back(arr[i]);
			ans++;
			idx[i] = ans;   // 최장 수열 길이 변화시 마다 저장. 
			//prev = arr[i];

		}
		else {
			int it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();//upperbound 는 x를 "초과" 하는 수가 처음나오는 위치 반환
			//  -v.begin() 을 통해  '위치 값' 에서  상대적인 위치 값인 인덱스 값으로 변환. 
			v[it] = arr[i];  //lower bound는 x "이상" 의 수가 처음 나오는 위치 반환.
			idx[i] = it;
			// lower, upper bound 를 사용해 이진탐색을 굳이 구현하지 않아도 된다!.
			
		}
	}
	cout << ans << endl;

	bool chk = false;
	int k = 0;
	for (int i = N - 1; i >= 0; i--) { //경로 추적. 도착지 > 출발지로 lcs 경로를 추적하며 거슬러 올라간다. 
		//cout << idx[i] << " " << ans << endl; 테스트. 
		if (idx[i] == ans) {
			if (chk) {
				if (prev > arr[i]) {
					prev = arr[i];
					ans--;
					lcs.push_back(prev);
				}
			}
			else {   //초기값 설정  
				chk = true;
				prev = arr[i];
				ans--;
				lcs.push_back(prev);
			}
		}
	}
	for (int i = k - 1; i >= 0; i--)  //거꾸로 추적한 경로가 저장된 lcs를 반대로 출력하여 정방향 경로를 얻는다. 

		cout << lcs[i] << " ";
}