#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[500001];
vector<int> dp;
vector<pair<int, int>> track;// 해당원소를 포함한 lis 길이, 해당원소
vector<pair<int, int>> vec;
bool visit[500001];
int main() {
	//lis 경로 찾기. 

	int n, a,b,len=0;//len은 실시간으로 변하는 lis 길이 저장
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
		int bb = vec[i].second;//i째로 작은 a전봇대 위치에 연결된 선이 b전봇대에 연결된 위치.
		if (dp.size() == 0 || dp.back() < bb) {
			dp.push_back(bb);
			track.push_back({ ++len, vec[i].first });//가장 큰수가 들어왔다> 여태까지의 LIS+ 지금 들어온 수 가 새로운 LIS. 
			//새로운 LIS는 기존 LIS 길이 (LEN) +1
			
		}
		else {
			int iter = lower_bound(dp.begin(), dp.end(), bb) - dp.begin();
			dp[iter] = bb;
			track.push_back({ iter+1 ,vec[i].first });
		}
	
	}

	cout << n-dp.size()<<endl;

	for (int i = track.size() - 1; i >= 0; i--) {//오른쪽부터 탐색시작
		if (track[i].first == len) {				// 전체 lis 를 찾은 뒤, 해당 원소를 시작으로 lis 경로 추적.
			//cout << track[i].second << endl;		//이전 위치 찾기: 길이가 원래 길이 -1이고 
													//현재 수보다 작은 수 가지고있는놈. >> 이 조건은 확인안해도 된다
			visit[track[i].second] = false;			//  1 2 3   4 9 8(lis) 를 보면    경로추적으로   1,2,3,4,8 찾을 것. 
													//해당 위치보다 이전에 입력된 원소들 중 길이가 작지만 더 큰 수 는 존재 x 
		}
		if (len == 0)
			break;
	}
	for (int i = 1; i <500001; i++) {
		if (visit[i]==true)
			cout << i << "\n";

	}
	
}