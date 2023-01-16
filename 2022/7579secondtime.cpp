#include <iostream>
using namespace std;
int mem[101], cost[101];
int dp[101][10001]; //앱의 개수, 비용 총합( 가능한 모든 비용의 합)
const int max_c = 10000;// 100개 앱, 각 비용 100이 최대 따라서 100*100 이 최대 비용.
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> mem[i];

	for (int i = 1; i <= n; i++) cin >> cost[i];

	for (int i = 1; i <= n; i++) {//i째 앱에 대한 탐색
		for (int j = max_c; j  >=0; j--) {// 가능한 모든 cost.  주어진 cost로 얻을 수 있는 최대 여유 공간 찾기
			//0>> max_c 순서로 돌리면 틀린다!! 맨아래 주석 참고
			if (cost[i] > j) dp[i][j] = dp[i - 1][j];
			
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
			}


		}
	}
	
	for (int i = 0; i <= max_c; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}
}



/*
* 가 증가하는 순으로 루프를 돌리면 m[i] 가 여러번 더해지겠죠

예를들어 c[i]를 1이라고 하면

DP[2]를 계산할 때 DP[1]에서 값을 가져오면서 m[i]를 한 번 더하고

DP[3]을 계산할 때 DP[2]에서 값을 가져오면서 m[i]를 한 번 더하고

...

이런 식으로 m[i]가 반복적으로 더해지게 됩니다

j를 내림차순으로 돌리면 이런 문제가 없죠

그래서 보통 저런 식의 dp는 루프를 반대로 돌리거나

헷갈리면 그냥 2차원 배열 잡아서 순서대로 돌리기도 합니다



*/