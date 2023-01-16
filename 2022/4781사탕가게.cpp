#include<iostream>
#include<algorithm>
using namespace std;
int c[10001];
int p[10001];
int dp[10001];


int main() {
	int n,m;
	double tmp;
	while (1) {

		for (int i = 0; i < 10001; i++) {
			c[i] = 0;
			p[i] = 0;
			dp[i] = 0;
			
		}
		
		cin >>n>> tmp;
		if (n == 0 && tmp == 0.00)
			break;
		m = (int)(tmp * 100.0+0.5);
		
		for (int i = 0; i < n; i++) {

			cin >> c[i] >> tmp;
			p[i] = (int)(tmp * 100.0+0.5);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j - p[i] >= 0) {
					dp[j] = max(dp[j - p[i]] + c[i], dp[j]);


				}

			}
		}
		/*
		int ma = -1;
		for (int i = 0; i <= m; i++) {
			if (ma < dp[i])
				ma = dp[i];

		}
		*/
		cout << dp[m] << endl;
	}
	 
	
}