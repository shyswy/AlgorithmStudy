#include<iostream>
#include<math.h>
using namespace std;
int hp[30], happy[30];
int dp[30][101];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> hp[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> happy[i];
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 100; j > 0; j--) {

			if (hp[i] >= j) { //i째 사람과 인사할 때 필요한 체력이 남은 체력보다 크거나 같으면 인사 x
				dp[i][j] = dp[i - 1][j];
			}

			else { //남은 체력이 충분하다면 인사 하거나 인사 안하거나 중 선택
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - hp[i ]] + happy[i ]);
			}


		}
	}

	cout << dp[n][100];
}