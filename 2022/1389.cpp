#include<iostream>
#include<vector>
using namespace std;
int  arr[1000][1000];
const int inf = 98765432;
int main() {
	
	int n, m, f, t;
	int sum, ans = inf, p;
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (i == j)arr[i][j] = 0;
			else
				arr[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> f >> t;
		arr[f][t] = 1;
		arr[t][f] = 1;
		
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > (arr[i][k] + arr[k][j]))
					arr[i][j] = (arr[i][k] + arr[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += arr[i][j];
		}
		
		if (ans > sum) {
			ans = sum;
			p = i;
		}
	
	}
	cout << p << endl;

	
}